#include <iostream>
#include <vector>
#include <algorithm>

int cnt = 0;
int head[501] = {};
std::vector<std::pair<int, int>> link[500001] = {};
long long extra[500001] = {};
long long dist[501][501] = {};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int test = 0;
	int n = 0;
	int m = 0;
	int d = 0;
	int q = 0;
	std::cin >> test >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		std::cin >> extra[i];
	}
	for (int i = 1; i <= n; ++i) {
		int k = 0;
		std::cin >> k;
		for (int j = 0; j < k; ++j) {
			int x = 0;
			long long v = 0;
			std::cin >> x >> v;
			link[x].emplace_back(i, v);
		}
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				dist[i][j] = 1e18;
			}
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		for (const auto& p : link[i]) {
			for (const auto& u : link[i]) {
				dist[p.first][u.first] = std::min(dist[p.first][u.first], (long long)p.second + u.second);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	while (q--) {
		int x = 0;
		int y = 0;
		long long ans = 1e18;
		std::cin >> x >> y;
		
		for (const auto& i : link[x]) {
			for (const auto& j : link[y]) {
				ans = std::min(ans, dist[i.first][j.first] + i.second + j.second);
			}
		}
		
		std::cout << ans + extra[x] + extra[y] << '\n';
	}
	
	return 0;
}