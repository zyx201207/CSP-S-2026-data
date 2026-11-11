#include <bits/stdc++.h>
using namespace std;
long long m, a[50010], f[10010][10010], t[10010][10010];
int n, ans = -1e9;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("dp.out", "w", stdout);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	memset(f, 1e9, sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 0, t[i][i] = a[i];
	for (int len = 0; len <= n; len++)
	{
		for (int i = 1; i <= n; i++)
		{
			int j = i + len;
			if (j > n) break;
			if (a[j + 1] > t[i][j])
			{
				int x = (len + 1) * (a[j + 1] - t[i][j]);
				f[i][j + 1] = max(f[i][j + 1], f[i][j] + x);
				t[i][j + 1] = a[j + 1];
			}
			else
			{
				int x = t[i][j] - a[j + 1];
				f[i][j + 1] = max(f[i][j + 1], f[i][j] + x);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (f[i][j] <= m) ans = max(ans, j - i + 1);
		}
	}
	printf("%d", ans);
	return 0;
}