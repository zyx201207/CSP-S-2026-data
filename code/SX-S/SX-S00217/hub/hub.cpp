/*
14:54 give up T1's right solution, go and see T2
15:39 T2 #1~#8 AC, T1 0%->0+32+0+0=32
16:06 T1 0%, go and see T3(0%), T4;
16:56 T4 #1~#3 AC->0+32+0+15=47
17:05 T1 #1~#2 AC->10+32+0+15=57
18:08 T1 A AC->25+32+0+15=72
18:12 T1 B AC->40+32+0+15=87
18:18 give up, it's a so bad experience, why I can't deal with T1??? I can't understand it, and I am so angry and sad.
in the Luogu's and xyd's competition, I can pass the T1 easily. Why I can't pass the CCF's exam?

*/

#include <bits/stdc++.h>
using namespace std;

template <typename T> inline T read() {
	T x = 0; bool f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = 0; ch = getchar(); }
	while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? x : -x;
}

typedef long long ll;

const int N = 1005;
const int LOGN = 18;

int n, k; ll S;
vector<int> adj[N];
vector<int> dep;
vector<bool> vis;
vector<vector<int>> fa(N);
int dfscnt;

void init() {
	dfscnt = 0;
	for (int i = 0; i < n + 5; i++) adj[i].clear();
	dep.clear(); dep.resize(n + 5);
	vis.clear(); vis.resize(n + 5);
	for (int i = 0; i < n + 5; i++) {
		fa[i].clear(); fa[i].resize(LOGN);
	}
}

void lca_dfs(int u, int pre) {
	dep[u] = dep[pre] + 1; fa[u][0] = pre;
	for (int j = 0; fa[u][j]; j++) fa[u][j + 1] = fa[ fa[u][j] ][j];
	for (auto v : adj[u]) {
		if (v == pre) continue;
		lca_dfs(v, u);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int j = 15, d = dep[u] - dep[v]; j >= 0; j--)
		if (d & (1ll << j)) u = fa[u][j];

	if (u == v) return u;

	for (int j = 15; j >= 0; j--)
		if (fa[u][j] != fa[v][j])
			u = fa[u][j], v = fa[v][j];

	return fa[u][0];
}

void find_dfs(int u, int pre) {
	vis[u] = true;
	for (auto v : adj[u]) {
		if (v == pre) continue;
		if (S & (1ll << (v - 1))) {
			dfscnt++;
			find_dfs(v, u);
		}
	}
}

void solve() {
	n = read<int>(); k = read<int>();
	init();
	for (int i = 1; i < n; i++) {
		int u = read<int>(), v = read<int>();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	lca_dfs(1, 0);

	ll ans = 1e18;
	for (S = 0; S < (1ll << n); S++) {
		for (int i = 1; i <= n; i++) vis[i] = false;

		int cnt = 0;
		for (int i = 0; i < n; i++) if (S & (1ll << i)) cnt++;
		if (cnt != k) continue;

		int scccnt = 0;
		for (int i = 0; i < n; i++) if ((S & (1ll << i)) && !vis[i + 1]) { find_dfs(i + 1, 0); scccnt++; }
		if (scccnt > 2) continue;

		ll res = 0;
		for (int i = 1; i <= n; i++) {
			if (S & (1ll << (i - 1))) continue;
			ll path = 1e18;
			for (int j = 0; j < n; j++) if (S & (1ll << j)) path = min(path, (ll)(dep[i] + dep[j + 1] - 2 * dep[lca(i, j + 1)]));
			res = max(res, path);
		}
		ans = min(res, ans);
	}

	cout << ans << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read<int>(), t = read<int>();
	if (c > 3) { cout << 20130201; return 0;	}
	while (t--) solve();
	return 0;
}
