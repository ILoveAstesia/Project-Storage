//ͷ�ļ�
#include<iostream>
#include<sstream>
#include<string>
#include "mysql.h"

using namespace std;
//{}[]()., :; +-*/ % &| ^ != <> ? @#\

const char dbusername[10] = "root";
const char dbpassword[10] = "Astesia";
const char dbname[12] = "new_schema";
//String ת��Ϊ char[*]
void transformation(){

}

//����
//class Bill;
//struct linkT;
//linkT* initiallink(int);
//void display(linkT*);
//void men();


//����Ϊ��������ķ���

struct bill
{
    int times = 0;
    float num = .0;
    string detail = "��";
};

//��������ļ�¼��ʽ��
class arr_Based {
public:
    int i = 0, n = 0, C = 31, y = 0;
    //�򵥵Ĵ������飬��������С��ͨ���߼��жϼ���û����´��������ʱ�����������ֱ�Ӹ��ıϾ���c
    bill arr[12][31];
    //Ĭ��2022
    arr_Based() {
        y = 2022;
        main();
    }
    //����iΪ���
    arr_Based(int i) {
        y = i;
        main();

    }

    void main() {
        //��ʼ������
        /*      for ( n = 0; n < 12; n++)
        {
                arr[n][0].month = n + 1;
        }*/
        //for (i = 0; i < C; i++) {
        //    arr[n][i].day = i + 1;
        //}
    }

    //

    //����
    // 
    //�ֶ���������ڣ������������Զ�ȡ����
    //��չ���ɵ��ӣ��ɶ�����÷����������ӣ�ϸ�ڵ��ӡ�
    void add_arr(int m, int d, float num, string t)
    {
        m--, d--;
        //ing ��һ�������Ϣ��ճ�ʼֵ���ա����ڶ��������Ϣ����ԭ����Ϣ����������ֱ�Ӹ��Ľṹ���ʼֵ��Ϊ����
        if (arr[m][d].times++ == 0/*arr[m][d].detail == "��"*/) {
            arr[m][d].detail = "";
        }
        //��������
        //arr[m][d].month = m+1;
        //arr[m][d].day = d+1;

        arr[m][d].times++;//���������Ϣ�Ĵ���

        arr[m][d].num += num;
        arr[m][d].detail += t;

        cout << "\n\t" << "һ��" << m + 1 << "��" << d + 1 << "�յļ�¼�����ɡ�\n";

        cout << "\n\t" << y << "��" << m + 1 << "��" << d + 1 << "��" << "\n";
        cout << "\t" << "����" << arr[m][d].num << "Ԫ/��" << "\n";
        cout << "\t" << "ϸ��:" << arr[m][d].detail << "��" << "\n";       
        cout << "\n";

    }

    //ɾ��

    void delete_arr(int m, int d)
    {
        m--, d--;
        //��ʼ��
        arr[m][d].times = 0;
        arr[m][d].num = .0;
        arr[m][d].detail = "��";
    }
    //ɾ��ĳ����L��
    void delete_arr(int m, int d, int l)
    {
        m--, d--;
        //��ʼ��
        for (i = 0; i < l; i++)
        {
            arr[m][d + i].times = 0;
            arr[m][d + i].num = .0;
            arr[m][d + i].detail = "��";
        }

    }
    //ɾ������
    void delete_arr(int a)
    {
        if (a == 1)
        {
            cout << "ɾ������ֵ�С���(n)" << "\n";
        }

    };

    //��ѯ

    void inspect_arr()
    {
        C = 5;
        //cout << "\n\n\n";
        //��ȡ����(��ȫ)
        for (i = 0; i < C; i++)
        {
            cout << "\n\t" << y << "��" << n << "��" << i << "��" << "\n";


            cout << "\t" << "����" << arr[n][i].num << "Ԫ/��" << "\n";
            cout << "\t" << "ϸ��:" << arr[n][i].detail << "��" << "\n";
            cout << "\n";

        }
        cout << "����" << "\n";
    }
    //���ĳ��ļ�¼
    void inspect_arr(int m, int d)
    {

        cout << "\n\t" << "���ڼ�飺" << y << "��" << m << "��" << d << "��" << "�ļ�¼����" << "\n\n";

        cout << "\n\t" << y << "��" << m << "��" << d << "��" << "\n";
        m--, d--;
        cout << "\t" << "����" << arr[m][d].num << "Ԫ/��" << "\n";
        cout << "\t" << "ϸ��:" << arr[m][d].detail << "��" << "\n";
        cout << "\n";


    }
    //����ĳ�쿪ʼ��L����¼
    void inspect_arr(int m, int d, int l)
    {

        cout << "\n\t" << "���ڼ�飺" << y << "��" << m << "��" << d << "�����" << l << "��" << "��¼����" << "\n\n";

        m--, d--;
        for (i = 0; i < l; i++)
        {
            cout << "\n\t" << y << "��" << m + 1 << "��" << d + 1 + i << "��" << "\n";
            cout << "\t" << "����" << arr[m][d + i].num << "Ԫ/��" << "\n";
            cout << "\t" << "ϸ��:" << arr[m][d + i].detail << "��" << "\n";
            cout << "\n";
        }

    }
    //��ѯ��������֮��ļ�¼
    void inspect_arr_between(int m, int star, int end)
    {


    }

