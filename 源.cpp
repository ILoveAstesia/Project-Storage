//�������
#include<stdlib.h>
//�����������
#include <iostream>
//�����ռ�
using namespace std;

const int ctrl = 0;//�����Ƿ���������Ϣ

//����
void scan_in(int H);
void scan_out(int H);

const int MAX = 1024;//���������
bool scIn = false;//Ĭ�ϴ�ͷ���� trueΪ����

int t = 0;//t���ڳ�ʼ����ʼλ���±� ��ʾ��a[0]��ʼ
//�̶�����
//int a[] = { 12,30,20 };
//const int L = sizeof(a) / sizeof(a[0]);//�Զ��������鳤��

//�������
const int L = 1024;
int a[L];

//�����������
void ran() {
	srand(time(0));
	for (int x = 0, b = 0; x < L; x++) {
		b = rand() % L;
		a[x] = b;
		//����128�ڵ�����
		cout << a[x] << endl;

	}
}

int main()
{
	ran();

	cout << "\t����ӣ�" << a[t] << " ��ʼ"<<endl;
	//��ͷ�����Ƿ��� 
	scIn = rand() % 2;
	cout << scIn << endl;
	if (scIn == true)
	{		//�� 
		cout << "��ͷ����,��ֵ���ӵķ���\n";
		scan_in(t);
	}
	else {	//�� 
		cout << "��ͷ����,��ֵ��С�ķ���\n";
		scan_out(t);
	}
}

/**
 *
 * �㷨����
 * 	��	ʼ
 *  ��ͷ�����Ƿ���
 *  ��
 *  	���ڷ������Ƿ�������
 *  	��
 *  		��������Ƿ�С�ڵ��ڵ�ǰֵminĬ��Ϊ��ͷ����������
 * 			��
 *  			���������±�����Ϊmark
 *  			����������Ϊmin
 *  		��
 *  			����ѭ��
 *  	��
 * 			�Ƿ��ǵ�һ��ִ��
 *  		��
 *  			�жϷ�������������
 *  			�ı��ͷ����
 *  			�ӷ������������ʼѭ��
 * 			��
 *  			����
 *  ��
 *  	�����Ƿ�������
 *  	��
 *  		��������Ƿ�С��min
 *  		��
 *  			�������������±�Ϊmark
 *  			���������������Ϊmin
 *  		��
 *  			����ѭ��֪����������
 *  	��
 *  		�Ƿ��ǵ�һ��ִ��
 * 			��
 * 				�жϷ�������������
 * 				�ı��ͷ����
 * 				�ӷ������������ʼѭ��
 * 			��
 *  			����
 *
 *
 *
 **/

