#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 5e5 + 5, M = 505;
vector<pair<int, int> > g[N];
int w[N], a[M][M], t[M][M];
long long dp[M][M];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dp, 0x3f, sizeof(dp));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0];
		for (int j = 1; j <= a[i][0]; j++) {
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back({t[i][j], i});
		}
		dp[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < g[i].size(); j++) {
			for (int k = 0; k < j; k++) {
				dp[g[i][j].second][g[i][k].second] = min(dp[g[i][j].second][g[i][k].second], (long long)g[i][j].first + g[i][k].first);
				dp[g[i][k].second][g[i][j].second] = min(dp[g[i][j].second][g[i][k].second], (long long)g[i][j].first + g[i][k].first);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	while (q--) {
		int x, y;
		long long ans = LONG_LONG_MAX;
		cin >> x >> y;
		for (pair<int, int> i : g[x]) {
			for (pair<int, int> j : g[y]) {
				ans = min(ans, dp[i.second][j.second] + i.first + j.first);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
5 10
-10 -9 -8 -7 -6
*/
