//基础前置
#include <iostream>
//文件？
//#include <sstream>
//字符串前置
#include <string.h>
//窗口、sleep、pause前置
#include <windows.h>
//数据库前置
#include "mysql.h"

//vs    ctrl m + l,m + o(pen)
//code  ctrl k + 0

//待做
//测试非admin 方法时 get 的使用（menu使用）
//get方法到底怎么用，这个ignore怎么回事。分离了ignore和get的cin.getline();方法

//st 可以拆分成 insert into new_table  和  values(。。。)俩个部分 可以给自定义用 然后用选择框的模式来调整 format【insert。。。】 + format【value/where】 之类的
//添加动态方法进入cui √
//添加动态表名 ing 发现问题，update语句需要知道表名，并且需要知道列数
//语句反馈使用cout可能有问题，需要检查
//switch输入\/会出现问题

//测试

using namespace std;

const char dbusername[16] = "root";
const char dbpassword[16] = "Astesia";
const char dbname[16] = "new_schema";
//const char table_name[16]=""; 

//全局暂存变量
string temp[16]={""};
//char temp_title[16][16] = { "" };

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

//假的进度条
void processbar()
{
    for (int i = 1; i <= 25; i++)cout << "-"; cout << "\n";


    for (int i = 1; i <= 10; i++)
    {
        gotoxy(0, 2);						//将光标移动至控制台左上角

        for (int j = 1; j <= i; j++)cout << " ";
        cout << "\\" << endl;

        Sleep(i * 30);
        if (0) {}

    }
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
            system("pause");
            exit(0);
            
        }
        else{
        cout << "数据库连接成功" << endl << endl;
        Sleep(250);
        system("cls");
        }
    }

    ///< 创建数据库回应结构体
    MYSQL_RES* res = nullptr;
    MYSQL_RES* rest = nullptr;
    ///< 创建存放结果的结构体
    MYSQL_ROW row;
    //   创建存放表头的结构体
    MYSQL_ROW title;
    char sql[1024]{ 0 };
    
    

    void title_get(string key){
        //SELECT COLUMN_NAME  FROM information_schema.columns WHERE table_name=\'"+ key +"\'
        string st = "SELECT COLUMN_NAME  FROM information_schema.columns WHERE table_name=\'"+ key +"\'";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
            cout <<"输入的指令是:"<<sql<<"\n";
	    }
	    else
	    {
		    //cout << "查询成功" << endl << endl;
            //cout <<"输入的指令是:"<<sql<<"\n";
		    ///< 装载结果集
		    rest = mysql_store_result(&mysql);

		    if (nullptr == rest)
		    {
			    cout << "装载数据失败" << ": " << mysql_errno(&mysql)  << endl;
		    }
		    else
		    {
			    ///< 取出结果集中内容
                //int n=0;
			    while (title = mysql_fetch_row(rest))
			    {
                    //temp[n]= title[0];n++;
                    cout << title[0]<<"\t";
			    }
		    }
            ///< 释放结果集
	        //mysql_free_result(rest);
            cout << endl;
	    }
    }

    void title_back(string key){
        //SELECT COLUMN_NAME  FROM information_schema.columns WHERE table_name=\'"+ key +"\'
        string st = "SELECT COLUMN_NAME  FROM information_schema.columns WHERE table_name=\'"+ key +"\'";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
            cout <<"输入的指令是:"<<sql<<"\n";
	    }
	    else
	    {
		    ///< 装载结果集
		    rest = mysql_store_result(&mysql);

		    if (nullptr == rest)
		    {
			    cout << "装载数据失败" << ": " << mysql_errno(&mysql)  << endl;
		    }
		    else
		    {
			    ///< 取出结果集中内容
                int i=0;
			    while (title = mysql_fetch_row(rest))
			    {
                    cout << title[0]<<"\t";
                    temp[i]=title[0];
                    i++;
			    }
		    }
            cout << endl;
	    }
    }
    
    //输入方法 报文字段 报文位数
    void get(int n){
        //会忽视第一个字符，禁用后不知道会不会出错。
        //奇怪的规律，在main调用b。get（n）时开启ignore会跳过第一个
        //在db类中，成员方法调用时关闭ignore会跳过第一个。
        //这可能是现象不是本质，本质应该是判断之前有没有输入的数据残余。
        cin.clear();
        cin.ignore(0);
        get_n(n);

    }

    void get_n(int n){
        cout << "输入参数\n:";
        char a[32] = "";

        
        int i = 0 ;
        for (i = 0; i < n; i++) {
            cout << "请输入参数 "<< i << "\n:";
            cin.getline(a, sizeof(a) - 1, '\n');
            //全局变量
            temp[i] = a;
        }
    }
        
