/*
【数据删除】怎么这么【数据删除】【数据删除】
【数据删除】了
我好菜
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n, m;
vector<int> E[N];

namespace sub0 {
	const int N = 20;
	int vis[N], d[N];
	void dfs(int u, int s) {
		vis[u] = 1;
		for (auto v : E[u]) if (!vis[v]) dfs(v, s);
	}
	int check(int s) {
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 1;i <= n;i++) if (!vis[i] && (s >> (i - 1) & 1)) dfs(i, s), cnt++;
		return cnt <= 2;
	}
	void dfss(int u, int fa) {
		d[u] = d[fa] + 1;
		for (auto v : E[u]) if (v != fa) dfss(v, u);
	}
	int calc(int s) {
		int r = 0;
		for (int i = 1;i <= n;i++) {
			dfss(i, 0);
			int mn = 1e9;
			for (int j = 1;j <= n;j++) if (s >> (j - 1) & 1) mn = min(mn, d[j] - 1);
			r = max(r, mn);
		}
		return r;
	}
	void solve() {
		cin >> n;
		for (int i = 1;i <= n;i++)
			E[i].clear();
		for (int i = 1, u, v;i < n;i++)
			cin >> u >> v, E[u].emplace_back(v), E[v].emplace_back(u);
		int ans = 1e9;
		for (int s = 1;s < (1 << n);s++)
			if (check(s)) ans = min(ans, calc(s));
		cout << ans << "\n";
	}
}
namespace sub1 {
	// O(n^3)枚举一条边断开，两边分别dp
	const int N = 100 + 10;
	int f[N][N], g[N], dep[N], mdep[N], sz[N], dfn[N], out[N], cyh, p[N];
	void dfs1(int u, int fa) {
		p[u] = fa, dep[u] = mdep[u] = dep[fa] + 1, dfn[u] = ++cyh;
		for (auto v : E[u]) if (v != fa)
			dfs1(v, u), mdep[u] = max(mdep[u], mdep[v]);
		out[u] = cyh;
	}
	int d(int x, int y) {
		if (dep[x] < dep[y]) swap(x, y);
		int r = 0;
		while (dep[x] != dep[y]) x = p[x], r++;
		while (x != y) x = p[x], y = p[y], r += 2;
		return r;
	}
	void dfs2(int u, int fa, int &ans, int rt) {
		sz[u] = 1, f[u][1] = 0;
		for (auto v : E[u]) if (v != fa) {
			dfs2(v, u, ans, rt);
			for (int i = 0;i <= n;i++)
				g[i] = 1e9;
			for (int i = 1;i <= sz[u];i++) {
				g[i] = min(g[i], max(f[u][i], mdep[v] - dep[u]));
				for (int j = 1;j <= sz[v];j++)
					g[i + j] = min(g[i + j], max(f[u][i], f[v][j]));
			}
			sz[u] += sz[v];
			for (int i = 1;i <= sz[u];i++)
				f[u][i] = g[i];
		}
		int mx = 0;
		for (int i = 1;i <= n;i++)
			if (dfn[i] >= dfn[rt] && dfn[i] <= out[rt] && !(dfn[i] >= dfn[u] && dfn[i] <= out[u]))
				mx = max(mx, d(u, i));
		ans = min(ans, max(f[u][min(m, sz[u])], mx));
	}
	void solve() {
		cin >> n >> m;
		for (int i = 1;i <= n;i++)
			E[i].clear();
		for (int i = 1, u, v;i < n;i++)
			cin >> u >> v, E[u].emplace_back(v), E[v].emplace_back(u);
		int ans = 1e9;
		for (int i = 1;i < n;i++)
			for (auto j : E[i]) if (j < i) {
				int r1 = 1e9, r2 = 1e9;
				cyh = 0;
				dfs1(i, j), dfs1(j, i);
				dfs2(i, j, r1, i), dfs2(j, i, r2, j);
				ans = min(ans, max(r1, r2));
				cout << i << " " << j << "  " << r1 << " " << r2 << "\n";
			}
		cout << ans << "\n";
	}
}
namespace subk2 {
	// 找直径
	void solve() {

	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int sid, T; cin >> sid >> T;
	while (T--) {
		if (sid <= 3) sub0::solve();
		if (4 <= sid && sid <= 6) sub1::solve();
		if (sid == 7 || sid == 13 || sid == 14) subk2::solve();
	}

	return 0;
}