#include <bits/stdc++.h>

using namespace std;

const int N = 500010, M = 510, K = 3010;

int c, n, m, d, q, w[N], k[M], a[M][1010], t[M][1010];
long long f[K][K];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= n; j ++ )
		{
			f[i][j] = 1e18;
			if (i == j) f[i][i] = 0;
		}
	}
	for (int i = 1; i <= m; i ++ )
	{
		scanf("%d", &w[i]);
		f[i][i + m] = w[i];
		f[i + m][i] = w[i];
	}
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j ++ )
		{
			scanf("%d%d", &a[i][j], &t[i][j]);
			f[a[i][j] + m][i + m + m] = t[i][j];
			f[i + m + m][a[i][j] + m] = t[i][j];
		}
		for (int j = 1; j <= k[i]; j ++ )
		{
			for (int l = j + 1; l <= k[i]; l ++ )
			{
				f[a[i][j] + m][a[i][l] + m] = 0;
				f[a[i][l] + m][a[i][j] + m] = 0;
			}
		}
	}
	int sum = 2 * m + n;
	for (int k = 1; k <= sum; k ++ )
	{
		for (int i = 1; i <= sum; i ++ )
		{
			for (int j = 1; j <= sum; j ++ )
			{
				if (f[i][k] != 1e18 && f[k][j] != 1e18)
				{
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= q; i ++ )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", f[x][y]);
	}
	return 0;
}
