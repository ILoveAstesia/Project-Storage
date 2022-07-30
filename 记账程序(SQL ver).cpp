#include<iostream>
#include<sstream>
#include "mysql.h"
#include<string.h>
#include <windows.h>

using namespace std;

const char dbusername[10] = "root";
const char dbpassword[10] = "Astesia";
const char dbname[12] = "new_schema";
//刷新前置 //移动光标 ! unused !
void gotoxy() {
    COORD pos = {0,0}; 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hOut, pos); 
    }    

void gotoxy(int x, int y) {
    COORD pos = {x,y}; 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hOut, pos); 
    }

void refresh_whole(){
    for(int i=1;i<=1;i++) {
		gotoxy(0,0);	
        					//将光标移动至控制台左上角
		for(int k=1;k<=10;k++) {

			for(int j=1;j<=i;j++)
            {cout<<" ";}
            
			cout<<"Hello, world"<<endl;
		}

		Sleep(100);
	}


}

void refresh_part(){

    for(int i=1;i<=10;i++) {
		for(int k=1;k<=10;k++) {
			gotoxy(i-1,k-1);				//将光标移至第k行，第i列

			cout<<"Hello, world";
            Sleep(100);

			if(i>1) {						//i大于1时做，不然坐标会变成负数
				gotoxy(i-2,k-1);			//将光标移至前一个字符
				cout<<' ';					//清除那个字符
			}
		}
		Sleep(100);
	}

}

//unsuccessed
string transform_string_To_char(){
    string uri="astesia",name="ila",sex="boy";
    string st = "insert into DBTable(URI,Name,Sex)values(" + uri + "," + name +"," + sex + ")";
    
    const char* k = NULL;

    k = st.c_str();	//让指针指向s1的位置
    
    char a[1024];
    
    return k;
}

class DB{

public:
    MYSQL mysql;
	///< 初始化句柄

    DB(){
        mysql_init(&mysql);
        //设置中文输入
        mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

        ///<    连接的数据库 （句柄、主机名、用户名、密码、数据库名、端口号、socket指针、标记）
        if (!mysql_real_connect(&mysql, "localhost", dbusername, dbpassword, dbname, 3306, nullptr, 0))
        {
            cout << "数据库连接失败" << mysql_errno(&mysql) << endl;
        }
        cout << "数据库连接成功" << endl << endl;
    }

    ///< 创建数据库回应结构体
    MYSQL_RES* res = nullptr;
    ///< 创建存放结果的结构体
    MYSQL_ROW row;
    char sql[1024]{ 0 };
    
        //查询
    void select(){
        ///< 调用查询接口
        sprintf_s(sql, 1024, "select * from new_table");
    
	    if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
	    }
	    else
	    {
		    cout << "查询成功" << endl << endl;

		    ///< 装载结果集
		    res = mysql_store_result(&mysql);

		    if (nullptr == res)
		    {
			    cout << "装载数据失败" << ": " << mysql_errno(&mysql)  << endl;
		    }
		    else
		    {
			    ///< 取出结果集中内容
			    while (row = mysql_fetch_row(res))
			    {
                    //可以优化
				    cout << row[0] << "  "  << row[1] << "  " << row[2] << endl;
			    }
		    }
	    }
    }

    //添加
    //静态 
    void add(){
        sprintf_s(sql, 1024, "insert into new_table values('7/10', '0','测试add')");
        //执行语句
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }
    //动态 char key[32],float val,char text[128]
    void add(string key,string val,string text){
        string st = "insert into new_table values(\'"  + key + "\',\'" + val + "\',\'" + text + "\')";
        char a[1024];
        strcpy_s(a, st.c_str());
        sprintf_s(sql, 1024, a);
        cout << sql;
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

        //删除
    void remove(){
        sprintf_s(sql, 1024, "DELETE FROM new_table WHERE idnew_table = '7/10'");
        //执行语句
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
	    }
    }

        //更新
    void update(){
        
        sprintf_s(sql, 1024, "UPDATE new_table SET new_tablecol = 10 WHERE idnew_table = '7/10'");
        //执行语句
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
	    }
    
    }
        //自定义
    void custom(){
        //最多只能使用1023
        char a[1024] = "";
        cin.clear();
        cin.ignore();
        cout << "请输入语句\n:";
        //scanf_s("%s", &a, unsigned(sizeof(a))) == 0
        //select * from new_table
        if (cin.getline(a, sizeof(a) - 1, '\n'))
        {
            //cout << a <<"\n";
            sprintf_s(sql, 1024, a);
            if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
            {
                cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
            }
            else
            {
                cout << "查询成功" << endl << endl;

                display();
            }
        }
        else
        {
            cout << "error input:out flow (1024)\n";
        }

        

        
    }

    void display() {
        ///< 装载结果集
        res = mysql_store_result(&mysql);

        if (nullptr == res)
        {
            cout << "装载数据失败" << ": " << mysql_errno(&mysql) << endl;
        }
        else
        {
            ///< 取出结果集中内容
            while (row = mysql_fetch_row(res))
            {
                //可以优化
                cout << row[0] << "  " << row[1] << "  " << row[2] << endl;
            }
        }
    }

    void menu(){
        int i=0;
        int flag=0;
        
        cout << "\t" << "0 s" << "\n" << "\t" << "1 a" << "\n" << "\t" << "2 r" << "\n" << "\t" << "3 u" << "\n" << "\t" << "4 c" << "\n";
        scanf_s("%d", &i);
        switch (i)
        {
        case 0 :
            select();            
            break;

        case 1 :
            add();            
            break;

        case 2 :
            remove();            
            break;

        case 3 :
            update();            
            break;

        case 4:
            custom();            
            break;

        default:
        //防止锁死
            flag++;
            if(flag==3)
            system("pause");
            
            break;

        case -1: 	
        ///< 释放结果集
	    mysql_free_result(res);

	    ///< 关闭数据库连接
	    mysql_close(&mysql);
        return;
        //break;
        }
        system("pause");
        system("cls");
        menu();
        
    }

};

int main()
{
    DB b;
    //b.menu();
    b.add("7/3","32","测试动态''");//用两个单引号可以表示一个单引号数据
   
   //c++ ? sql foramt
    /*
    string uri="astesia",name="ila",sex="boy";
    string st = "insert into DBTable(URI,Name,Sex)values(" + uri + "," + name +"," + sex + ")";
    
    const char* k = NULL;

    k = st.c_str();	//让指针指向s1的位置
    
    //cout << k;
    printf(k);
   */
	

    cout<<"进程已结束,";
    system("pause");
    //结束
    return 0;
}