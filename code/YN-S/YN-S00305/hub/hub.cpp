#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 1e5 + 5;
int test_c, n, k, dis[N];
vector <int> e[N];
bool vis[N], p[N];
queue <int> q;
void dfs(int u) {
	vis[u] = true;
	for (int v : e[u]) if (!vis[v] && p[v]) dfs(v);
}
int calc() {
	for (int i = 1; i <= n; i++) vis[i] = false;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] || !p[i]) continue;
		cnt++, dfs(i);
	}
	if (cnt != 2) return 1e9;
	for (int i = 1; i <= n; i++) if (p[i]) dis[i] = 0, q.push(i); else dis[i] = 1e9;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u])
			if (dis[u] + 1 < dis[v]) dis[v] = dis[u] + 1, q.push(v);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(dis[i], res);
	return res;
}
void solve() {
	in >> n >> k;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v; in >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	int ans = n - 1;
	for (int i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) != k) continue;
		for (int j = 0; j < n; j++) if (i >> j & 1) p[j + 1] = true; else p[j + 1] = false;
		ans = min(ans, calc());
	}
	out << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	int T; in >> test_c >> T;
	while (T--) solve();
	return 0;
}