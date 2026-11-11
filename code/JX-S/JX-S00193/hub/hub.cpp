#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 5;

int c, test_case, n, k, u, v, bel[N], cur = 0, ans = 1 << 30;
int dist[N];
bool vis[N];
std::vector<int> adj[N];
std::vector<std::pair<int, int>> edges;

inline void dfs(int u, int tot) {
	if (u > n) {
		if (tot != k) return;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (auto [u, v] : edges) if (bel[u] != bel[v]) adj[u].push_back(v), adj[v].push_back(u);
		std::queue<int> q;
		std::memset(dist, 0, sizeof(dist));
		std::memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			if (!bel[i]) continue;
			q.push(i), dist[i] = 0, vis[i] = true;
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v : adj[u]) {
				if (!vis[v]) dist[v] = dist[u] + 1, q.push(v);
			}
		}

		cur = 0;
		for (int i = 1; i <= n; i++) cur = std::max(cur, dist[i]);
		ans = std::min(ans, cur);
		return;
	}
	
	bel[u] = 0, dfs(u + 1, tot);
	if (tot + 1 <= k) bel[u] = 1, dfs(u + 1, tot + 1);
	if (tot + 1 <= k) bel[u] = 2, dfs(u + 1, tot + 1);
	bel[u] = 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::freopen("hub.in", "r", stdin);
	std::freopen("hub.out", "w", stdout);

	std::cin >> c >> test_case;

	while (test_case--) {
		std::cin >> n >> k;
		
		edges.clear();
		for (int i = 1; i < n; i++) {
			std::cin >> u >> v;
			edges.push_back({u, v});
		}
		ans = 1 << 30;
		dfs(1, 0);

		std::cout << ans << "\n";
	}

	return 0;
}
