#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 505;
constexpr int M = 5e5 + 5;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
i64 dist[N][N], w[M];
std::vector<int> a[N], t[N];
std::vector<std::pair<int, int>> sta[M];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

  std::freopen("subway.in", "r", stdin);
  std::freopen("subway.out", "w", stdout);

	std::cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) std::cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; std::cin >> k;
		a[i].resize(k), t[i].resize(k);
		for (int j = 0; j < k; j++)
			std::cin >> a[i][j] >> t[i][j], sta[a[i][j]].push_back({i, t[i][j]});
	}

	std::memset(dist, INF, sizeof(dist));
	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int i = 1; i <= m; i++) {
		for (int x = 0; x < (int) sta[i].size(); x++) {
			for (int y = 0; y < (int) sta[i].size(); y++) {
				if (x == y) continue;
				int xp = sta[i][x].first, xt = sta[i][x].second;
				int yp = sta[i][y].first, yt = sta[i][y].second;
				dist[xp][yp] = std::min(dist[xp][yp], (i64) xt + yt);
				dist[yp][xp] = std::min(dist[yp][xp], (i64) xt + yt);
			}
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

	while (q--) {
		int u, v; std::cin >> u >> v;

		i64 ans = INF;
		for (int i = 0; i < (int) sta[u].size(); i++)
			for (int j = 0; j < (int) sta[v].size(); j++)
				ans = std::min(ans, w[u] + w[v] + sta[u][i].second + sta[v][j].second + dist[sta[u][i].first][sta[v][j].first]);

		std::cout << ans << "\n";
	}


	return 0;
}
