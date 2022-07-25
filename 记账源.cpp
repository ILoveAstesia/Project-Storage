//头文件
#include<iostream>
#include<sstream>
#include<string>
#include "mysql.h"

using namespace std;
//{}[]()., :; +-*/ % &| ^ != <> ? @#\

const char dbusername[10] = "root";
const char dbpassword[10] = "Astesia";
const char dbname[12] = "new_schema";
//String 转换为 char[*]
void transformation(){

}

//声明
//class Bill;
//struct linkT;
//linkT* initiallink(int);
//void display(linkT*);
//void men();


//以下为基于数组的方法

struct bill
{
    int times = 0;
    float num = .0;
    string detail = "空";
};

//基于数组的记录方式类
class arr_Based {
public:
    int i = 0, n = 0, C = 31, y = 0;
    //简单的创建数组，保持满大小，通过逻辑判断检查用户年月错误，如果有时间可以在这里直接更改毕竟是c
    bill arr[12][31];
    //默认2022
    arr_Based() {
        y = 2022;
        main();
    }
    //输入i为年份
    arr_Based(int i) {
        y = i;
        main();

    }

    void main() {
        //初始化日期
        /*      for ( n = 0; n < 12; n++)
        {
                arr[n][0].month = n + 1;
        }*/
        //for (i = 0; i < C; i++) {
        //    arr[n][i].day = i + 1;
        //}
    }

    //

    //增加
    // 
    //手动输入的日期，将来可以试试读取日期
    //扩展至可叠加，可多次引用方法，金额叠加，细节叠加。
    void add_arr(int m, int d, float num, string t)
    {
        m--, d--;
        //ing 第一次添加信息清空初始值“空”，第二次添加信息叠加原来信息。……或者直接更改结构体初始值空为其他
        if (arr[m][d].times++ == 0/*arr[m][d].detail == "空"*/) {
            arr[m][d].detail = "";
        }
        //更新日期
        //arr[m][d].month = m+1;
        //arr[m][d].day = d+1;

        arr[m][d].times++;//当天添加信息的次数

        arr[m][d].num += num;
        arr[m][d].detail += t;

        cout << "\n\t" << "一个" << m + 1 << "月" << d + 1 << "日的记录添加完成。\n";

        cout << "\n\t" << y << "年" << m + 1 << "月" << d + 1 << "日" << "\n";
        cout << "\t" << "消费" << arr[m][d].num << "元/￥" << "\n";
        cout << "\t" << "细节:" << arr[m][d].detail << "。" << "\n";       
        cout << "\n";

    }

    //删除

    void delete_arr(int m, int d)
    {
        m--, d--;
        //初始化
        arr[m][d].times = 0;
        arr[m][d].num = .0;
        arr[m][d].detail = "空";
    }
    //删除某天后的L天
    void delete_arr(int m, int d, int l)
    {
        m--, d--;
        //初始化
        for (i = 0; i < l; i++)
        {
            arr[m][d + i].times = 0;
            arr[m][d + i].num = .0;
            arr[m][d + i].detail = "空";
        }

    }
    //删除所有
    void delete_arr(int a)
    {
        if (a == 1)
        {
            cout << "删除所有值中……(n)" << "\n";
        }

    };

    //查询

