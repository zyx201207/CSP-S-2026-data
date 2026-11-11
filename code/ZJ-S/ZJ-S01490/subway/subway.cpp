#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using p64 = std::pair<i64, i64>;
const i32 inf32 = 1e9;
const i64 inf64 = 2e18;
void solve();
signed main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
	while (T--) solve();
}
void solve() {
	i32 T, n, m, d, q;
	std::cin >> T >> n >> m >> d >> q;
	std::vector<i32> w(m + 2, 0), k(n + 2, 0);
	std::vector<std::vector<i32>> a(n + 2), t(n + 2);
	for (i32 i = 1; i <= m; i++) std::cin >> w[i];
	for (i32 i = 1; i <= n; i++) {
		std::cin >> k[i];
		a[i].resize(k[i] + 2), std::fill(a[i].begin(), a[i].end(), 0);
		t[i].resize(k[i] + 2), std::fill(t[i].begin(), t[i].end(), 0);
		for (i32 j = 1; j <= k[i]; j++) std::cin >> a[i][j] >> t[i][j];
	}
	std::vector<std::vector<i64>> g(n + 2, std::vector<i64>(n + 2, inf64));
	for (i32 i = 1; i <= n; i++) g[i][i] = 0;	
	std::vector<std::vector<p64>> G(m + 2);
	for (i32 i = 1; i <= n; i++) {
		for (i32 j = 1; j <= k[i]; j++) {
			i64 u = a[i][j], w1 = t[i][j];
			for (auto& [v, w2] : G[u]) {
				g[i][v] = std::min(g[i][v], w1 + w2);
				g[v][i] = std::min(g[v][i], w1 + w2);
			}
			G[u].push_back({i, w1});
		}
	}
	for (i32 kk = 1; kk <= n; kk++) 
		for (i32 i = 1; i <= n; i++) 
			for (i32 j = 1; j <= n; j++) 
				g[i][j] = std::min(g[i][j], g[i][kk] + g[kk][j]);
	for (i32 _ = 1, x, y; _ <= q; _++) {
		std::cin >> x >> y;
		i64 ans = inf64;
		for (auto& [u, w1] : G[x]) {
			for (auto& [v, w2] : G[y]) {
				ans = std::min(ans, w1 + w2 + g[u][v]);
			}
		}
		ans += w[x] + w[y];
		std::cout << ans << endl;
	}
	// BanG Dream! It's Floyd!!!!!
}
