#include <bits/stdc++.h>

namespace Qwarth {

const int N = 1007;

int n, k;
int can[N], vis[N];
int f[N][20], dep[N], dis[N];
std::vector< int > G[N];

void dfs_init(int u, int fa) {
	dep[u] = dep[f[u][0] = fa] + 1;
	for (int v : G[u]) {
		if (v != fa) {
			dfs_init(v, u);
		}
	}
}

int LCA(int u, int v) {
	if (dep[u] < dep[v]) {
		std::swap(u, v);
	}
	int d = dep[u] - dep[v];
	for (int i = 0; i <= 19; ++i) {
		if ((d >> i) & 1) {
			u = f[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 19; i >= 0; --i) {
		if (f[u][i] != f[v][i]) {
			u = f[u][i], v = f[v][i];
		}
	}
	return f[u][0];
}

void dfs(int u) {
	vis[u] = 1;
	for (int v : G[u]) {
		if (can[v] && !vis[v]) {
			dfs(v);
		}
	}
}

int Dfs(int u, int fa, int e, int s) {
	if (u == e) {
		return s;
	}
	int min = n;
	for (int v : G[u]) {
		if (v != fa) {
			min = std::min(min, Dfs(v, u, e, s + 1));
		}
	}
	return min;
}

void main(int _c) {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		G[i].clear();
	}
	for (int i = 1, u, v; i < n; ++i) {
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs_init(1, 0);
	for (int j = 1; j <= 19; ++j) {
		for (int i = 1; i <= n; ++i) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	int ans = 1e9;
	for (int mask = 1; mask < (1 << n); ++mask) {
		int s = 0;
		for (int i = 1; i <= n; ++i) {
			can[i] = (mask >> (i - 1)) & 1;
			vis[i] = 0;
			s += can[i];
		}
		if (s != k) {
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n && cnt <= 2; ++i) {
			if (can[i] && !vis[i] && ++cnt <= 2) {
				dfs(i);
			}
		}
		if (cnt > 2) {
			continue;
		}
		int cur = 0;
		for (int i = 1; i <= n; ++i) {
			dis[i] = n;
			for (int j = 1; j <= n; ++j) {
				if (can[j]) {
					if (i == j) {
						dis[i] = 0;
					} else {
						dis[i] = std::min(dis[i], Dfs(i, 0, j, 0));
					}
				}
			}
			cur = std::max(cur, dis[i]);
		}
		ans = std::min(ans, cur);
	}
	std::cout << ans << '\n';
}
}  // namespace Qwarth

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int _T = 1, c;
	std::cin >> c >> _T;
	while (_T--) {
		Qwarth::main(c);
	}
	return 0;
}
