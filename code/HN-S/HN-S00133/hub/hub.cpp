#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int c, t, n, k, a[N][N], ans, pos[N], f[N];
int dep[N], sz[N], son[N], fa[N], top[N];
vector <int> g[N];
void dfs1 (int now, int f) {
	fa[now] = f;
	sz[now] = 1;
	dep[now] = dep[f] + 1;
	for (int v : g[now])
		if (v != f) {
			dfs1(v, now);
			sz[now] += sz[v];
			if (sz[v] > sz[son[now]])
				son[now] = v;
		}
}
void dfs2 (int now, int tp) {
	top[now] = tp;
	if (son[now]) dfs2(son[now], tp);
	for (int v : g[now])
		if (v != fa[now] && v != son[now])
			dfs2(v, v);
}
int get_lca (int u, int v) {
	int x = u, y = v;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return (dep[x] < dep[y]) ? x : y;
}
int find (int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
bool check () {
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++) {
			if (i == j) continue;
			if (a[pos[i]][pos[j]]) {
				if (dep[pos[i]] > dep[pos[j]])
					f[pos[i]] = pos[j];
				else
					f[pos[j]] = pos[i];
			}
		}
	set <int> s;
	for (int i = 1; i <= k; i++)
		s.insert(find(pos[i]));
	if (s.size() > 2) return 0;
	return 1;
}
int get_ans () {
	int maxx = INT_MIN;
	for (int i = 1; i <= n; i++) {
		int tmp = INT_MAX;
		for (int j = 1; j <= k; j++) {
			int lca = get_lca(i, pos[j]);
			tmp = min(tmp, dep[i] + dep[pos[j]] - dep[lca] * 2);
		}
		maxx = max(maxx, tmp);
	}
	return maxx;
}
void dfs (int now, int x) {
	if (now == n + 1 || x == 0) {
		if (check())
			ans = min(ans, get_ans());
		return ;
	}
	if (n - now + 1 < x) return ;
	dfs(now + 1, x);
	pos[k - x + 1] = now;
	dfs(now + 1, x - 1);
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		ans = INT_MAX;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			a[u][v] = a[v][u] = 1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1, 0);
		dfs2(1, 1);
		dfs(1, k);
		cout << ans <<'\n';
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = 0;
		for (int i = 1; i <= n; i++) {
			top[i] = dep[i] = fa[i] = son[i] = sz[i] = 0;
			g[i].clear();
		} 
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
