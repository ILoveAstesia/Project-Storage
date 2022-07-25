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
    cout << "请按下任意按键以结束……";
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
    //如果提供了初始化列表，那么可以在数组定义中省略数组长度，数组长度由初始化器列表中最后一个数组元素的索引值决定
    //TODO测试非等长数组

    int num1[] = {3, 2, 7,8},num2[] = {2,1,5};//储存8723和512

    //typedef struct nod{...}listNod; 意思是创建了一个nod结构体，同时给了它一个别名叫做listNod,且两者同时可用。

    //判断长度

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
    // nextP ↓                                         
    // headP ↓                                        nextP↓
    // nod1[0.null] nod2[0,null]    nod1[0,&t]        nod1->t->null 
    //                                nextP↓       
    // t[0,null]                    t[num[0],null]       

    headP = &nod1;//指向nod1
    nextP = headP;//指向1
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
                nod_LinkList* temp_Nod = (nod_LinkList*)malloc(sizeof(nod_LinkList));//创建匿名空间
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
        headP = &nod2;//指向nod2
        nextP = headP;//2
    }

    //ToDO
    //float 改int 方法为n+=val*pow(10,i)；
    //L的求解 用%10 ==0来判断位数

    //相加准备
    int n1=0,n2=0;
    //提取
    //num1[] = { 3, 2, 7 }, num2[] = { 2,1,5 };//储存723和512 723+512
    headP = &nod1;//指向nod1
    nextP = headP;//指向1
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

        headP = &nod2;//指向nod2
        nextP = headP;//2
    }

    int sum = n1 + n2;
    cout <<"sum in int is:" << sum << "\n";

    //判断位数

     for (i=0,n=sum;n;i++)
    {
        n/=10;
    }
    int length = i;


    nod_LinkList nod_Sum;
    headP = &nod_Sum;//指向nod_Sum
    nextP = headP;

    //读取异常是因为读取了未被分配的空间，及可能循环只有三次，但是你却应为位数多读取到了第四次，第四次的空间未分配（因为创建节点的循环只有三次）而导致的。

    for ( n = 0; n < length; n++)
    {
        nod_LinkList* nodP_temp=(nod_LinkList*)malloc(sizeof(nod_LinkList));
        nodP_temp->val = sum % 10;
        sum /= 10;
        nodP_temp->next = NULL;

        nextP->next = nodP_temp;
        nextP = nextP->next;
    }

    //出现了问题，l的值不嫩随sum位数变化而变化

    cout << "Sum in the form of LinkNod:";
    headP = &nod_Sum;//指向nod_Sum
    nextP = headP;
    for ( n = 0; n < length; n++)
    {
        nextP = nextP->next;
        cout << nextP->val;
    }

}

//Complete 
void NoRepeatString() {
    //原始算法分析，使用flag计数，判断ASKII码，当重复时flag归零，类似冒泡排序，比较(起始点，长度)
    int flag;
    string s = "pw11 wke w",temp="",result="";
    //获得字串temp，temp字串内部比较重复值，符合的字串和result现有值比较，大的赋值到result，之后返回result.length();
    
    //获得字串
    int n = 0;

    cout << "\n\t" << "输入的字符串为" << s << "\n";
    cout << "\t" << "长度为: " << s.length() << "\n\n";

    for ( n = 0; n < s.length(); n++)
    {
        //初始字赋值，
        temp = temp + s[n];
        cout << "\t" <<"头字符：" << temp << "\n";
        
        for (int i = 1; i + n < s.length(); i++)
        {
            //字串有两个值，一个是起始位置n，一个是长度i。
            //终止条件为，i+n等于长度
            // 
            //判断是否重复
            //判断依据，判断当前temp
            //bug 判断只会判断两对，但是我们需要全部判断 用 for循环

            //现有元素和要添加的元素比较
            for (flag = 0; flag < i; flag++)
            {
                //逻辑为比较，全部都不同再添加
                cout << "\t" << "检查子串成员(" << flag <<")："<<  temp[flag]<<" ；和主字符串成员(" << i + n << ")：" << s[i + n]<<"。\n";
                if (temp[flag] == s[i + n])
                {
                    cout << "\t" << temp[flag] << " 和：" << s[i + n] << "重复：" << "\n";

                    //cout << "REPEAT" << "\n";
                    goto se1;//重复，该字串为零时最大字串

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
            cout << "\t" << "添加" << s[i + n] << " 到：" << temp[i-1] << "后面" << "\n";
            cout << "\t" <<"最新字串为：" << temp << "\n" 
                 //<< "字串所有成员比较完毕，" << "第" << i << "轮结束" << "\n\n"
                ;

        }
    se1:
        cout << "\t" << "得到的字串为：" << temp << "\n";
        cout << "\t" << "正在判断: " << temp << "的长度(" << temp.length() << ")是否大于" << result << "的长度(" << result.length() << ");" << "\n";
        if (temp.length() > result.length()) {
            result = temp;
        }
        cout <<"\n目前最长无重复子串为: " << result << "\n\n";
        
        //清空字串
        temp = "";

    }
    cout << "最长无重复子串为: " << result << "\n\n";
    cout << "长度为: " << result.length() << "\n\n";


}

//OnGoing
//void