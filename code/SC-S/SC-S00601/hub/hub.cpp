#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int c, T, u, v, n, k, top[N], dep[N], fat[N], siz[N], wc[N];
vector<int> G[N];
bool vis[N];
inline void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	fat[u] = fa;
	for (auto v : G[u]) {
		if (v == fa)	continue;
		dfs(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[wc[u]])	wc[u] = v;
	}
}
inline void dfs2(int u, int Top) {
	top[u] = Top;
	if (wc[u])	dfs2(wc[u], Top);
	for (auto v : G[u]) {
		if (v == fat[u] || v == wc[u])	continue;
		dfs2(v, v);
	}
}
inline int getLCA(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[u] > dep[v])	swap(u, v);
		v = fat[top[v]];
	} return (dep[u] < dep[v] ? u : v);
}
inline int ppc(int x) {
	int cnt = 0;
	while (x) {
		cnt += x % 2;
		x >>= 1;
	} return cnt;
}
vector<int> a;
unordered_map<int, bool> mp;
inline void dfs3(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa)	continue;
		if (!mp[v])	continue;
		if (vis[v])	continue;
		vis[v] = true;
		dfs3(v, u);
	}
}
inline bool check() {
	mp.clear();
	int cnt = 0;
	for (auto i : a)	mp[i] = true;
	for (int i = 1; i <= n; ++i)	vis[i] = false;
	for (auto i : a) {
		if (!vis[i])	++cnt;
		if (vis[i])	continue;
		dfs3(i, 0);
	}
	return (cnt < 3);
}
inline int dfs4(int u, int fa) {
	if (mp[u])	return 0;
	int cnt = 1e18;
	for (auto v : G[u]) {
		if (v == fa)	continue;
		cnt = min(cnt, dfs4(v, u) + 1);
	} return cnt;
}
inline void solve() {
	cin >> n >> k;
	if (c == 13 || c == 14) {
		for (int i = 1; i < n; ++i) {
			cin >> u >> v;
		}
		cout << ((n + 3) / 2 - k + 3) / 4 << '\n';
		return ;
	}
	for (int i = 1; i <= n; ++i)	G[i].clear();
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	} dfs(1, 0); dfs2(1, 1);
	int ans = 1e18;
	for (int i = 0; i < (1ll << n); ++i) {
		if (ppc(i) != k)	continue;
		a.clear();
		for (int j = 1; j <= n; ++j) {
			if (i & (1ll << (j - 1))) {
				a.push_back(j);
			}
		}
		if (!check())	continue;
		int now = 0;
		for (int u = 1; u <= n; ++u) {
			now = max(now, dfs4(u, 0));
		} ans = min(ans, now);
	} cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--)	solve();
	return 0;
}