#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005], f[2000005], dp[2000005];
void solve() {
	int n, d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int u = 1; u <= n; u++) {
		for (int i = 1; i <= n; i++) f[i] = 1e18, dp[i] = 0;
		f[u] = 0, dp[u] = 1;
		for (int i = u + 1; i <= n; i++) {
			for (int j = i - 1; j >= u; j--) {
				if (x[i] - x[j] > d) break;
				int nw = f[j] + 1;
				if (nw < f[i]) {
					f[i] = nw;
					dp[i] = dp[j];
				}
				else if (nw == f[i]) dp[i] += dp[j];
			}
		}
		for (int i = 1; i <= n; i++) ans += (f[i] < 1e18 && dp[i] == 2);
	}
	cout << ans << "\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
} 
