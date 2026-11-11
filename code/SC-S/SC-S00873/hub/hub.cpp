#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

constexpr int MAXN = 10 + 5;

std::vector<int> G[MAXN];
int vis[MAXN];
int up[MAXN], dep[MAXN];

void dfs(int u, int fa) {
	up[u] = fa;
	dep[u] = dep[fa] + 1;
	for (int v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}

inline int LCA(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	while (dep[u] > dep[v]) u = up[u];
	if (u == v) return u;
	while (u != v) u = up[u], v = up[v];
	return u;
}

inline int dis(int u, int v) {
	int lca = LCA(u, v);
	return dep[u] - dep[lca] + dep[v] - dep[lca];
}

struct DSU {
	int n, fa[MAXN];
	inline void operator()(int sz) { n = sz; for (int i = 1; i <= n; i++) fa[i] = i; }
	int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
	inline void unite(int u, int v) { fa[find(u)] = find(v); }
	inline bool same(int u, int v) { return find(u) == find(v); }
} dsu;

int con[MAXN][MAXN];

inline void solve() {
	int n, k;
	std::cin >> n >> k;
	
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		con[u][v] = con[v][u] = 1;
	}
	
	dfs(1, 0);
	
	int res = 0x3f3f3f3f;
	
	for (int stat = 0; stat < (1 << n); stat++) {
		int cnt = __builtin_popcount(stat);
		if (cnt != k) continue;
		for (int i = 1; i <= n; i++) { vis[i] = 0; }
		for (int i = 1; i <= n; i++) { if ((stat >> (i - 1)) & 1) vis[i] = 1; }
		
		dsu(n);
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) continue;
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) continue;
				if (con[i][j]) {
					if (dsu.same(i, j)) continue;
					else {
						dsu.unite(i, j);
						cnt--;
					}
				}
			}
		}
		
		if (cnt > 2) continue;
		
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int d = 0x3f3f3f3f;
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) continue;
				d = std::min(d, dis(i, j));
			}
			cur = std::max(cur, d);
		}
		res = std::min(cur, res);
	}
	
	std::cout << res << '\n';
	
	for (int u = 1; u <= n; u++) { G[u].clear(); }
	std::memset(con, 0, sizeof con);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int TestCase, T;
	std::cin >> TestCase >> T;
	
	while (T--) {
		solve();
	}
	
	return 0;
}