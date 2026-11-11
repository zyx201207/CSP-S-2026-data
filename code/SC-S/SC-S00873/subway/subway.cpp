#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using ll = long long;
constexpr int MAXN = 5e2 + 10;
constexpr int MAXM = 5e5 + 10;
constexpr int MAXQ = 1e5 + 10;
constexpr ll INF = 1e18;

int w[MAXM];
std::vector<std::pair<int, ll>> own[MAXM];

ll dis[MAXN][MAXN];

inline void solve() {
	int n, m, d, q;
	std::cin >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; j++) {
			int v, w;
			std::cin >> v >> w;
			own[v].push_back({i, w});
		}
	}
	
	std::memset(dis, 0x3f, sizeof dis);
	for (int u = 1; u <= m; u++) {
		for (const auto& d1 : own[u]) {
			for (const auto& d2 : own[u]) {
				int s1 = d1.first, s2 = d2.first;
				ll w1 = d1.second, w2 = d2.second;
				if (s1 == s2) dis[s1][s2] = 0;
				else {
					dis[s1][s2] = std::min(dis[s1][s2], w1 + w2);
					dis[s2][s1] = std::min(dis[s2][s1], w1 + w2);
				}
			}
		}
	}
	
	for (int u = 1; u <= n; u++) {
		dis[u][u] = 0;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				dis[u][v] = std::min(dis[u][v], dis[u][k] + dis[k][v]);
			}
		}
	}
	
	for (int i = 1; i <= q; i++) {
		int u, v;
		std::cin >> u >> v;
		
		ll res = INF;
		for (const auto& d1 : own[u]) {
			int s1 = d1.first;
			ll w1 = d1.second;
			for (const auto& d2 : own[v]) {
				int s2 = d2.first;
				ll w2 = d2.second;
				res = std::min(res, w1 + w2 + dis[s1][s2]);
			}
		}
		
		std::cout << res + w[u] + w[v] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int TestCase;
	std::cin >> TestCase;
	
	solve();
	
	return 0;
}