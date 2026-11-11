#include <bits/stdc++.h>

const int N = 505;
const int M = 5e5 + 5;
using ll = long long;

int c, n, m, d, q, w[M];
std::vector <std::pair <int, int>> s[M];
ll dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) std::cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k; std::cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t; std::cin >> a >> t;
			s[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	for (int i = 1; i <= m; i ++) {
		for (size_t x = 0; x < s[i].size(); x ++) {
			for (size_t y = x + 1; y < s[i].size(); y ++) {
				int u = s[i][x].first, v = s[i][y].first;
				ll tu = s[i][x].second, tv = s[i][y].second;
				dis[u][v] = std::min(dis[u][v], tu + tv);
				dis[v][u] = std::min(dis[v][u], tu + tv);
			}
		}
	}
	
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while (q --) {
		int x, y; std::cin >> x >> y;
		ll ans = LLONG_MAX;
		for (size_t i = 0; i < s[x].size(); i ++) {
			for (size_t j = 0; j < s[y].size(); j ++) {
				int u = s[x][i].first, v = s[y][j].first;
				ll tu = s[x][i].second, tv = s[y][j].second;
				ans = std::min(ans, w[x] + tu + dis[u][v] + tv + w[y]);
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}