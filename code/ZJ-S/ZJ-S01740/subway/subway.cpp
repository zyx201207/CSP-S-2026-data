#include <bits/stdc++.h>
#define ll long long
const int N = 2e6 + 5;
const ll INF = 1e17;
int c, n, m, d, q;
ll dis[502][502], w[N];
std::vector<std::pair<int, ll>> adj[N];
int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		std::cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k; std::cin >> k;
		for (int j = 1; j <= k; ++j) {
			int l; ll t;
			std::cin >> l >> t;
			adj[l].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = (i == j ? 0 : INF);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (std::pair<int, ll> v : adj[i]) {
			for (std::pair<int, ll> w : adj[i]) {
				int x, y; ll t1, t2;
				std::tie(x, t1) = v, std::tie(y, t2) = w;
				dis[x][y] = std::min(dis[x][y], t1 + t2);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int i, j; std::cin >> i >> j;
		ll ans = INF;
		for (std::pair<int, ll> v : adj[i]) {
			for (std::pair<int, ll> w : adj[j]) {
				int x, y; ll t1, t2;
				std::tie(x, t1) = v, std::tie(y, t2) = w;
				ans = std::min(ans, dis[x][y] + t1 + t2);
			}
		}
		std::cout << ans + w[i] + w[j] << "\n";
	}
}