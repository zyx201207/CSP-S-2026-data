#include <iostream>
#include <cstdio>
#include <bits/stdc++.h> 
using namespace std;

const int N = 5e5 + 10;

int n = 0;
int m = 0;

int a[N];

int ans[N];

int flg[N];
int idx[N];

int ord[N];

void sol_1()
{
	int cnt = 0;
	
	for(int i = 1; i <= n; i++) // 第 i 局 
	{
		cnt = 0;
		
		for(int j = i; j <= n; j++)
		{
			if(flg[ a[j] ] != i) // 第 i 局桌面上没有 
			{
				cnt++;
				ord[cnt] = a[j];
				
				flg[ a[j] ] = i;
				idx[ a[j] ] = cnt; // idx[j] => j 排 上一次的 位置 
			}
			else // 桌面上有 
			{
				for(int p = idx[a[j]] + 1; p <= cnt; p++)
				{
					flg[ ord[p] ] = 0;
				}
				
				cnt = idx[ a[j] ]; // 收走
			}
		}
		
		for(int i = 1; i <= cnt; i++)
		{
			ans[ord[i]]++;
		}
	}
	
	return;
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if(n <= 5000)
	{
		sol_1();
	}
	else
	{
		sol_1();
	}
	
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