    void inspect_arr()
    {
        C = 5;
        //cout << "\n\n\n";
        //读取数组(完全)
        for (i = 0; i < C; i++)
        {
            cout << "\n\t" << y << "年" << n << "月" << i << "日" << "\n";


            cout << "\t" << "消费" << arr[n][i].num << "元/￥" << "\n";
            cout << "\t" << "细节:" << arr[n][i].detail << "。" << "\n";
            cout << "\n";

        }
        cout << "结束" << "\n";
    }
    //检查某天的记录
    void inspect_arr(int m, int d)
    {

        cout << "\n\t" << "正在检查：" << y << "年" << m << "月" << d << "日" << "的记录……" << "\n\n";

        cout << "\n\t" << y << "年" << m << "月" << d << "日" << "\n";
        m--, d--;
        cout << "\t" << "消费" << arr[m][d].num << "元/￥" << "\n";
        cout << "\t" << "细节:" << arr[m][d].detail << "。" << "\n";
        cout << "\n";


    }
    //检查从某天开始的L条记录
    void inspect_arr(int m, int d, int l)
    {

        cout << "\n\t" << "正在检查：" << y << "年" << m << "月" << d << "日起的" << l << "个" << "记录……" << "\n\n";

        m--, d--;
        for (i = 0; i < l; i++)
        {
            cout << "\n\t" << y << "年" << m + 1 << "月" << d + 1 + i << "日" << "\n";
            cout << "\t" << "消费" << arr[m][d + i].num << "元/￥" << "\n";
            cout << "\t" << "细节:" << arr[m][d + i].detail << "。" << "\n";
            cout << "\n";
        }

    }
    //查询两者日期之间的记录
    void inspect_arr_between(int m, int star, int end)
    {


    }

    //更改

    //改变某一条记录 m，d坐标，s信息
    //添加信息
    void change_add(int m, int d, int n, string s) {
        cout << "\n\t" << "正在修改：" << y << "年" << m << "月" << d << "日" << "的记录……" << "\n\n";
        m--, d--;
        arr[m][d].times++;
        arr[m][d].detail += s;
        arr[m][d].num += n;
        cout << "\t" << "已修改次数：" << arr[m][d].times << "次" << "\n";
        cout << "\t" << "消费：" << arr[m][d].num << "元/￥" << "\n";
        cout << "\t" << "细节:" << arr[m][d].detail << "。" << "\n";
        cout << "\n";
    }

    void change(int m, int d, int n) {
        //可以传入原来字符串，传入s1，然后赋值给s2，输出s2，修改s2，用s2覆盖原来s1
    }

    //cui 文字菜单用户界面
    void menu() {
        cout << "菜单开始……" << "\n";

        //string s="0";
        //可尝试枚举 只能数字太悲催了
        //读取文件？
        int s = 0, m = 1, d = 1;
        float n = 0.0;
        string i = " ";
        // getchar();
        cout << "1 增加" << "\n";
        cout << "2 查询" << "\n";
        cout << "3 修改(n)" << "\n";
        cout << "4 删除(n)" << "\n";
        cout << "0 退出" << "\n";


        scanf_s("%d", &s);
        switch (s)
        {

        case 0: cout << "退出中." << "\n";
            return;

        case 1: cout << "增加" << "\n";

            cout << "(空格隔开)输入参数 m d:";
            scanf_s("%d %d", &m, &d);

            cout << "(空格隔开)输入参数 n:";
            scanf_s("%f", &n);

            cout << "(回车输入)输入参数 i:";
            cin >> i;
            // getline(cin,i);

            cout << "\n";
            add_arr(m, d, n, i);
            break;

        case 2: cout << "查询" << "\n";

            cout << "(空格隔开)输入参数 m d:";
            scanf_s("%d %d", &m, &d);

            cout << "\n";
            inspect_arr(m, d);
            break;

        case 3: cout << "修改" << "\n";

            cout << "(空格隔开)输入参数 m d:";
            scanf_s("%d %d", &m, &d);

            cout << "(空格隔开)输入参数 n (表示要添加的金额可为负值):";
            scanf_s("%f", &n);

            cout << "(回车输入)输入参数 i （表示要在细节后加入的信息）:";
            cin >> i;
            change_add(m, d, n, i);
            break;

        case 4: cout << "删除" << "\n";

            cout << "(空格隔开)输入参数 m d:";
            scanf_s("%d %d", &m, &d);

            delete_arr(m, d);
            break;
        
        default:
            cout << "未知操作符…… 返回中" << "\n";
            break;
        }

        cout << "菜单结束……" << "\n";
        menu();
    }

};

class DB{

