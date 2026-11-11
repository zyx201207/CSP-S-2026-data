#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int maxn = 505, maxm = 5e5 + 5;

vector<pair<int, int>> graph[maxn + maxm];
int fa[maxn + maxm][25], dis[maxn + maxm], dep[maxn + maxm], w[maxm]; 

void dfs(int x, int f) {
	dep[x] = dep[f] + 1;
	fa[x][0] = f;
	for (int i = 1; i <= 20; ++i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (auto e : graph[x]) {
		int v = e.first, w = e.second;
		if (v == f) continue;
		int newd = dis[x] + w;
		if (dis[v] > newd) dis[v] = newd, dfs(v, x); 
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; --i) if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; --i) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i]; 
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int u, t; cin >> u >> t;
			graph[m + i].push_back({u, t});
			graph[u].push_back({m + i, t}); 
		}
	}
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	dfs(1, 0);
	while (q--) {
		int x, y; cin >> x >> y;
		cout << dis[x] + dis[y] - 2 * dis[lca(x, y)] + w[x] + w[y] << endl; 
	}
	return 0; 
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/