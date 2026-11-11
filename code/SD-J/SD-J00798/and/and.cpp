#include <bits/stdc++.h>
using namespace std;

int n, m, ma = 0, ans;
int a[200010], b[200010];

void dfs(int c)
{
	if (c > m)
	{
		int k = a[b[1]];
		for (int i = 2;i <= m;i++)
		{
			k = k & a[b[i]];
			
		}
		ans = max(k, ans);
		return;
	}
	for (int i = b[c-1] + 1;i <= n;i++)
	{
		b[c] = i;
		dfs(c + 1);
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ma = max(a[i], ma);
	}
	if (m == 1)
	{
		cout << ma;
		return 0;
	}
	if (m == n)
	{
		ans = a[1];
		for (int i = 2;i <= n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == 2)
	{
		ans = 0;
		for (int i = 1;i < n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				ans = max(a[i] & a[j], ans);
			}
		}
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