    //����

    //�ı�ĳһ����¼ m��d���꣬s��Ϣ
    //�����Ϣ
    void change_add(int m, int d, int n, string s) {
        cout << "\n\t" << "�����޸ģ�" << y << "��" << m << "��" << d << "��" << "�ļ�¼����" << "\n\n";
        m--, d--;
        arr[m][d].times++;
        arr[m][d].detail += s;
        arr[m][d].num += n;
        cout << "\t" << "���޸Ĵ�����" << arr[m][d].times << "��" << "\n";
        cout << "\t" << "���ѣ�" << arr[m][d].num << "Ԫ/��" << "\n";
        cout << "\t" << "ϸ��:" << arr[m][d].detail << "��" << "\n";
        cout << "\n";
    }

    void change(int m, int d, int n) {
        //���Դ���ԭ���ַ���������s1��Ȼ��ֵ��s2�����s2���޸�s2����s2����ԭ��s1
    }

    //cui ���ֲ˵��û�����
    void menu() {
        cout << "�˵���ʼ����" << "\n";

        //string s="0";
        //�ɳ���ö�� ֻ������̫������
        //��ȡ�ļ���
        int s = 0, m = 1, d = 1;
        float n = 0.0;
        string i = " ";
        // getchar();
        cout << "1 ����" << "\n";
        cout << "2 ��ѯ" << "\n";
        cout << "3 �޸�(n)" << "\n";
        cout << "4 ɾ��(n)" << "\n";
        cout << "0 �˳�" << "\n";


        scanf_s("%d", &s);
        switch (s)
        {

        case 0: cout << "�˳���." << "\n";
            return;

        case 1: cout << "����" << "\n";

            cout << "(�ո����)������� m d:";
            scanf_s("%d %d", &m, &d);

            cout << "(�ո����)������� n:";
            scanf_s("%f", &n);

            cout << "(�س�����)������� i:";
            cin >> i;
            // getline(cin,i);

            cout << "\n";
            add_arr(m, d, n, i);
            break;

        case 2: cout << "��ѯ" << "\n";

            cout << "(�ո����)������� m d:";
            scanf_s("%d %d", &m, &d);

            cout << "\n";
            inspect_arr(m, d);
            break;

        case 3: cout << "�޸�" << "\n";

            cout << "(�ո����)������� m d:";
            scanf_s("%d %d", &m, &d);

            cout << "(�ո����)������� n (��ʾҪ��ӵĽ���Ϊ��ֵ):";
            scanf_s("%f", &n);

            cout << "(�س�����)������� i ����ʾҪ��ϸ�ں�������Ϣ��:";
            cin >> i;
            change_add(m, d, n, i);
            break;

        case 4: cout << "ɾ��" << "\n";

            cout << "(�ո����)������� m d:";
            scanf_s("%d %d", &m, &d);

            delete_arr(m, d);
            break;
        
        default:
            cout << "δ֪���������� ������" << "\n";
            break;
        }

        cout << "�˵���������" << "\n";
        menu();
    }

};

class DB{

    public:
        MYSQL mysql;
	    //MYSQL *mysql = mysql_init(nullptr);
	    ///< ��ʼ�����
        DB(){
            mysql_init(&mysql);
            //������������
            mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

            ///< ���ӵ����ݿ�       �������    ��������    �û��������롢  ���ݿ�����     �˿ںš�socketָ�롢��ǣ�
            if (!mysql_real_connect(&mysql, "localhost", dbusername, dbpassword, dbname, 3306, nullptr, 0))
            {
                cout << "���ݿ�����ʧ��" << mysql_errno(&mysql) << endl;
                // return -1;
            }
            cout << "���ݿ����ӳɹ�" << endl << endl;
        }
        ///< �������ݿ��Ӧ�ṹ��
        MYSQL_RES* res = nullptr;
        ///< ������Ž���Ľṹ��
        MYSQL_ROW row;
        char sql[1024]{ 0 };
    

