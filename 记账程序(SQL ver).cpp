#include<iostream>
#include<sstream>
#include "mysql.h"

using namespace std;

const char dbusername[10] = "root";
const char dbpassword[10] = "Astesia";
const char dbname[12] = "new_schema";

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
    void add(){
        sprintf_s(sql, 1024, "insert into new_table values('7/10', '0','测试add')");
        //执行语句
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
        cout << "\t" << "0 s" << "\n" << "\t" << "1 a" << "\n" << "\t" << "2 r" << "\n" << "\t" << "3 u" << "\n" << "\t" << "4 c" << "\n";
        scanf_s("%d", &i);
        switch (i)
        {
        case -1: 	
        ///< 释放结果集
	    mysql_free_result(res);

	    ///< 关闭数据库连接
	    mysql_close(&mysql);
        return;
        break;

        case 0 :
            select();
            menu();
            break;
        case 1 :
            add();
            menu();
            break;
        case 2 :
            remove();
            menu();
            break;
        case 3 :
            update();
            menu();
            break;
        case 4:
            custom();
            menu();
            break;
        default:
            break;
        }
    }

};

int main()
{
    DB b;
    b.menu();

    //结束
    return 0;
}