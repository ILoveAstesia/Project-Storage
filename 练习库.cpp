#include<iostream>
#include <cmath>
#include <cstring>

double my_pow(double a, int b)
{
    int s = 0, i;
    double r = 1;
    if (b == 0) return 1;
    if (b < 0)
    {
        b *= -1;
        s = 1;
    }
    for (i = 0; i < b; i++)
        r *= a;
    if (s)r = 1 / s;
    return r;
}

using namespace std;

void SumOfTwo();
void TwoAdd_LinkList();
void NoRepeatString();

int main() {
    //SumOfTwo();
    //TwoAdd_LinkList()
    NoRepeatString();
    cout << "�밴�����ⰴ���Խ�������";
    getchar();
}
//Complete
void SumOfTwo() {
    int nums[4] = {2,4,1,7}, target = 9;
    int n, i;
    int L = sizeof(nums) / sizeof(nums[0]);
    for (n=0;n<L;n++) {
        for (i=n+1;i<L;i++) {
           if( nums[n] + nums[i] == target)
           {
               cout << "nums[" << n << "]" << "+" << "nums[" << i << "]" << "=" << target;
               break;
           }
        }
    }
    
}

//Complete
void TwoAdd_LinkList() {
    //����ṩ�˳�ʼ���б���ô���������鶨����ʡ�����鳤�ȣ����鳤���ɳ�ʼ�����б������һ������Ԫ�ص�����ֵ����
    //TODO���Էǵȳ�����

    int num1[] = {3, 2, 7,8},num2[] = {2,1,5};//����8723��512

    //typedef struct nod{...}listNod; ��˼�Ǵ�����һ��nod�ṹ�壬ͬʱ������һ����������listNod,������ͬʱ���á�

    //�жϳ���

    struct nod_LinkList
    {
        int val;
        nod_LinkList* next;
    };
    nod_LinkList nod1, nod2;

    nod1.val = sizeof(num1) / sizeof(num1[0]);
    nod1.next = NULL;
    nod2.val = sizeof(num2) / sizeof(num2[0]);
    nod2.next = NULL;

    nod_LinkList *nextP=NULL,*headP=&nod1;
    int n = 0, i = 0;
    
    // 1.                           2.              3.
    // nextP ��                                         
    // headP ��                                        nextP��
    // nod1[0.null] nod2[0,null]    nod1[0,&t]        nod1->t->null 
    //                                nextP��       
    // t[0,null]                    t[num[0],null]       

    headP = &nod1;//ָ��nod1
    nextP = headP;//ָ��1
    for(n=0;n<2;n++){

        if(headP==&nod1){
            for (i = 0; i < nod1.val; i++) {
                nod_LinkList* temp_Nod = (nod_LinkList*)malloc(sizeof(nod_LinkList));
                temp_Nod->val = num1[i];
                temp_Nod->next = NULL;

                nextP->next = temp_Nod;
                nextP = nextP->next;
            }
        }
        else if (headP == &nod2)
        {
            for (i = 0; i < nod2.val; i++) {
                nod_LinkList* temp_Nod = (nod_LinkList*)malloc(sizeof(nod_LinkList));//���������ռ�
                temp_Nod->val = num2[i];
                temp_Nod->next = NULL;

                nextP->next = temp_Nod;
                nextP = nextP->next;
            }
        }
        else
        {
            cout << "SomethingWrong";
        }
        headP = &nod2;//ָ��nod2
        nextP = headP;//2
    }

    //ToDO
    //float ��int ����Ϊn+=val*pow(10,i)��
    //L����� ��%10 ==0���ж�λ��

    //���׼��
    int n1=0,n2=0;
    //��ȡ
    //num1[] = { 3, 2, 7 }, num2[] = { 2,1,5 };//����723��512 723+512
    headP = &nod1;//ָ��nod1
    nextP = headP;//ָ��1
    for ( n = 0; n < 2; n++)
    {
        if (headP== &nod1)
        {
            for (i = 0; i < nod1.val; i++) {
                nextP = nextP->next;
                n1 +=   (nextP->val) * pow(10,i);
            }

            cout << n1 << "\n";

        }
        else if (headP == &nod2)
        {
            for (i = 0; i < nod2.val; i++) {
                nextP = nextP->next;
                n2 += (nextP->val) * pow(10, i);
            }

            cout << n2 <<"\n";
        }

        headP = &nod2;//ָ��nod2
        nextP = headP;//2
    }

    int sum = n1 + n2;
    cout <<"sum in int is:" << sum << "\n";

    //�ж�λ��

     for (i=0,n=sum;n;i++)
    {
        n/=10;
    }
    int length = i;


    nod_LinkList nod_Sum;
    headP = &nod_Sum;//ָ��nod_Sum
    nextP = headP;

    //��ȡ�쳣����Ϊ��ȡ��δ������Ŀռ䣬������ѭ��ֻ�����Σ�������ȴӦΪλ�����ȡ���˵��ĴΣ����ĴεĿռ�δ���䣨��Ϊ�����ڵ��ѭ��ֻ�����Σ������µġ�

    for ( n = 0; n < length; n++)
    {
        nod_LinkList* nodP_temp=(nod_LinkList*)malloc(sizeof(nod_LinkList));
        nodP_temp->val = sum % 10;
        sum /= 10;
        nodP_temp->next = NULL;

        nextP->next = nodP_temp;
        nextP = nextP->next;
    }

    //���������⣬l��ֵ������sumλ���仯���仯

    cout << "Sum in the form of LinkNod:";
    headP = &nod_Sum;//ָ��nod_Sum
    nextP = headP;
    for ( n = 0; n < length; n++)
    {
        nextP = nextP->next;
        cout << nextP->val;
    }

}