    void select(){
    ///< ���ò�ѯ�ӿ�
    //��ѯ
    sprintf_s(sql, 1024, "select * from new_table");

    //���
    //sprintf_s(sql, 1024, "insert into new_table values('7/18', '0','����gbk')");
    //ִ�����
    // mysql_real_query(&mysql, sql, (unsigned int)strlen(sql));
    
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "��ѯʧ��" << ": "  << mysql_errno(&mysql) << endl;
	}
	else
	{
		cout << "��ѯ�ɹ�" << endl << endl;

		///< װ�ؽ����
		res = mysql_store_result(&mysql);

		if (nullptr == res)
		{
			cout << "װ������ʧ��" << ": " << mysql_errno(&mysql)  << endl;
		}
		else
		{
			///< ȡ�������������
			while (row = mysql_fetch_row(res))
			{
				cout << row[0] << "  "  << row[1] << "  " << row[2] << endl;
			}
		}
	}

	///< �ͷŽ����
	// mysql_free_result(res);

	///< �ر����ݿ�����
	// mysql_close(&mysql);

	// system("pause");
    }

    void add(){
        //���
        sprintf_s(sql, 1024, "insert into new_table values('7/10', '0','����add')");
        //ִ�����
        mysql_real_query(&mysql, sql, (unsigned int)strlen(sql));
    
    }

    void remove(){
        //��� DELETE FROM ������ WHERE ������ = ֵ
        sprintf_s(sql, 1024, "DELETE FROM new_table WHERE idnew_table = '7/10'");
        //ִ�����
        //mysql_real_query(&mysql, sql, (unsigned int)strlen(sql));
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "��ѯʧ��" << ": "  << mysql_errno(&mysql) << endl;
	}
    }

    void update(){
        //UPDATE Person SET FirstName = 'Fred' WHERE LastName = 'Wilson' 
        sprintf_s(sql, 1024, "UPDATE new_table SET new_tablecol = 10 WHERE idnew_table = '7/10'");
        //ִ�����
        if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "��ѯʧ��" << ": "  << mysql_errno(&mysql) << endl;
	}
    
    }

    void custom(){

    }

    void menu(){
        int i=0;
        cout << "\t" << "0 s" << "\n" << "\t" << "1 a" << "\n" << "\t" << "2 r" << "\n" << "\t" << "3 u" << "\n" << "\t" << "4 c" << "\n";
        scanf_s("%d", &i);
        switch (i)
        {
        case -1: 	
        ///< �ͷŽ����
	     mysql_free_result(res);

	///< �ر����ݿ�����
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

void database(){

    //��Ҫ׼��������
    //�Զ�������� �þ��Ӻ�����ֿ�
    //���ϱ�����������׼�� ���ߵ�������һ��display
    //ʵ����ɾ�Ĳ�
    //�Զ������


    cout<<"�޸���"<<"\n";
    ///< �������ݿ���
	MYSQL mysql;
	//MYSQL *mysql = mysql_init(nullptr);
	///< ��ʼ�����
	mysql_init(&mysql);
    //������������
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	///< ���ӵ����ݿ�       �������    ��������    �û��������롢  ���ݿ�����     �˿ںš�socketָ�롢��ǣ�
	if (!mysql_real_connect(&mysql, "localhost", dbusername, dbpassword, dbname, 3306, nullptr, 0))
	{
		cout << "���ݿ�����ʧ��" << mysql_errno(&mysql) << endl;
		// return -1;
	}

	cout << "���ݿ����ӳɹ�" << endl << endl;

	///< �������ݿ��Ӧ�ṹ��
	MYSQL_RES *res = nullptr;
	///< ������Ž���Ľṹ��
	MYSQL_ROW row;

	char sql[1024]{ 0 }/*,table_name[16]="test_table"*/;

    //�����Զ������
    // char strSQL[128];
    // strSQL <<"select * from " << table_name << "";
	// sprintf_s(sql, 1024, "select * from test_table");
    stringstream ss;
    /*ss << "insert `t_image` (`name`,`path`,`size`)values('image";
    ss << i << ".jpg','d:/img/', 10240)";
    sqls = ss.str();*/

	///< ���ò�ѯ�ӿ�
    //��ѯ
     sprintf_s(sql, 1024, "select * from new_table");

    //���
    //sprintf_s(sql, 1024, "insert into new_table values('7/18', '0','����gbk')");
    //ִ�����
    // mysql_real_query(&mysql, sql, (unsigned int)strlen(sql));
    
	if (mysql_real_query(&mysql, sql, (unsigned int)strlen(sql)))
	{
		cout << "��ѯʧ��" << ": "  << mysql_errno(&mysql) << endl;
	}
	else
	{
		cout << "��ѯ�ɹ�" << endl << endl;

		///< װ�ؽ����
		res = mysql_store_result(&mysql);

		if (nullptr == res)
		{
			cout << "װ������ʧ��" << ": " << mysql_errno(&mysql)  << endl;
		}
		else
		{
			///< ȡ�������������
			while (row = mysql_fetch_row(res))
			{
				cout << row[0] << "  "  << row[1] << "  " << row[2] << endl;
			}
		}
	}

	///< �ͷŽ����
	mysql_free_result(res);

	///< �ر����ݿ�����
	mysql_close(&mysql);

	system("pause");

	// return 0;
}

int main()
{
    DB b;
    b.menu();
   
    //����
    return 0;
}

//int main(){
// prepare();
       // database();
   //linkT* headp=initiallink(5);
   //display(headp);
   //�������ڵ��˵���//�����������Ի����¼����˵�
       //arr_Based a(2002);//����һ��2002����˵�
   //a.main();
   //���ȫ��
   //a.inspect_arr();
       //cout << "��ӡ���";
   // ��
   // ���һ�����ŵĶ���
       //a.add_arr(6, 4, 32.5, "���¼��ţ����⣬���ţ�����");
   /*
       a.add_arr(6, 7, 5, "����");

       // ���¼��
       //a.inspect_arr(6, 4);
       // ��

       cout << "������顭��";
       // �������
       a.inspect_arr(6, 1,7);

       // ��
       cout << "�޸ġ���";
       // �޸�
       a.change_add(6, 7, 7,"����");
       cout << "�޸ĺ��顭��";
       // �޸ĺ���
       a.inspect_arr(6, 4);
       a.inspect_arr(6, 7);

       //ɾ
       a.delete_arr(6, 4);
       cout << "ɾ�޸ĺ��顭��";
       // �޸ĺ���
       a.inspect_arr(6, 4);
       a.inspect_arr(6, 7);
   */
   // ���ز˵� reqquired
       //a.menu();

   //int n;
   //scanf_s("%d", &n);

   //return֮��û����!!!!!
   // cout << "�밴�����ⰴ���Խ������Ĳ��ԡ��� :";
   // getchar();
  //  }



//
//  ����������н�������д���ף���չ�Խϸߣ�
//  ������̣����нϿ죬��д���ѣ���չ�Խϲ
// 
//  �ҵ��뷨�ǣ��ȱ�д�������Ȼ����ֲ��Ϊ������̡�
// 
//  �����ܣ��˵�����ɾ�Ĳ飬�˵��ڲ�����ɾ�Ĳ飬������ƽ��������λ����������bill��Ҫ����µĳ�Ա��������������
//
//  �㷨������������������ʵ��һ�¡���С��������Ŀ��
//
//  ��������Ա���󣬹���Ա������ò˵��������˵�����������ɾ�Ĳ飬(���߽��û�)
//  ���ӣ�����Ϊͷ�ڵ㣬ͷ�ڵ������Ӻ�������ӽڵ� ��
//  �½����νڵ㣬�����νڵ㸳ֵ����ͷ�ڵ�next���渡�νڵ�ĵ�ַ�����νڵ�ָ��null��
// 
//  ɾ��������Ϊͷ�ڵ㣬ͷ�ڵ����ɾ��������ɾ���ڵ㡣
// 
//  ���ģ�
// 
//  ��ѯ����ȫ��ѯ�����ֲ�ѯ��������
//
//  ֮��ʹ���ļ�����ϵͳ����
//  ���ʹ��database 
//


/*
//�����˵���
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
        cout << "Ĭ�Ϲ��캯�����óɹ�";
    }
    Bill(int num, int date, string temp)
    {
        this->moneyNum = num;
        this->date = date;
        detail = temp;
        cout << "���ι��캯�����óɹ�";
    }

private:


};

//Ĭ�ϳ�ʼ������Ϊ0��
int Bill::sum = 0;

//������������
struct linkT
{
    //����&���Կ���
    int num;
    //������
    Bill elemB;
    //ָ����
    struct linkT* Nextp;
};

//����һ����ʼ������
//��ʼ��������������ͷ�ڵ������
linkT* initiallink(int i) {
    //linkT* p = null;

    linkT* headp = (linkT*)malloc(sizeof(linkT));    //��ʼ������ͷָ��
    headp->num = i;          //ͷ�ڵ㴢�泤��
    linkT* temp = headp;    //��ʱָ��ָ��ͷָ�봦��ͬһλ��
    int n;  //ѭ��������
    for (n = 0; n < i; n++)
    {   //[head]->[newS]
        linkT* newS = (linkT*)malloc(sizeof(linkT)); //�½�����ڵ�
        newS->num = n + 1;  //��ʱ���ڸ�ֵ��ʼ�� ���д�����
        newS->Nextp = NULL; //��ʼ��Section,Ĭ�ϸ�ֵNULL
        temp->Nextp = newS; //����������
        temp = temp->Nextp; //
    }
    return headp;
}

//��ʾ����
void display(linkT* headp)
{
    linkT* temp = headp->Nextp;//ָ���һ�����ݽ��ļ�
    //[H] [1] [2] ... [i]
    int n;//������
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

//����˵�����
void men()
{
    cout << "���ò˵��ɹ�";
    return;
}
*/