#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using db = double;

const int MAXN = 1e6 + 5;

vector<int> e[MAXN];
int dep[MAXN];
int dfn[MAXN], ts;
int st[20][MAXN];
bool vis[MAXN];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	dfn[u] = ++ts;
	st[0][dfn[u]] = fa;
	for (int v : e[u]) {
		if (v != fa) {
			dfs(v, u);
		}
	}
}

int get(int u, int v) {
	return dfn[u] < dfn[v] ? u : v;
}

int getlca(int u, int v) {
	if (u == v) return u;
	if (dfn[u] > dfn[v]) swap(u, v);
	int k = __lg(dfn[v] - dfn[u]);
	return get(st[k][dfn[u] + 1], st[k][dfn[v] - (1 << k) + 1]);
}

int getdis(int u, int v) {
	int lca = getlca(u, v);
	return dep[u] + dep[v] - 2 * dep[lca];	
}

void dfs2(int u, int s, int fa) {
	vis[u] = true;
	for (int v : e[u]) {
		if (v != fa && (s >> (v - 1)) & 1) dfs2(v, s, u);	
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		e[i].clear();
	}
	ts = 0;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
			st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
	int ans = n + 1;
	for (int s = 0; s < (1 << n); ++s) {
		if (__builtin_popcount(s) != k) continue;
		for (int i = 1; i <= n; ++i) vis[i] = false;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if ((s >> i) & 1 && !vis[i + 1]) {
				dfs2(i + 1, s, 0);
				++cnt;
			}
		}
		if (cnt > 2) continue;
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			int d = n + 1;
			for (int j = 1; j <= n; ++j) {
				if ((s >> (j - 1)) & 1) {
					d = min(d, getdis(i, j));
				}
			}
			mx = max(mx, d);
		}
		ans = min(ans, mx);
	}
	cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
}
