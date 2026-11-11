#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E6+5, DMAXN = 105;

int c, t, n, k;
struct edge {
	int to;
	int next;
}edges[MAXN << 1];
int edgecnt, edgeset[MAXN];
void addedge(int from, int to) {
	edges[++edgecnt] = (edge){to, edgeset[from]};
	edgeset[from] = edgecnt; 
}

int fa[MAXN], dep[MAXN];
void dfs1(int pres, int prev) {
	fa[pres] = prev;
	dep[pres] = dep[prev] + 1;
	for (int e = edgeset[pres], to; e; e = edges[e].next) {
		to = edges[e].to;
		if (to == prev) continue;
		dfs1(to, pres);
	}
}

bool sl[DMAXN], used[DMAXN];
int vc, cc, ans, tans;
void dfs2(int pres) {
	used[pres] = true;
	for (int e = edgeset[pres], to; e; e = edges[e].next) {
		to = edges[e].to;
		if (to == fa[pres] || !sl[to]) continue;
		dfs2(to);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] > dep[v]) u = fa[u];
	while (u != v) u = fa[u], v = fa[v];
	return u;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		edgecnt = 0;
		for (int i = 1; i <= n; i++) edgeset[i] = 0;
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			addedge(u, v), addedge(v, u);
		}
		dfs1(1, 0);
		if (c <= 3) {
			ans = 1E9;
			for (int b = 1; b < (1 << n); b++) {
				vc = cc = 0;
				for (int i = 1; i <= n; i++) {
					if ((b >> (i - 1)) & 1) sl[i] = true, vc++;
					else sl[i] = false;
				}
				if (vc != k) continue;
				for (int i = 1; i <= n; i++) used[i] = false;
				for (int i = 1; i <= n; i++) {
					if (sl[i] && !used[i]) cc++, dfs2(i);
				}
				if (cc > 2) continue;
				tans = 0;
				for (int i = 1, tmp, x; i <= n; i++) {
					tmp = 1E9;
					for (int j = 1; j <= n; j++) {
						if (!sl[j]) continue;
						x = lca(i, j);
						tmp = min(tmp, dep[i] + dep[j] - 2 * dep[x]);
					}
					tans = max(tans, tmp);
				}
				ans = min(ans, tans);
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
