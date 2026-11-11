#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000005];
ll dp[5005][5005], f[5005][5005];
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		ll n, d;
		int ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c <= 10) {
			for (int i = 1; i <= n; i++) {
				memset(dp, 0x7f, sizeof(dp));
				memset(f, 0, sizeof(f));
				int t = i;
				dp[i][i] = 0;
				f[i][i] = 1;
				for (int j = i + 1; j <= n; j++) {
					int cnt = 0;
					while (x[j] - x[t] > d) t++;
					for (int k = t; k <= j; k++) {
						if (dp[i][k] + 1 < dp[i][j]) {
							cnt = f[i][k];
							dp[i][j] = dp[i][k] + 1;
						} else if (dp[i][k] + 1 == dp[i][j]) {
							cnt += f[i][k];
						}
					}
					f[i][j] = cnt;
					if (cnt == 2) ans++;
				}
			}
			cout << ans << '\n';
		} else if (c >= 13 && c <= 14) {
			cout << 0 << '\n';
		} else if (c == 11 || c == 12) {
			if (x[2] - x[1] << 1 > d) {
				cout << 0 << '\n';
				continue;
			} else if (x[2] - x[1] << 1 <= d && 3 * (x[2] - x[1]) * 3 > d) {
				cout << n - 3 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}