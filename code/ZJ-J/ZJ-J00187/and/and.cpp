#include<bits/stdc++.h>
using namespace std;

int a[200005], n, m;
int ans = 0;

void dfs(int idx, int k, int used)
{
	if(used == m)
	{
		ans = max(ans, k);
		return;
	}
	for(int i = idx + 1; i + m - used - 1 <= n; ++ i)
	{
		dfs(i, (k & a[i]), used+1);
	}
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		for(int i = 1; i <= n; ++ i)
		{
			ans = max(ans, a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	if(m == n)
	{ 	
		ans = a[1];
		for(int i = 2; i <= n; ++ i)
		{
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if(n <= 25)
	{
		for(int i = 1; i <= n; ++ i)
		{
			dfs(i, a[i], 1);
		}
		cout << ans << endl;
		return 0;
	}
	if(m == 2)
	{
		int cnt = 0;
		for(int i = 1; i <= n; ++ i)
		{
			for(int j = i + 1; j <= n; ++ j)
			{
				ans = max(ans, a[i] & a[j]);
				++ cnt;
				if(cnt >= 80000000)
				{
					cout << ans << endl;
					return 0;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	ans = a[n];
	for(int i = 1; i <= m; ++ i)
	{
		ans &= a[i];
	}
	cout << ans << endl;
	return 0;
}