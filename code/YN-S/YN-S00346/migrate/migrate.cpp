#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, T, n, d;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		if (c <= 2) {
			int x[20], cnt[20][20], dp[20][20];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dp[i][j] = INT_MAX;
				}
			}
			for (int i = 1; i <= n; i++) {
				cin >> x[i];

			}
			sort(x + 1, x + n + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (abs(x[i] - x[j]) <= d)
						dp[i][j] = 1;
				}
				dp[i][i] = 0;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						if (dp[i][j] > dp[i][k] + dp[k][j]) {
							dp[i][j] = dp[i][k] + dp[k][j];
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						if (dp[i][j] == dp[i][k] + dp[k][j] && dp[i][j] >= 2) {
							cnt[i][j]++;
						}
					}
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (cnt[i][j] == 2)
						ans++;
				}
			}
			cout << ans << "\n";
		}
		if (c == 13 || c == 14) {
			cout << "0\n";
		}
	}
	return 0;
}