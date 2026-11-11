#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, ans = 1e18;
int d[100005], f[100005][35], fa[100005];
vector<int> g[100005];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int father, int u) {
	d[u] = d[father] + 1;
	f[u][0] = father;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != father) {
			dfs(u, v);
		}
	}
}
int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int kk = 30; kk >= 0; kk--)
		if (d[f[u][kk]] >= d[v]) u = f[u][kk];
	if (u == v) return u;
	for (int kk = 30; kk >= 0; kk--)
		if (f[u][kk] != f[v][kk]) {
			u = f[u][kk];
			v = f[v][kk];
		}
	return f[u][0];
}
void solve() {
	ans = 1e18;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		g[i].clear();
		d[i] = 0;
		for (int j = 0; j <= 30; j++) f[i][j] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 1);
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++) 
			f[i][j] = f[f[i][j - 1]][j - 1];
	for (int i = 1; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) fa[j] = j;
		for (int j = 0; j < n; j++) if (i & (1 << j)) cnt++;
		if (cnt != k) continue;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				for (int k = 0; k < g[j + 1].size(); k++)
					if (i & (1 << (g[j + 1][k] - 1)))
						fa[find(j + 1)] = find(g[j + 1][k]);
		set<int> s;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) s.insert(fa[j + 1]);
		if (s.size() > 2) continue;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int tt = 1e18;
			for (int k = 0; k < n; k++) {
				if (i & (1 << k)) {
					tt = min(tt, -2 * d[lca(j + 1, k + 1)] + d[j + 1] + d[k + 1]);
				}
			}
			sum = max(sum, tt);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
} 