//Complete 
void NoRepeatString() {
    //ԭʼ�㷨������ʹ��flag�������ж�ASKII�룬���ظ�ʱflag���㣬����ð�����򣬱Ƚ�(��ʼ�㣬����)
    int flag;
    string s = "pw11 wke w",temp="",result="";
    //����ִ�temp��temp�ִ��ڲ��Ƚ��ظ�ֵ�����ϵ��ִ���result����ֵ�Ƚϣ���ĸ�ֵ��result��֮�󷵻�result.length();
    
    //����ִ�
    int n = 0;

    cout << "\n\t" << "������ַ���Ϊ" << s << "\n";
    cout << "\t" << "����Ϊ: " << s.length() << "\n\n";

    for ( n = 0; n < s.length(); n++)
    {
        //��ʼ�ָ�ֵ��
        temp = temp + s[n];
        cout << "\t" <<"ͷ�ַ���" << temp << "\n";
        
        for (int i = 1; i + n < s.length(); i++)
        {
            //�ִ�������ֵ��һ������ʼλ��n��һ���ǳ���i��
            //��ֹ����Ϊ��i+n���ڳ���
            // 
            //�ж��Ƿ��ظ�
            //�ж����ݣ��жϵ�ǰtemp
            //bug �ж�ֻ���ж����ԣ�����������Ҫȫ���ж� �� forѭ��

            //����Ԫ�غ�Ҫ��ӵ�Ԫ�رȽ�
            for (flag = 0; flag < i; flag++)
            {
                //�߼�Ϊ�Ƚϣ�ȫ������ͬ�����
                cout << "\t" << "����Ӵ���Ա(" << flag <<")��"<<  temp[flag]<<" �������ַ�����Ա(" << i + n << ")��" << s[i + n]<<"��\n";
                if (temp[flag] == s[i + n])
                {
                    cout << "\t" << temp[flag] << " �ͣ�" << s[i + n] << "�ظ���" << "\n";

                    //cout << "REPEAT" << "\n";
                    goto se1;//�ظ������ִ�Ϊ��ʱ����ִ�

                }
                else if (temp[flag] != s[i + n])
                {
                    //cout << "OK;"<<"\n";
                }
                else
                {
                    cout << "Wrong" << "\n";
                }
            }

            temp = temp + s[i + n];
            cout << "\t" << "���" << s[i + n] << " ����" << temp[i-1] << "����" << "\n";
            cout << "\t" <<"�����ִ�Ϊ��" << temp << "\n" 
                 //<< "�ִ����г�Ա�Ƚ���ϣ�" << "��" << i << "�ֽ���" << "\n\n"
                ;

        }
    se1:
        cout << "\t" << "�õ����ִ�Ϊ��" << temp << "\n";
        cout << "\t" << "�����ж�: " << temp << "�ĳ���(" << temp.length() << ")�Ƿ����" << result << "�ĳ���(" << result.length() << ");" << "\n";
        if (temp.length() > result.length()) {
            result = temp;
        }
        cout <<"\nĿǰ����ظ��Ӵ�Ϊ: " << result << "\n\n";
        
        //����ִ�
        temp = "";

    }
    cout << "����ظ��Ӵ�Ϊ: " << result << "\n\n";
    cout << "����Ϊ: " << result.length() << "\n\n";


}

//OnGoing
//void