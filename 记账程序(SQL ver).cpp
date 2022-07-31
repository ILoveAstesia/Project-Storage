#include <iostream>
#include <sstream>
#include <string.h>

#include <windows.h>

#include "mysql.h"

//待做
//st 可以拆分成 insert into new_table  和  values(。。。)俩个部分 可以给自定义用 然后用选择框的模式来调整 format【insert。。。】 + format【value/where】 之类的
//添加动态方法进入cui
//添加动态表名
//语句反馈使用cout可能有问题，需要检查

using namespace std;

const char dbusername[16] = "root";
const char dbpassword[16] = "Astesia";
const char dbname[16] = "new_schema";
//const char table_name[16]=""; 

string temp[16]={""};

//刷新前置 //移动光标 ! unused !
/*
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

//unsuccessed strcpy_s(a, st.c_str());直接转换了

string transform_string_To_char(){
    string uri="astesia",name="ila",sex="boy";
    string st = "insert into DBTable(URI,Name,Sex)values(" + uri + "," + name +"," + sex + ")";
    
    const char* k = NULL;

    k = st.c_str();	//让指针指向s1的位置
    
    //char a[1024]; strcpy_s(a, st.c_str());直接转换了
    
    return k;
}
*/

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
    
    //固定表格的动态 char key[32],float val,char text[128]
    void add(string key,string val,string text){
        
        string st = "insert into new_table values(\'"  + key + "\',\'" + val + "\',\'" + text + "\')";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //反馈
        cout << sql;
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

        //删除
        //静态
    void remove(){
        sprintf_s(sql, 1024, "DELETE FROM new_table WHERE idnew_table = '7/10'");
        //执行语句
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
	    }
    }

        //固定表格的动态
    void remove(string key){
            
        string st = "DELETE FROM new_table WHERE idnew_table = \'"+key+"\'";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //反馈
        cout << sql;
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

        //更新
        //静态
    void update(){
        
        sprintf_s(sql, 1024, "UPDATE new_table SET new_tablecol = 10 WHERE idnew_table = '7/10'");
        //执行语句
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
	    }
    
    }
        
        //固定表格的动态
    void update(string key,string val,string text){
        
        string st = "UPDATE new_table SET new_tablecol="+val+",new_tablecol1=\'"+text+"\' WHERE idnew_table =\'"+key+"\'";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //反馈
        cout << sql;
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

        //自定义
    void custom(){
        //最多只能使用1023
        char a[1024] = "";
        cin.clear();
        cin.ignore();
        cout << "请输入语句\n:";
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
        
        //显示结果集
    void display() {
        ///< 装载结果集
        res = mysql_store_result(&mysql);

        if (nullptr == res)
        {
            cout << "装载数据失败,or have no result(s)" << ": " << mysql_errno(&mysql) << endl;
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

        //输入方法 报文字段 报文位数
    void get(int n){
        cout << "输入参数\n:";
        char a[32] = "";

        cin.clear();
        //会忽视第一个字符，禁用后不知道会不会出错。
        //cin.ignore();
        
        int i = 0 ;
        for (i = 0; i < n; i++) {
            cout << "请输入参数 "<< i << "\n:";
            cin.getline(a, sizeof(a) - 1, '\n');
            //全局变量
            temp[i] = a;
        }

    }
        
        //cui
    void menu(){
        //选择falg
        int i=0;
        //防止锁死flag
        int flag=0;
        //提示
        cout    << "\t" << "0 s" << "\n" 
                << "\t" << "1 a" << "\n" 
                << "\t" << "2 r" << "\n" 
                << "\t" << "3 u" << "\n" 
                << "\t" << "4 c" << "\n";

        scanf_s("%d", &i);

        //选择
            //int num[16]={0}, int n = 0;
        switch (i)
        {

        case -1: 	
            ///< 释放结果集
	        mysql_free_result(res);

	        ///< 关闭数据库连接
	        mysql_close(&mysql);
        return;
        //break;

        //静态冗余
        case 0:
            int n;
            cout    << "\t" << "0 s" << "\n" 
                    << "\t" << "1 a" << "\n" 
                    << "\t" << "2 r" << "\n" 
                    << "\t" << "3 u" << "\n" 
                    << "\t" << "4 c" << "\n";     
            scanf_s("%d", &n);
            switch (n)
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
                break;
                }
        break;

        case 1:
            select();
        break;
        /*
        case 2:
            n=3;
            num[0]='1';
            num[1]='1';
            num[2]='1';
            get(num,n);
            add( key, val, text);
        break;
            n=1;
            num[0]='1';
            num[1]='0';
            num[2]='0';
            get(num,n);
            remove(key);
        case 3:
            n=3;
            num[0]='1';
            num[1]='1';
            num[2]='1';
            get(num,n);
            update(key, val, text);
        break;
        case 4:
            custom();
        break;
        case 5:
            cout<<"后面就没了\n";
        break;
        */
        //防止锁死
        default:
            flag++;
            if(flag==3)
            system("pause");
        break;

        
        }
        system("pause");
        system("cls");
        menu();
        
    }
    
        //gui
    void gui(){}
};

int main()
{
    DB b;
    //b.menu();
    //("7/11","10","测试update的为动态") , ("7/3","32","测试动态''")
    //b.select();

    //测试读取函数
    int n = 3;
    b.get(n);
    //尝试让get运算后返回一个集合，例如数组。之后使用数组中的元素充当参数
    //尝试让get的返回值赋值给a
    //strcpy_s(a,b.);
    cout << temp[0]<<"\n";
    cout << temp[1]<<"\n";
    cout << temp[2]<<"\n";
	
    cout<<"进程已结束,";
    system("pause");
    //结束
    return 0;
}