    public:
        MYSQL mysql;
	    //MYSQL *mysql = mysql_init(nullptr);
	    ///< 初始化句柄
        DB(){
            mysql_init(&mysql);
            //设置中文输入
            mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

            ///< 连接的数据库       （句柄、    主机名、    用户名、密码、  数据库名、     端口号、socket指针、标记）
            if (!mysql_real_connect(&mysql, "localhost", dbusername, dbpassword, dbname, 3306, nullptr, 0))
            {
                cout << "数据库连接失败" << mysql_errno(&mysql) << endl;
                // return -1;
            }
            cout << "数据库连接成功" << endl << endl;
        }
        ///< 创建数据库回应结构体
        MYSQL_RES* res = nullptr;
        ///< 创建存放结果的结构体
        MYSQL_ROW row;
        char sql[1024]{ 0 };
    

    void select(){
    ///< 调用查询接口
    //查询
    sprintf_s(sql, 1024, "select * from new_table");

    //添加
    //sprintf_s(sql, 1024, "insert into new_table values('7/18', '0','测试gbk')");
    //执行语句
    // mysql_real_query(&mysql, sql, (unsigned int)strlen(sql));
    
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
				cout << row[0] << "  "  << row[1] << "  " << row[2] << endl;
			}
		}
	}

	///< 释放结果集
	mysql_free_result(res);

	///< 关闭数据库连接
	mysql_close(&mysql);

	system("pause");
    }

    void menu(){
        int i=0;
        switch (i)
        {
        case 0 :
            select();
            break;
        
        default:
            break;
        }
    }

};

void database(){

    //需要准备的如下
    //自定义的名称 让句子和命令分开
    //符合本程序的输出标准， 或者单独创建一个display
    //实现增删改查
    //自定义语句


    cout<<"修改中"<<"\n";
    ///< 创建数据库句柄
	MYSQL mysql;
	//MYSQL *mysql = mysql_init(nullptr);
	///< 初始化句柄
	mysql_init(&mysql);
    //设置中文输入
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	///< 连接的数据库       （句柄、    主机名、    用户名、密码、  数据库名、     端口号、socket指针、标记）
	if (!mysql_real_connect(&mysql, "localhost", dbusername, dbpassword, dbname, 3306, nullptr, 0))
	{
		cout << "数据库连接失败" << mysql_errno(&mysql) << endl;
		// return -1;
	}

	cout << "数据库连接成功" << endl << endl;

	///< 创建数据库回应结构体
	MYSQL_RES *res = nullptr;
	///< 创建存放结果的结构体
	MYSQL_ROW row;

	char sql[1024]{ 0 }/*,table_name[16]="test_table"*/;

    //测试自定义语句
    // char strSQL[128];
    // strSQL <<"select * from " << table_name << "";
	// sprintf_s(sql, 1024, "select * from test_table");
    stringstream ss;
    /*ss << "insert `t_image` (`name`,`path`,`size`)values('image";
    ss << i << ".jpg','d:/img/', 10240)";
    sqls = ss.str();*/

	///< 调用查询接口
    //查询
     sprintf_s(sql, 1024, "select * from new_table");

    //添加
    //sprintf_s(sql, 1024, "insert into new_table values('7/18', '0','测试gbk')");
    //执行语句
    // mysql_real_query(&mysql, sql, (unsigned int)strlen(sql));
    
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
				cout << row[0] << "  "  << row[1] << "  " << row[2] << endl;
			}
		}
	}

	///< 释放结果集
	mysql_free_result(res);

	///< 关闭数据库连接
	mysql_close(&mysql);

	system("pause");

	// return 0;
}

int main()
{
    DB b;
    b.menu();
   
    //结束
    return 0;
}

