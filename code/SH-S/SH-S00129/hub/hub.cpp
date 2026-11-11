#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, K, dep[20], st[20][10];
bool vis[20];
vector <int> g[20];
void dfs(int u, int s) {
	if (vis[u]) return;
	if (((1 << (u - 1)) & s) == 0) return;
	vis[u] = true;
	for (auto v:g[u]) dfs(v, s);
}
void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1;
	st[u][0] = fa;
	for (auto v:g[u]) {
		if (v == fa) continue;
		dfs1(v, u);
	}
}
void init() {
	for (int j = 1; j <= 5; j++) {
		for (int i = 1; i <= n; i++) {
			st[i][j] = st[st[i][j - 1]][j - 1];
		}
	}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 5; i >= 0; i--) {
		if (dep[st[u][i]] >= dep[v]) {
			u = st[u][i];
		}
	}
	if (u == v) return u;
	for (int i = 5; i >= 0; i--) {
		if (st[u][i] != st[v][i]) {
			u = st[u][i];
			v = st[v][i];
		}
	}
	return st[u][0];
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		memset(st, 0, sizeof(st));
		cin >> n >> K;
		int ans = 100000;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1, 0);
		init();
//		cout << st[4][1] << '\n';
//		cout << lca(1, 2);
//		dfs(1, 262);
//		cout << vis[1] << ' ' << vis[3]
		for (int s = 0; s < (1 << n); s++) {
			int now = 0;
			if (__builtin_popcount(s) != K) continue;
			bool flag = true;
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if ((s & (1 << k)) && !vis[k + 1]) {
					dfs(k + 1, s);
					cnt++;
				}
				if (cnt > 2) {
					flag = false;
					break;
				}
			}
			if (!flag) continue;
//			cout << s << '\n';
			for (int i = 1; i <= n; i++) {
				if (s & (1 << i - 1)) continue;
//				cout << i << ' ';
				int tmp = 1e6;
				for (int k = 0; k < n; k++) {
					if (s & (1 << k)) {
						int w = lca(i, k + 1);
						tmp = min(tmp, dep[i] + dep[k + 1] - 2 * dep[w]);
					}
				}
				now = max(now, tmp);
//				cout << s << ' ' << tmp << '\n';
			}
			ans = min(ans, now);
//			cout << now << ' ' << ans << '\n';
		}
		cout << ans << '\n';
	} 
	return 0;
} 
