#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int)2e6 + 11, M = 311;
int n, f[M][M], dp[M][M];
ll D, a[N];

inline void solve() {
	scanf("%d%lld", &n, &D);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i > 1 && a[i] - a[i - 1] <= D)
			dp[i - 1][i] = 1, f[i][i + 1] = 1;
		else
			dp[i - 1][i] = n + 1;
		dp[i][i] = 0, f[i][i] = 1;
	}
	ll res = 0;
	for (int d = 2; d < n; d++)
		for (int i = 1; i <= n - d; i++) {
			int j = i + d;
			dp[i][j] = n + 1, f[i][j] = 0;
			for (int k = j - 1; k >= i && a[j] - a[k] <= D; k--)
				if (dp[i][k] + 1 < dp[i][j])
					dp[i][j] = dp[i][k] + 1, f[i][j] = f[i][k];//, printf("%d->%d->%d\n", i, k, j);
				else if (dp[i][k] + 1 == dp[i][j]) {
					f[i][j] += f[i][k];
					if (f[i][j] > 2)
						f[i][j] = 3;
//					printf("== %d %d %d\n", i, k, j);
				}
//			printf("dp[%d][%d]=%d f[%d][%d]=%d\n", i, j, dp[i][j], i, j, f[i][j]);
			if (f[i][j] == 2)
				++res;//, printf("%d %d\n", i, j);
		}
	printf("%lld\n", res);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	scanf("%d%d", &C, &T);
	while (T--)
		solve();
	return 0;
}
