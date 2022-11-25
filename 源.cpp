//随机数包
#include<stdlib.h>
//基本输入输出
#include <iostream>
//命名空间
using namespace std;

const int ctrl = 0;//控制是否开启调试信息

//声明
void scan_in(int H);
void scan_out(int H);

const int MAX = 1024;//最大柱面数
bool scIn = false;//默认磁头朝向 true为向内

int t = 0;//t用于初始化开始位置下标 表示从a[0]开始
//固定数组
//int a[] = { 12,30,20 };
//const int L = sizeof(a) / sizeof(a[0]);//自动计算数组长度

//随机数组
const int L = 1024;
int a[L];

//创建随机数组
void ran() {
	srand(time(0));
	for (int x = 0, b = 0; x < L; x++) {
		b = rand() % L;
		a[x] = b;
		//生成128内的整数
		cout << a[x] << endl;

	}
}

int main()
{
	ran();

	cout << "\t任务从：" << a[t] << " 开始"<<endl;
	//磁头方向是否朝内 
	scIn = rand() % 2;
	cout << scIn << endl;
	if (scIn == true)
	{		//是 
		cout << "磁头方向,向值增加的方向\n";
		scan_in(t);
	}
	else {	//否 
		cout << "磁头方向,向值减小的方向\n";
		scan_out(t);
	}
}

/**
 *
 * 算法分析
 * 	开	始
 *  磁头方向是否朝内
 *  是
 *  	朝内方向上是否有任务
 *  	是
 *  		任务距离是否小于等于当前值min默认为磁头任务的柱面号
 * 			是
 *  			将该任务下标设置为mark
 *  			将距离设置为min
 *  		否
 *  			继续循环
 *  	否
 * 			是否是第一次执行
 *  		是
 *  			判断反方向的最近任务
 *  			改变磁头方向
 *  			从反方向最近任务开始循环
 * 			否
 *  			结束
 *  否
 *  	朝外是否有任务
 *  	是
 *  		任务距离是否小于min
 *  		是
 *  			将该任务设置下表为mark
 *  			将该任务距离设置为min
 *  		否
 *  			继续循环知道遍历所有
 *  	否
 *  		是否是第一次执行
 * 			是
 * 				判断反方向的最近任务
 * 				改变磁头方向
 * 				从反方向最近任务开始循环
 * 			否
 *  			结束
 *
 *
 *
 **/

int flag = 0;
void scan_in(int H) {
	//H表示将要被比价的元素的下标  
	int mark = H, min = a[H];
	//是否有同方向任务 

	for (int j = 0; j < L; j++) {//对每一数组成员遍历 j不是比较数组的下标，只是循环的计数器 
		min = MAX;
		
		//这里的目的是，有两个数组，数组一的每一个元素和数组二的每一个元素比较，得出最最近值 。 难点在于数组一二是同一个数组 
		
		if (ctrl == 1)
		cout << "[Info] 当前任务：" << a[mark]<<endl;

		if (ctrl == 1)
		cout << " 当前H：" << H << " 当前 j：" << j << endl;

		for (int i = 0; i < L; i++)
		{	//i代表将要来比较的数组下标 

			if (a[i] == -1||i==H) {
				continue;//如果当前值为空或下标是本身就跳过 a[i]与a[H]这一个值的比较 
			}
			
			if (a[i] >= a[H] && (a[i] - a[H]) <= min) {//判断是否同方向  [---] a[i] >= a[H] && (a[i] - a[H]) <= min --->>> a[i] <= a[H] && (a[H] - a[i]) <= min
				//方向相同 ，判断是否是目前最近值 
				if (ctrl == 1)
					cout << "[Info] 当前i：" << i << endl;
					//目前最近值确定 零时
					mark = i;
					min = a[mark] - a[H];//[---] 绝对值 a[mark] - a[H] --->>> a[H] - a[mark]
			}
			
		}
		//和所有的i成员比较完后，确定mark就是和j最近的任务,最近的值为,a[mark]-H
		if (mark==H)//如果没有后继任务，转换 没有后继任务如何表达？ 没有比他更大的了
		{
			cout << "BRE IN\n";
			if (flag == 1) {//如果转换过磁头
				return;
			}

			min = MAX;

			//寻找最近反向任务 out (减小的方向) 
			for (int x = 0; x < L; x++) {//对所有值遍历 为记录器
				//
				if (a[x] == -1 || x == H) {//如果当前值为空或下标是本身就跳过 a[x]与a[H]这一个值的比较 
					continue;
				}

				if ((a[H]-a[x] ) <= min) { //[---] 绝对值 a[H]-a[x]--->>>a[x]-a[H] 绝对值

					if(ctrl==1)
					cout << "[Info] 当前x：" << x<<" H: " << H << " a[H]: " << a[H] << " a[x]: " << a[x] << " a[H]-a[x]: " << a[H] - a[x] << endl;

					//目前最近值确定 
					mark = x;
					min = a[H]- a[mark];//[---] 绝对值 a[H]-a[mark]--->>>a[mark]-a[H]
				}

			}

			//最终 mark
			H = mark;
			cout << "\n\t任务号：" << mark << "\n";
			cout << "\n\t任务值：" << a[mark] << "\n";
			cout << "\n\t距  离：" << min << "\n";

			flag = 1;
			scIn = false;
			cout << "更换磁头方向,向值减少的方向\n\n";
			scan_out(H);
			//保险
			return;
			//break;
		}


		cout << "\n\t任务号：" << mark << "\n";
		cout << "\t最近值：" << a[mark] << "\n";
		cout << "\t距  离：" << a[mark] - a[H] << "\n\n";
		

		a[H] = -1;//H号任务执行完毕 
		H = mark;//将这个最近任务a[mark]设置为下一个 待比较的对象

	}//fir for end
	
}

void scan_out(int H) {

	int mark = H, min = a[H];

	for (int j = 0; j < L; j++) {
		min = MAX;

		if (ctrl == 1)
		cout << "[Info] 当前任务：" << a[mark] << endl;

		if (ctrl == 1)
		cout << " 当前H：" << H << " 当前 j：" << j << endl;

		for (int i = 0; i < L; i++)
		{	

			if (a[i] == -1 || i == H) {
				continue;
			}

			if (a[i] <= a[H] && (a[H]-a[i] ) <= min) {
				
				if (ctrl == 1)
				cout << "[Info] 当前i：" << i << endl;
				
				mark = i;
				min = a[H]-a[mark];
			}

		}
		
		if (mark == H)
		{
			cout << "BRE OUT\n";
			if (flag == 1) {
				return;
			}

			min = MAX;
			
			for (int x = 0; x < L; x++) {
				
				if (a[x] == -1 || x == H) {
					continue;
				}

				if ((a[x]-a[H]  ) <= min) {

					if (ctrl == 1)
					cout << "[Info] 当前x：" << x << " H: " << H << " a[H]: " << a[H] << " a[x]: " << a[x] << " a[H]-a[x]: " << a[H] - a[x] << endl;
					
					mark = x;
					min = a[mark] - a[H] ;
				}

			}

			
			H = mark;
			cout << "\n\t任务号：" << mark << "\n";
			cout << "\n\t任务值：" << a[mark] << "\n";
			cout << "\n\t距  离：" << min << "\n";

			flag = 1;
			scIn = true;
			cout << "更换磁头方向,向值增加的方向\n\n";
			scan_in(H);
			
			return;
			
		}

		cout << "\n\t任务号：" << mark << "\n";
		cout << "\t最近值：" << a[mark] << "\n";
		cout << "\t距  离：" << min << "\n\n";


		a[H] = -1; 
		H = mark;

	}

}
