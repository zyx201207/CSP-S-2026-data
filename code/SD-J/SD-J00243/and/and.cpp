#include <iostream>
#include <cstdio>
#include <bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 10;
const int LOGN = 30;
const int NG = -1;
const int N1 = 5e3 + 10; 

int a[N];

int memo[N1][N1];

int n = 0;
int m = 0;

int max_res = 0;

bool cmp(int a, int b)
{
	return a > b;
}

void dfs(int idx, int cnt, int num)
{	
	if(cnt == m)
	{
		max_res = max(max_res, num);
		return;
	}
	
	if(idx == n + 1)
	{
		return;
	}
	
	dfs(idx + 1, cnt, num); // 不选 
	
	dfs(idx + 1, cnt + 1, num & a[idx]);
	
	return;
}

int dfs1(int idx, int cnt)
{
	int res = 0;
	
	int tmp1 = 0;
	int tmp2 = 0;
	
	if(cnt == m)
	{
		return NG;
	}
	
	if(idx == n + 1)
	{
		return 0;
	}
	
	if(memo[idx][cnt] != NG)
	{
		return memo[idx][cnt];
	}
	
	tmp1 = dfs1(idx + 1, cnt); // 不选 
	
	tmp2 = dfs1(idx + 1, cnt + 1); // 选 
	
	if(tmp2 == NG)
	{
		tmp2 = a[idx];
	}
	else
	{
		tmp2 &= a[idx];
	}
	
	res = max(tmp1, tmp2);
	
	memo[idx][cnt] = res;
	
	return res;
}

int sol_a()
{
	sort(a + 1, a + 1 + n);
	
	for(int i = n; i >= 1; i++)
	{
		if(a[i] == a[i - 1])
		{
			return a[i];
		}
	}
	
	return 0;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	int res = 0; 
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if(n <= 20)
	{
		for(int i = 1; i <= n; i++)
		{
			dfs(i + 1, 1, a[i]);
		}
		
		cout << max_res << endl;
	}
	else if(n <= 2000)
	{
		memset(memo, NG, sizeof(memo));
		
		res = dfs1(1, 0);
		
		cout << res << endl;
	}
	else
	{
		res = sol_a();
		
		cout << res << endl; 
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
