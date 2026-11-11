#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e5 + 10;
typedef pair<int, int> pii;
vector<int> g[N];
int c, t, n, k;
int fa[N][26], dep[N];
void dfs (int u, int f) {
	fa[u][0] = f;
	dep[u] = dep[f] + 1;
	for (int i = 1; (1 << i) <= dep[u]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v:g[u]) {
		if (v == f) continue;
		dfs (v, u);
	}
}
int lca (int u, int v) {
	if (dep[u] < dep[v]) swap (u, v);
	for (int i = 24; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v) return u;
	for (int i = 24; i >= 0; i--) {
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}
bool ff[N], vis[N];
void dfs1 (int x, int f) {
	vis[x] = 1;
	for (auto v:g[x]) {
		if (v == f) continue;
		if (ff[v]) dfs1 (v, x);
	}
}
bool check (vector<int> v) {
	memset (ff, 0, (n + 1) * sizeof (bool));
	memset (vis, 0, (n + 1) * sizeof (bool));
	for (auto x:v) ff[x] = 1;
	int cnt = 0;
	for (auto x:v) {
		if (!vis[x]) {
			cnt++;
			if (cnt > 2) return 0;
			dfs1 (x, 0);
		}
	}
	return 1;
}

int si[N];
vector<int> h;
void dfs2 (int u, int fa) {
	si[u] = 1;
	int mx = 0;
	for (auto v:g[u]) {
		if (v == fa) continue;
		dfs2 (v, u);
		si[u] += si[v];
		mx = max (mx, si[v]);
	}
	mx = max (mx, n - si[u]);
//	cout << mx << "\n";
	if (mx <= n / 2) h.push_back (u);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);

	cin >> c >> t;
	if (c >= 3) {
		while (t--) {
			cin >> n >> k;
			for (int i = 1; i <= n; i++) g[i].clear();
			for (int i = 1; i <= n - 1; i++) {
				int u, v;
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			dfs (1, 0);
			h.clear();
			dfs2(1, 0);
			if (h.size() == 1) {
				if (fa[h[0]][0] != 0) h.push_back(fa[h[0]][0]);
				else h.push_back(g[h[0]][0]);
			}
			int ans = 0, res = 0;
			for (int i = 1; i <= n; i++) {
				int mi = 1e9;
				for (auto x:h) {
					int l = lca (i, x);
					mi = min (mi, -2 * dep[l] + dep[i] + dep[x]);
				}
				res = max (res, mi);
			}
			cout << res << "\n";
		}
		return 0;
	}
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		int ans = 1e9;
		for (int mask = 0; mask <= (1 << n) - 1; mask++) {
			int tot = 0;
			vector<int> v;
			for (int i = 1; i <= n; i++) {
				if (mask & (1 << (i - 1))) {
					tot++;
					v.push_back (i);
				}
			}
			if (tot != k) continue;
			if (!check (v)) continue;
			int res = 0;
			for (int i = 1; i <= n; i++) {
				int mi = 1e9;
				for (auto x:v) {
					int l = lca (i, x);
					mi = min (mi, -2 * dep[l] + dep[i] + dep[x]);
				}
				res = max (res, mi);
			}
			ans = min (ans, res);
		}
		cout << ans << "\n";
	}
	return 0;
}

