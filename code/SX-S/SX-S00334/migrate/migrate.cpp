#include <bits/stdc++.h>
#define re register
#define l long long
#define rl re l
using namespace std;

l c, t, n, d, a[2000006], dp[5006][5006], dd[5006][5006];

void mian() {
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (l i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c <= 6) {
			l ans = 0;
			for (l i = 1; i <= n; i++) {
				dp[i][i] = 0;
				dd[i][i] = 0;
				for (l j = i + 1; j <= n; j++) {
					dp[i][j] = 1e12;
					dd[i][j] = 0;
				}
			}
			for (l i = 1; i <= n; i++) {
				for (rl j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d) {
						dp[i][j] = 1;
						dd[i][j] = 1;
					}
				}
			}
			for (l i = 1; i <= n; i++) {
				for (l j = i + 1; j <= n; j++) {
					for (l k = i + 1; k < j; k++) {
						if (dp[i][j] > dp[i][k] + dp[k][j]) {
							dd[i][j] = 1;
							dp[i][j] = dp[i][k] + dp[k][j];
						} else if (dp[i][j] == dp[i][k] + dp[k][j]) {
							dd[i][j]++;
						}
					}
				}
			}
			for (l i = 1; i <= n; i++) {
				for (l j = i + 1; j <= n; j++) {
					if (dd[i][j] == 2) {
						ans++;
					}
				}
			}
			printf("%lld\n", ans);
		} else {
			printf("0\n");
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	mian();
	return 0;
}