int flag = 0;
void scan_in(int H) {
	//H��ʾ��Ҫ���ȼ۵�Ԫ�ص��±�  
	int mark = H, min = a[H];
	//�Ƿ���ͬ�������� 

	for (int j = 0; j < L; j++) {//��ÿһ�����Ա���� j���ǱȽ�������±ֻ꣬��ѭ���ļ����� 
		min = MAX;
		
		//�����Ŀ���ǣ����������飬����һ��ÿһ��Ԫ�غ��������ÿһ��Ԫ�رȽϣ��ó������ֵ �� �ѵ���������һ����ͬһ������ 
		
		if (ctrl == 1)
		cout << "[Info] ��ǰ����" << a[mark]<<endl;

		if (ctrl == 1)
		cout << " ��ǰH��" << H << " ��ǰ j��" << j << endl;

		for (int i = 0; i < L; i++)
		{	//i����Ҫ���Ƚϵ������±� 

			if (a[i] == -1||i==H) {
				continue;//�����ǰֵΪ�ջ��±��Ǳ�������� a[i]��a[H]��һ��ֵ�ıȽ� 
			}
			
			if (a[i] >= a[H] && (a[i] - a[H]) <= min) {//�ж��Ƿ�ͬ����  [---] a[i] >= a[H] && (a[i] - a[H]) <= min --->>> a[i] <= a[H] && (a[H] - a[i]) <= min
				//������ͬ ���ж��Ƿ���Ŀǰ���ֵ 
				if (ctrl == 1)
					cout << "[Info] ��ǰi��" << i << endl;
					//Ŀǰ���ֵȷ�� ��ʱ
					mark = i;
					min = a[mark] - a[H];//[---] ����ֵ a[mark] - a[H] --->>> a[H] - a[mark]
			}
			
		}
		//�����е�i��Ա�Ƚ����ȷ��mark���Ǻ�j���������,�����ֵΪ,a[mark]-H
		if (mark==H)//���û�к������ת�� û�к��������α� û�б����������
		{
			cout << "BRE IN\n";
			if (flag == 1) {//���ת������ͷ
				return;
			}

			min = MAX;

			//Ѱ������������� out (��С�ķ���) 
			for (int x = 0; x < L; x++) {//������ֵ���� Ϊ��¼��
				//
				if (a[x] == -1 || x == H) {//�����ǰֵΪ�ջ��±��Ǳ�������� a[x]��a[H]��һ��ֵ�ıȽ� 
					continue;
				}

				if ((a[H]-a[x] ) <= min) { //[---] ����ֵ a[H]-a[x]--->>>a[x]-a[H] ����ֵ

					if(ctrl==1)
					cout << "[Info] ��ǰx��" << x<<" H: " << H << " a[H]: " << a[H] << " a[x]: " << a[x] << " a[H]-a[x]: " << a[H] - a[x] << endl;

					//Ŀǰ���ֵȷ�� 
					mark = x;
					min = a[H]- a[mark];//[---] ����ֵ a[H]-a[mark]--->>>a[mark]-a[H]
				}

			}

			//���� mark
			H = mark;
			cout << "\n\t����ţ�" << mark << "\n";
			cout << "\n\t����ֵ��" << a[mark] << "\n";
			cout << "\n\t��  �룺" << min << "\n";

			flag = 1;
			scIn = false;
			cout << "������ͷ����,��ֵ���ٵķ���\n\n";
			scan_out(H);
			//����
			return;
			//break;
		}


		cout << "\n\t����ţ�" << mark << "\n";
		cout << "\t���ֵ��" << a[mark] << "\n";
		cout << "\t��  �룺" << a[mark] - a[H] << "\n\n";
		

		a[H] = -1;//H������ִ����� 
		H = mark;//������������a[mark]����Ϊ��һ�� ���ȽϵĶ���

	}//fir for end
	
}

void scan_out(int H) {

	int mark = H, min = a[H];

	for (int j = 0; j < L; j++) {
		min = MAX;

		if (ctrl == 1)
		cout << "[Info] ��ǰ����" << a[mark] << endl;

		if (ctrl == 1)
		cout << " ��ǰH��" << H << " ��ǰ j��" << j << endl;

		for (int i = 0; i < L; i++)
		{	

			if (a[i] == -1 || i == H) {
				continue;
			}

			if (a[i] <= a[H] && (a[H]-a[i] ) <= min) {
				
				if (ctrl == 1)
				cout << "[Info] ��ǰi��" << i << endl;
				
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
					cout << "[Info] ��ǰx��" << x << " H: " << H << " a[H]: " << a[H] << " a[x]: " << a[x] << " a[H]-a[x]: " << a[H] - a[x] << endl;
					
					mark = x;
					min = a[mark] - a[H] ;
				}

			}

			
			H = mark;
			cout << "\n\t����ţ�" << mark << "\n";
			cout << "\n\t����ֵ��" << a[mark] << "\n";
			cout << "\n\t��  �룺" << min << "\n";

			flag = 1;
			scIn = true;
			cout << "������ͷ����,��ֵ���ӵķ���\n\n";
			scan_in(H);
			
			return;
			
		}

		cout << "\n\t����ţ�" << mark << "\n";
		cout << "\t���ֵ��" << a[mark] << "\n";
		cout << "\t��  �룺" << min << "\n\n";


		a[H] = -1; 
		H = mark;

	}

}
