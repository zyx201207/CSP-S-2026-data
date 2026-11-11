#include <bits/stdc++.h>
#define pk push_back
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e9;
int c, t, n, k;
int fa[N], siz[N], dep[N];
vector<int> g[N];
int son[N], top[N];
bool vis[N];
int dsu[N];
int find(int x) {
	return (dsu[x] == x) ? x : dsu[x] = find(dsu[x]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		dsu[x] = y;
	}
	return ;
}
void dfs1(int cur, int f) {
	fa[cur] = f;
	siz[cur] = 1;
	dep[cur] = dep[f] + 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int nxt = g[cur][i];
		if (nxt == f) continue;
		dfs1(nxt, cur);
		siz[cur] += siz[nxt];
		if (siz[nxt] > siz[son[cur]]) {
			son[cur] = nxt;
		}
	}
	return ;
}
void dfs2(int cur) {
	if (son[cur]) {
		top[son[cur]] = top[cur];
		dfs2(son[cur]);
	}
	for (int nxt : g[cur]) {
		if (nxt == fa[cur] || nxt == son[cur]) continue;
		dfs2(nxt);
	}
	return ;
}
int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) return x;
	return y;
}
int get(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void solve() {
	cin >> n >> k;
	int u, v;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].pk(v);
		g[v].pk(u);
	}
	dfs1(1, 0);
	top[1] = 1;
	dfs2(1);
	int ans = inf;
	for (int mask = 1; mask < (1 << n); mask++) {
		int chs = 0;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if ((mask >> (i - 1)) & 1) {
				vis[i] = 1;
				chs++;
			}
		}
		if (chs != k) continue;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 1) {
				dsu[i] = i;
			}
		}
		for (int u = 1; u <= n; u++) {
			if (!vis[u]) continue;
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i];
				if (!vis[v]) continue;
				unite(u, v);
			}			 
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 1) {
				if (dsu[i] == i) {
					sum++;
				}
			}
		}
		if (sum > 2) {
			continue;
		}
//		cout << "www";
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int dis1 = inf;
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) continue;
				dis1 = min(dis1, get(i, j));
			}
			Max = max(Max, dis1);
		}
		ans = min(ans, Max);
	}
	cout << ans << "\n";
	return ;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
