#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int f[n + 5][m + 5], maxn = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int t = max(maxn, a[i]);
		maxn = t;
	}
	if (m == 1)
	{
		cout << maxn;
		return 0;
	}
	maxn = -1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			int t = max(maxn, (a[i] & a[j]));
			maxn = t;
		}
	}
	if (m == 2)
	{
		cout << maxn;
		return 0;
	}
	int mx = a[1];
	for (int i = 1; i <= n; i++)
	{
		int t = mx & a[i];
		mx = t;
	}
	if (m == n)
	{
		cout << mx;
		return 0;
	}
	for (int j = 3; j <= m; j++)
		for (int i = j; i <= n; i++)
			f[i][j] = max(f[i - 1][j], (f[i - 1][j - 1] & a[i]));
	cout << f[n][m];
	return 0;
}