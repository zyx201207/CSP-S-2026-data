#include<bits/stdc++.h>
using namespace std;
int n, a[200010], m, ans, flag = 1, maxa;
void dfs(int t, int cnt, int y)
{
	if(t > n + 1) return;
	if(y == m)
	{
		ans = max(ans, cnt);
	}
	dfs(t + 1, cnt, y);
	if(cnt == 0 && flag == 1)
	{
		flag = 0;
		dfs(t + 1, a[t], y + 1);
		flag = 1;
	}
	else
	{
		dfs(t + 1, cnt & a[t], y + 1);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	if(n <= 20)
	{
		dfs(1, 0, 0);
		cout << ans;
	}
	else if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			ans = max(ans, a[i]);
		}
		cout << ans;
	}
	else if(m == n)
	{
		ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			ans &= a[i];
		}
		cout << ans;
	}
	else if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	}	
	return 0;
}