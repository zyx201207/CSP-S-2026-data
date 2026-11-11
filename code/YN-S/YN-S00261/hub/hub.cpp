#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 1000010;
std::vector<int>g[N];
int dis1[N], dis2[N];

void dfs(int u, int fa, int d) {
	dis1[u] = d;
	for (int v : g[u]) {
		if (v == fa)
			continue;
		dfs(v, u, d + 1);
	}
}

void dfs2(int u, int fa, int d) {
	dis2[u] = d;
	for (int v : g[u]) {
		if (v == fa)
			continue;
		dfs2(v, u, d + 1);
	}
}

void solve() {
	memset(dis1, 0, sizeof dis1);
	memset(dis2, 0, sizeof dis2);
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 1e9, mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dfs(i, 0, 0);
			dfs2(j, 0, 0);
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j)
					continue;
				mx = std::max(ans, std::min(dis1[k], dis2[k]));
			}
			ans = std::min(ans, mx);

		}
	}
	std::cout << ans << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	std::cin >> c >> t;
	while (t--)
		solve();
	return 0;
}