#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e6 + 10;
const int N1 = 5e3 + 10;
const int INF = 0x3f3f3f3f;

int n = 0;
LL d = 0;

int tar = 0;

int min_d = 0;
int cnt = 0;

LL x[N];

void dfs(int u, int ds)
{
	if(u == tar)
	{
		if(ds == min_d)
		{
			cnt++;
		}
		
		if(ds < min_d) 
		{
			min_d = ds;
			cnt = 1;
		}
		
		return;
	}
	
	for(int i = u + 1; i <= tar; i++)
	{
		if(x[i] - x[u] > d)
		{
			break;
		}
		
		dfs(i, ds + 1);
	}
	
	return;
}

int check(int u, int v) // 判断 (u, v) 是否双径 
{
	tar = v;
	min_d = INF;
	cnt = 0;
	
	dfs(u, 0);
	
	if(cnt == 2)
	{
		return 1;
	}
	
	return 0;
}

int sol_1()
{
	int res = 0;
	
	for(int u = 1; u <= n; u++)
	{
		for(int v = u + 1; v <= n; v++)
		{
			// 枚举 双径岛屿 (u, v)
			// 字面意思 u ~ v 有两条路 
			
			if(check(u, v) == 1)
			{
				res++;
			}
		}
	}
	
	return res;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	
	int c = 0;
	int t = 0;
	
	int res = 0;
	
	cin >> c >> t;
	
	while(t--)
	{
		cin >> n >> d;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		
		res = sol_1();
		
		cout << res << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
 } 
