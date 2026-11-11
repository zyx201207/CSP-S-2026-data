#include <bits/stdc++.h>
using namespace std;
using uns = unsigned;
using ull = unsigned long long;
pair<uns, uns> g[500001][21];
uns cnt_g[500001], w[500001];
ull dp[501][501];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, 0x7f, sizeof dp);
	
	uns c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (uns i = 1; i <= m; ++i) cin >> w[i];
	for (uns i = 1; i <= n; ++i) {
		uns k;
		cin >> k;
		uns sta, tt;
		while (k--) {
			cin >> sta >> tt;
			for (uns j = 1; j <= cnt_g[sta]; ++j) dp[g[sta][j].first][i] = dp[i][g[sta][j].first] = 
				min(dp[i][g[sta][j].first], ull(g[sta][j].second + tt));
			g[sta][++cnt_g[sta]] = { i, tt };
		}
	}
	for (uns i = 0; i < 501; ++i) dp[i][i] = 0;
	for (uns k = 1; k <= n; ++k) for (uns i = 1; i <= n; ++i) for (uns j = 1; j <= n; ++j) 
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	
	while (q--) {
		uns x, y;
		cin >> x >> y;
		ull ans = 0xffffffffffffffffull;
		for (uns i = 1; i <= cnt_g[x]; ++i) {
			for (uns j = 1; j <= cnt_g[y]; ++j) {
				ans = min(ans, g[x][i].second + g[y][j].second + dp[g[x][i].first][g[y][j].first]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	
	return 0;
}
