#include<iostream>
#include<time.h>
using namespace std;
#define N 100
int main()
{
	int n = 10;
	srand((unsigned)time(NULL));
	int  num, max, out, d, fushu, kh,  yushu;//有无真分数判断，题目数量，最大值，输出方式，是否有乘除运算，加减法是否有负数,有无括号,有无余数
	cout << "********二柱子四则运算定制版+升级版********" << endl;
	cout << "请输入题目的数量num:" << endl;
	cin >> num;
	cout << "请选择数值范围最大值(大于0)" << endl;
	cin >> max;
	cout << "请选择打印方式out（0空行打印 ,1空格打印）" << endl;
	cin >> out;
	cout << "请选择有无乘除运算d（0没有乘除运算, 1有乘除运算）" << endl;
	cin >> d;
	cout << "请选择加减运算有无负数fushu（0没有负数 ,1有负数）" << endl;
	cin >> fushu;
	cout << "请选择有无括号（0没有括号 ,1有括号）" << endl;
	cin >> kh;
	cout << "除法是否有余数（0没有余数，1有余数）" << endl;
	cin >> yushu;
	for (int m = 0; m < num; m++)
	{
		int a = 2 + rand() % 4;
		int a1[N] = {};//存运算的随机数
		int y;//运算结果
		for (int i = 0; i < a; i++)
		{
			int b = 1 + rand() % max;
			a1[i] = b;
		}
		if (fushu == 1)
		{
			int v = rand() % 2;
			if (v == 1)
			{
				a1[0] = -a1[0];
			}
			
		}
		char b1[N] = {};//存进行运算的符号
		char b[4] = { '+', '-', '*', '/' };
		for (int i = 0; i < a - 1; i++)//判断连续除法
		{
			if (d == 0)
			{
				int d = rand() % 2;
				b1[i] = b[d];
			}
			else
			{
				int d = rand() % 4;
				b1[i] = b[d];
				if (d == 3)
				{
					int c = rand() % 10 + 1;
					if (yushu == 0)
					{
						a1[i] = a1[i + 1] * c;
					}
					
					if (b1[i - 1] == '/')
					{
						a1[i] = a1[i + 1] * c;
						int c1 = rand() % 10 + 1;
						a1[i - 1] = a1[i] * a1[i + 1] * c1;
					}
				}
				for (int i = 0; i < a - 3; i++)
				{
					if (b1[i] == b1[i + 1] == b1[i + 2] == '/')
					{
						b1[i] = '+';
					}
					if (b1[i] == b1[i + 1] == b1[i + 2] == b1[i + 3] == '/')
					{
						b1[i + 3] = '-';
					}
				}
			}
		
		}
		if (kh == 1)
		{
			int n = rand() % 2;
			if (n == 1)
			{
				for (int i = 0; i < a - 1; i++)//输出运算
				{
					if (b1[i] == '/'&&b1[i + 1] == '/')//连续除法用括号分开
					{
						cout << '(' << a1[i] << b1[i];

					}
					else
					if (b1[i] == '/'&&b1[i - 1] == '/'&&i>0)
					{
						cout << a1[i] << ')' << b1[i];
					}

					else
					{
						int e = rand() % 10;
						a1[i] = a1[i] + e;
						cout << '(' << a1[i] << '+' << e << ')' << b1[i];
					}

				}
				cout << a1[a - 1] << '=' << "   ";
			}
			
		}
		else
		{
			for (int i = 0; i < a - 1; i++)//输出运算
			{
				if (b1[i] == '/'&&b1[i + 1] == '/')//连续除法用括号分开
				{
					cout << '(' << a1[i] << b1[i];

				}
				else
				if (b1[i] == '/'&&b1[i - 1] == '/'&&i>0)
				{
					cout << a1[i] << ')' << b1[i];
				}

				else
					cout << a1[i] << b1[i];
			}
			cout << a1[a - 1] << '=' << "   ";
		}
		y = a1[0];
		for (int i = 0; i < a - 1; i++)
		{
			int y = 0;

			if (b1[i] == '/'&&b1[i + 1] == '/')
			{
				y = a1[i] / a1[i + 1] / a1[i + 2];
				a1[i] = y;
				a1[i + 1] = 0;
				a1[i + 2] = 0;
				b1[i] = b1[i + 1] = '+';

			}
			else
			if (b1[i] == '/'&&b1[i + 1] == '*')
			{
				y = a1[i] / a1[i + 1] * a1[i + 2];
				a1[i] = y;
				a1[i + 1] = 0;
				a1[i + 2] = 0;;
				b1[i] = b1[i + 1] = '+';

			}
			else
			if (b1[i] == '*'&&b1[i + 1] == '/')
			{
				y = a1[i] * a1[i + 1] / a1[i + 2];
				a1[i] = y;
				a1[i + 1] = 0;
				a1[i + 2] = 0;
				b1[i] = b1[i + 1] = '+';

			}
			else
			if (b1[i] == '*'&&b1[i + 1] == '*')
			{
				y = a1[i] * a1[i + 1] * a1[i + 2];
				a1[i] = y;
				a1[i + 1] = 0;
				a1[i + 2] = 0;
				b1[i] = b1[i + 1] = '+';

			}
			else
			if (b1[i] == '/')
			{
				y = a1[i] / a1[i + 1];
				a1[i] = y;
				a1[i + 1] = 0;
				b1[i] = '+';

			}
			else
			if (b1[i] == '*')
			{
				y = a1[i] * a1[i + 1];
				a1[i] = y;
				a1[i + 1] = 0;
				b1[i] = '+';

			}

		}
		int y1 = a1[0];
		for (int i = 0; i < a - 1; i++)//递归计算
		{
			if (b1[i] == '+')
			{
				y1 = y1 + a1[i + 1];

			}
			else
			if (b1[i] == '-')
			{
				y1 = y1 - a1[i + 1];

			}
			else
			if (b1[i] == '*')
			{
				y1 = y1 * a1[i + 1];

			}
			else
			if (b1[i] == '/')
			{
				y1 = y1 / a1[i + 1];

			}

		}
		int s;
		cout << "请输入你的计算结果";
		cin >> s;
		if (s == y1)
		{
			cout << "结果正确" ;
		}
		else
		{
			cout << "结果错误，正确答案为" << y1<<"     " ;
		}
		if (out == 0)
		{
			cout << endl;
		}
	}

	return 0;
	}