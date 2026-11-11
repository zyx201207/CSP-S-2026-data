#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll x[5005], mn[5005][5005], cnt[5005][5005], n, d;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while (T--)
	{
		memset(mn, 0x3f, sizeof(mn));
		memset(cnt, 0, sizeof(cnt));
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				if (x[j] - x[i] <= d)
					mn[i][j] = 1, cnt[i][j] = 1;
		for (int l = 1; l <= n; l++)
		{
			for (int i = 1; i + l - 1 <= n; i++)
			{
				int j = i + l - 1;
				if (cnt[i][j] != 0)
					continue;
				for (int k = i + 1; k < j; k++)
				{
					if (mn[i][j] > mn[i][k] + mn[k][j])
						cnt[i][j] = cnt[i][k] * cnt[k][j], mn[i][j] = mn[i][k] + mn[k][j];
					else if (mn[i][j] == mn[i][k] + mn[k][j])
						cnt[i][j] += cnt[i][k] * cnt[k][j];
					cnt[i][j] = min(cnt[i][j], 3ll);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				if (cnt[i][j] == 2)
					ans++;
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/