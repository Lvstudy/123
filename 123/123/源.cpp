#include<iostream>
#include<time.h>
using namespace std;
#define N 100
int main()
{
	int n = 10;
	srand((unsigned)time(NULL));
	int  num, max, out, d, fushu, kh,  yushu;//����������жϣ���Ŀ���������ֵ�������ʽ���Ƿ��г˳����㣬�Ӽ����Ƿ��и���,��������,��������
	cout << "********�������������㶨�ư�+������********" << endl;
	cout << "��������Ŀ������num:" << endl;
	cin >> num;
	cout << "��ѡ����ֵ��Χ���ֵ(����0)" << endl;
	cin >> max;
	cout << "��ѡ���ӡ��ʽout��0���д�ӡ ,1�ո��ӡ��" << endl;
	cin >> out;
	cout << "��ѡ�����޳˳�����d��0û�г˳�����, 1�г˳����㣩" << endl;
	cin >> d;
	cout << "��ѡ��Ӽ��������޸���fushu��0û�и��� ,1�и�����" << endl;
	cin >> fushu;
	cout << "��ѡ���������ţ�0û������ ,1�����ţ�" << endl;
	cin >> kh;
	cout << "�����Ƿ���������0û��������1��������" << endl;
	cin >> yushu;
	for (int m = 0; m < num; m++)
	{
		int a = 2 + rand() % 4;
		int a1[N] = {};//������������
		int y;//������
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
		char b1[N] = {};//���������ķ���
		char b[4] = { '+', '-', '*', '/' };
		for (int i = 0; i < a - 1; i++)//�ж���������
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
				for (int i = 0; i < a - 1; i++)//�������
				{
					if (b1[i] == '/'&&b1[i + 1] == '/')//�������������ŷֿ�
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
			for (int i = 0; i < a - 1; i++)//�������
			{
				if (b1[i] == '/'&&b1[i + 1] == '/')//�������������ŷֿ�
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
		for (int i = 0; i < a - 1; i++)//�ݹ����
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
		cout << "��������ļ�����";
		cin >> s;
		if (s == y1)
		{
			cout << "�����ȷ" ;
		}
		else
		{
			cout << "���������ȷ��Ϊ" << y1<<"     " ;
		}
		if (out == 0)
		{
			cout << endl;
		}
	}

	return 0;
	}