#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n, m, ans;
int a[maxn];

void dfs (int f, int cnt, int sum)
{
	if (cnt == m)
	{
		ans = max(sum, ans);
		return ;
	}
	if (f == n + 1 && cnt < m) return ;
	
	dfs(f + 1, cnt + 1, sum & a[f]);
	dfs(f + 1, cnt, sum);
}

int main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	
	if (n <= 20) // 1 ~ 5
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		dfs(1, 0, INT_MAX);
	}
	else if (m == 1) // 6
	{
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			ans = max(ans, a[i]);
		}
	}
	else if (m == n) // 7
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			ans &= a[i];
		}
	else if (m == 2) // 8 ~ 10
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
					ans = max(ans, a[i] & a[j]);
	}
	cout << ans;
	return 0;
}