void admin(){
        //update_dynamic("sc", "8/3", "6.0000", "小七 6.0000");
        //select("sc");
        //remove_dynamic("sc", "7/31");
        select("sc");
}
    
    //查询
    void select(){
        ///< 调用查询接口
        sprintf_s(sql, 1024, "select * from new_table");
    
	    if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
            cout <<"输入的指令是:"<<sql<<"\n";
	    }
	    else
	    {
		    cout << "查询成功" << endl << endl;
            cout <<"输入的指令是:"<<sql<<"\n";
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

    void select(string key){
        ///< 调用查询接口
        //SHOW COLUMNS FROM "+ key +"
        //select * from "+ key +"
        //SELECT COLUMN_NAME  FROM information_schema.columns WHERE table_name=\'"+ key +"\'
        string st = "select * from " + key + "";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);


	    if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	    {
		    cout << "查询失败" << ": "  << mysql_errno(&mysql) << endl;
	    }
	    else
	    {
		    cout << "查询成功" << endl << endl;
            cout <<"输入的指令是:"<<sql<<"\n";
		    ///< 装载结果集
		    res = mysql_store_result(&mysql);

		    if (nullptr == res)
		    {
			    cout << "装载数据失败" << ": " << mysql_errno(&mysql)  << endl;
		    }
		    else
		    {
                //表头
                title_get(key);
                //cout<<temp[0]<< "\t"  << temp[1] << "\t" << temp[2] << endl;
			    ///< 取出结果集中内容
			    while (row = mysql_fetch_row(res))
			    {

                    //可以优化
				    cout << row[0] << "\t"  << row[1] << "\t" << row[2] << endl;
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
        cout <<"\n输入的指令是:"<<sql<<"\n";
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

    //真动态
    void add_dynamic(string d,string key,string val,string text){
        
        string st = "insert into "+ d +" values(\'"  + key + "\',\'" + val + "\',\'" + text + "\')";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //反馈
        cout <<"\n输入的指令是:"<<sql<<"\n";
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
        cout <<"\n输入的指令是:"<<sql<<"\n";
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

    void remove_dynamic(string d,string key) {
        title_back(d);
        string st = "DELETE FROM " + d + " WHERE " + temp[1] + " = \'" + key + "\'";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //反馈
        cout << "\n输入的指令是:" << sql << "\n";
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
        cout <<"\n输入的指令是:"<<sql<<"\n";
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl;
        }
    
    }

    //表，键，值1,...
    void update_dynamic(string d,string key,string val,string text){
        //判断表名，填写sql语句！
        //get_n(3);
        title_back(d);
        //string col[16];
        //strcpy_s(a, st.c_str());
        //strcpy_s(col,col);
        //cout    << "1:" << temp[0] << "\n"
        //        << "2:" << temp[1] << "\n"
        //        << "2:" << temp[2] << "\n";
        
        string st = "UPDATE " + d + " SET " + temp[0] +"=" + val + "," + temp[2] +"=\'" + text + "\' WHERE " + temp[1] + " =\'" + key + "\'";
        char a[1024];
        //转换
        strcpy_s(a, st.c_str());
        //赋值
        sprintf_s(sql, 1024, a);
        //反馈
        cout <<"\n输入的指令是:"<<sql<<"\n";
        //执行
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
        {
            cout << "查询失败" << ": " << mysql_errno(&mysql) << endl<< mysql_error(&mysql) << endl;
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

        
        //cui
    void menu(){
        //选择falg
        int i=0;
        int k = 0;
        //防止锁死flag
        int flag=0;
        //提示 待修改
        cout    << "\t" << "-1 退出" << "\n"
                << "\t" << " 0 静态冗余" << "\n" 
                << "\t" << " 1 表查询" << "\n" 
                << "\t" << " 2 对newtalbe添加(key,val,deatil)" << "\n" 
                << "\t" << " 3 删除" << "\n" 
                << "\t" << " 4 更新" << "\n"
                << "\t" << " 5 自定义sql语句" << "\n";

        cout<<"\n\t"<<"请输入对应的选项数字\n:";
        scanf_s("%d", &i);
        cout<<"\n";
        //选择
        switch (i)
        {
            //退出程序
        case -1: 
            //ZhongDuan :
            ///< 释放结果集
	        mysql_free_result(res);

	        ///< 关闭数据库连接
	        mysql_close(&mysql);
        //实现推出
        return;
        //break; 多余的属于是

        //静态冗余 备份，这些二级选项可以删除，并且替换成相应的一级选项
        //
        /*
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
*/
        
        case 0:
            select();
        break;

        case 1:
            k = 1;
            get(k);
            cout<<"\n";
            cout    << "1:" << temp[0] << "\n";
            select(temp[0]);
        break;
    //添加
        case 2:
            k = 3;
            get(k);
            cout<<"\n";
            cout    << "1:" << temp[0] << "\n"
                    << "2:" << temp[1] << "\n"
                    << "2:" << temp[2] << "\n";
            add( temp[0], temp[1], temp[2]);
        break;
    //删除
        case 3:
            k = 1;
            get(k);
            cout<<"\n";            
            cout    << "1:" << temp[0] << "\n";
            remove( temp[0] );
        break;
    //更新
        case 4:
            k = 3;
            get(k);
            cout<<"\n";
            cout    << "1:" << temp[0] << "\n"
                    << "2:" << temp[1] << "\n"
                    << "2:" << temp[2] << "\n";
            update( temp[0], temp[1], temp[2]);
        break;
        /*
        case 3:
            n=3;
            num[0]='1';
            num[1]='1';
            num[2]='1';
            get(num,n);
            update(key, val, text);
        break;
        */
    //自定义语句
        case 5:
            custom();
        break;
        case 6:
            cout<<"后面就没了\n";
        break;
        //防止锁死  
        default:
        cout<<"\n\t未知指令|错误指令|循环错误\n";
            flag++;
            cout<<"\n";
            cout<<"flag="<<flag;
            if(flag==8)
            {
            cout<<"检查测到循环错误"<<"\n";
            cout<<"执行任何按键操作以终止程序"<<"\n";
            system("pause");
            return;
            }
        break;

        
        }
        
        system("pause");
        system("cls");
        menu();
        
    }
    
        //gui
    void gui(){}
};

    //("7/11","10","测试update的为动态") , ("7/3","32","测试动态''")
    //b.select();
    //测试读取函数
    //尝试让get运算后返回一个集合，例如数组。之后使用数组中的元素充当参数
    //尝试让get的返回值赋值给a
    //strcpy_s(a,b.);
    //现在零时通过全局变量temp实现传递

int main()
{
    DB b;
    //b.menu();
    b.admin();
    //select count(*) from information_schema.columns where table_schema=\'"+d+"\' and table_name=\'"+t+"\';
    cout<<"进程已结束,";
    system("pause");
    //结束
    return 0;
}