//int main(){
// prepare();
       // database();
   //linkT* headp=initiallink(5);
   //display(headp);
   //基于日期的账单。//将来可以试试基于事件的账单
       //arr_Based a(2002);//创建一个2002年的账单
   //a.main();
   //检查全部
   //a.inspect_arr();
       //cout << "添加……";
   // 增
   // 添加一个二号的订单
       //a.add_arr(6, 4, 32.5, "正新鸡排，酥肉，鸡排，薯条");
   /*
       a.add_arr(6, 7, 5, "薯条");

       // 重新检查
       //a.inspect_arr(6, 4);
       // 查

       cout << "截至检查……";
       // 截至检查
       a.inspect_arr(6, 1,7);

       // 改
       cout << "修改……";
       // 修改
       a.change_add(6, 7, 7,"汉堡");
       cout << "修改后检查……";
       // 修改后检查
       a.inspect_arr(6, 4);
       a.inspect_arr(6, 7);

       //删
       a.delete_arr(6, 4);
       cout << "删修改后检查……";
       // 修改后检查
       a.inspect_arr(6, 4);
       a.inspect_arr(6, 7);
   */
   // 返回菜单 reqquired
       //a.menu();

   //int n;
   //scanf_s("%d", &n);

   //return之后没用了!!!!!
   // cout << "请按下任意按键以结束更改测试…… :";
   // getchar();
  //  }



//
//  面向对象，运行较慢，编写较易，扩展性较高，
//  面向过程，运行较快，编写较难，扩展性较差。
// 
//  我的想法是，先编写面向对象，然后移植成为面向过程。
// 
//  需求功能，账单的增删改查，账单内部的增删改查，总数，平均数，中位数，比例（bill类要添加新的成员），比例分析，
//
//  算法分析，可以先用数组实验一下。最小可运行项目。
//
//  创建管理员对象，管理员对象调用菜单函数，菜单函数包括增删改查，(或者叫用户)
//  增加，参数为头节点，头节点调用添加函数，添加节点 。
//  新建浮游节点，给浮游节点赋值，让头节点next储存浮游节点的地址，浮游节点指向null；
// 
//  删除，参数为头节点，头节点调用删除方法，删除节点。
// 
//  更改，
// 
//  查询，完全查询，部分查询，遍历。
//
//  之后使用文件管理系统储存
//  最后使用database 
//


/*
//创建账单类
class Bill
{
public:
    int moneyNum;
    int date;
    string detail;
    static int sum;
    //int iomoney;
    Bill()
    {
        moneyNum = 0, date = 0, detail = "Null";
        cout << "默认构造函数调用成功";
    }
    Bill(int num, int date, string temp)
    {
        this->moneyNum = num;
        this->date = date;
        detail = temp;
        cout << "带参构造函数调用成功";
    }

private:


};

//默认初始化总数为0；
int Bill::sum = 0;

//创建链表构造体
struct linkT
{
    //计数&调试空余
    int num;
    //数据域
    Bill elemB;
    //指针域
    struct linkT* Nextp;
};

//定义一个初始化函数
//初始化函数，创建含头节点的链表
linkT* initiallink(int i) {
    //linkT* p = null;

    linkT* headp = (linkT*)malloc(sizeof(linkT));    //初始化创建头指针
    headp->num = i;          //头节点储存长度
    linkT* temp = headp;    //临时指针指与头指针处于同一位置
    int n;  //循环计数器
    for (n = 0; n < i; n++)
    {   //[head]->[newS]
        linkT* newS = (linkT*)malloc(sizeof(linkT)); //新建游离节点
        newS->num = n + 1;  //临时链节赋值初始化 ，有待迭代
        newS->Nextp = NULL; //初始化Section,默认赋值NULL
        temp->Nextp = newS; //链接至主链
        temp = temp->Nextp; //
    }
    return headp;
}

//显示函数
void display(linkT* headp)
{
    linkT* temp = headp->Nextp;//指向第一个数据节文件
    //[H] [1] [2] ... [i]
    int n;//计数器
    for (n = 0; ; n++)
    {
        if (temp->Nextp != NULL)
        {
            cout << temp->num << "\n";
            temp = temp->Nextp;

        }
        else if (temp->Nextp == NULL)
        {
            break;
        }
    }



}

//定义菜单函数
void men()
{
    cout << "调用菜单成功";
    return;
}
*/