#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 2;



/*
int search_far(int x[N], int d, int n, int start = 0)
{
	cout << "[debug]数据获取成功 " << d << " " << n << endl;
	// first, check da longest first step
	int flag = 0, best = 0;
	for(int i = 0; flag != 1; i++)
	{	
		cout << "[debug]第 " << i << " 次尝试" << endl; 
		int x_bird = start;
		if (abs(x[i]-x_bird) <= d)
		{
			best = x[i];
			cout << "[debug]第 " << i << " 次尝试，best为" << best << endl; 
		}
		else
		{
			flag = 1;
			cout << "[debug]最大为 " << best << " ，循环中断\n";
			break;
		}
	}
	cout << "循环结束，flag为 " << flag << endl << " Next: \n\n";
	
	for (int i = 0;)	
	
}*/

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	//...
	int c = 0, t = 0;
	cin >> c >> t;
	for (int ww = 0; ww < t; ww++)
	{
		//cout << "[debug] 输入第 " << ww << " 组数据 : \n";
		int n = 0, d = 0;
		cin >> n >> d;
		int x[n+1] = {};
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		int L_list[n+1] = {};
		// debug: draw number line
		/*cout << "[debug] 获取到 " << n << " 座岛屿，最大飞行距离为 " << d << " 。\n |";
		for (int i = 0; i < n; i++)
		{
			for (int j = x[i-1]; j < x[i]; j++)
			{
				cout << "____";
			}
			cout << "|";
		}
		cout << endl;
		*/
		// search step
		// int best_step = search_far(x, d, n);
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			L_list[i] = abs(x[i]-x[i-1]);
			cout << L_list[i] << endl;
			if (L_list[i] > d)
			{
				cout << "0" << endl;
				break; flag = 1;
			}
		}
		
		if (flag == 0)
		{
			
		}
		
	}
	
	return 0;
}
