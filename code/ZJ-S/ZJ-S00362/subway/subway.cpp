#include <bits/stdc++.h>

using i64 = long long;

namespace Qwarth {

const int N = 507;
const int M = 500007;
const int D = 27;
const i64 INF = 1e18;

int _c, n, m, d, q;
i64 w[M];
//std::vector< std::pair< int, int > > G[N];
int t[M];
std::pair< int, i64 > g[M][D];
i64 ans;
i64 dis[N][N];
//bool vis[N], Vis[M];

//void dfs(int u, int e, i64 s) {
//	if (u == e) {
//		ans = std::min(ans, s + w[u]);
//		return;
//	}
//	if (s >= ans) {
//		return;
//	}
//	for (int i = 1; i <= t[u]; ++i) {
//		auto [x, xw] = g[u][i];
//		if (vis[x]) {
//			continue;
//		}
//		vis[x] = 1;
//		for (auto [v, w] : G[x]) {
//			if (Vis[v]) {
//				continue;
//			}
//			Vis[v] = 1;
//			dfs(v, e, s + xw + w);
//			Vis[v] = 0;
//		}
//		vis[x] = 0;
//	}
//}

void main() {
	std::cin >> _c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		std::cin >> w[i];
	}
	for (int i = 1, k; i <= n; ++i) {
		std::cin >> k;
		for (int j = 1, x, y; j <= k; ++j) { 
			std::cin >> x >> y;
//			G[i].push_back({ x, y });
			g[x][++t[x]] = { i, y };
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dis[i][j] = dis[j][i] = INF;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int u = 1; u < t[i]; ++u) {
			for (int v = u + 1; v <= t[i]; ++v) {
//				auto [x, xw] = g[i][u];
//				auto [y, yw] = g[i][v];
				int x = g[i][u].first;
				i64 xw = g[i][u].second;
				int y = g[i][v].first;
				i64 yw = g[i][v].second;
				dis[x][y] = dis[y][x] = std::min(dis[x][y], xw + yw);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (i == k) {
				continue;
			}
			for (int j = 1; j <= n; ++j) {
				if (i == j || k == j) {
					continue;
				}
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		ans = INF;
		for (int i = 1; i <= t[x]; ++i) {
			for (int j = 1; j <= t[y]; ++j) {
//				auto [u, uw] = g[x][i];
//				auto [v, vw] = g[y][j];
				int u = g[x][i].first;
				i64 uw = g[x][i].second;
				int v = g[y][j].first;
				i64 vw = g[y][j].second;
				ans = std::min(ans, uw + dis[u][v] + vw);
			}
		}
		ans += w[x] + w[y];
//		Vis[x] = 1;
//		dfs(x, y, w[x]);
//		Vis[x] = 0;
		std::cout << ans << '\n';
	}
}
}  // namespace Qwarth

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int _T = 1;
//	std::cin >> _T;
	while (_T--) {
		Qwarth::main();
	}
	return 0;
}
