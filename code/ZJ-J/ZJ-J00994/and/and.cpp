#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n, m;
int ans;
void dfs(int step, int val, int now)
{
	if(now == m)
	{
		ans = max(ans, val);
		return;
	}
	if(step > n)
	{
		return;
	}
	dfs(step + 1, val & a[step], now + 1);
	dfs(step + 1, val, now);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n < 30)
	{
		dfs(1, INT_MAX, 0);
		cout << ans;
		return 0;
	}
	int ans1 = INT_MAX;
	if(n == m && m != 1 && m != 2)
	{
		for(int i = 1; i <= n; i++)
		{
			ans1 &= a[i];
		}
		cout << ans1;
		return 0;
	}
	int ans2 = 0;
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			ans2 = max(a[i], ans2);
		}
		cout << ans2;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans2 = max(a[i] & a[j], ans2);
			}
		}
		cout << ans2;
		return 0;
	}
	if(m == n - 1)
	{
		for(int i = 1; i <= n; i++)
		{
			int temans = INT_MAX;
			for(int j = 1; j <= n; j++)
			{
				if(i != j)
				{
					temans &= a[j];
				}
			}
			ans2 = max(temans, ans1);
		}
		cout << ans2;
		return 0;
	}
	cout << 1;
	return 0;
}
