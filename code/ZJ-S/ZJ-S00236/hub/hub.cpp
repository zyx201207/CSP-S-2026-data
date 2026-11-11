#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, inf = 0x3f3f3f3f;
int c, t, n, k, ans, d[N];
vector<int> g[N];
bool vis[N], f[N];
struct node {
	int u, w;
	bool operator < (const node b) const {
		return w > b.w;
	}
}; priority_queue<node> q;
void dfs2(int u) {
	for (int v : g[u]) {
		if (!vis[v] || f[v]) continue;
		f[v] = true; dfs2(v);
	}
	return ;
}
bool check() {
	int cnt;
	for (int i = 1; i <= n; i++) f[i] = false;
	for (int i = 1; i <= n; i++){
		if (vis[i] && !f[i]) {
			cnt++; if (cnt > 2) return false;
			f[i] = true; dfs2(i);
		}
	}
	return true;
}
void dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		d[i] = inf, vis[i] = false;
	}
	d[s] = 0; q.push({s, d[s]});
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int p : g[u]) {
			int w;
			if (vis[u] && vis[p]) w = 0;
			else w = 1;
			if (d[u] + w < d[p]) {
				d[p] = d[u] + w;
				q.push({p, d[p]});
			}
		}
	}
	return ;
}
int query() {
	int mn = 1e9;
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			mn = min(mn, d[j]);
		}
	}
	return mn;
}
void dfs(int x, int c) {
	if (x == n || c == k) {
		if (c > k || !check()) return ;
		ans = min(ans, query());
	}
	vis[x] = false;
	dfs(x + 1, c);
	vis[x] = true;
	dfs(x + 1, c + 1);
	return ;
}
void solve() {
	cin >> n >> k; ans = 1e9;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	dfs(1, 0);
	cout << ans;
	return ;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}