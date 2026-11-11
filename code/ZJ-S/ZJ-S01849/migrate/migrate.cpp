#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 305;

int n, dp[N][N], cnt[N][N];
ll d, x[N];

inline void solve()
{
	scanf("%d %lld", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i + 1; j++)
		{
			dp[j][j + i] = N;
			cnt[j][j + i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i + 1; j++)
		{
			if (x[j + i] - x[j] <= d)
			{
				dp[j][j + i] = 1;
				continue;
			}
			for (int k = j + 1; k < j + i; k++)
			{
				if (dp[j][k] >= N || dp[k][j + i] >= N) continue;
				if (dp[j][j + i] > dp[j][k] + dp[k][j + i])
				{
					dp[j][j + i] = dp[j][k] + dp[k][j + i];
					cnt[j][j + i] = 1;
				}
				else if (dp[j][j + i] == dp[j][k] + dp[k][j + i]) cnt[j][j + i]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) if (cnt[i][j] == dp[i][j]) ans++;
	printf("%d\n", ans);
	return ;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; scanf("%d %d", &c, &t);
	while (t--) solve();
	return 0;
}
