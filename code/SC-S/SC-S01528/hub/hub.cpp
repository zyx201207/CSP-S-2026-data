#include<bits/stdc++.h>
#define int long long
using namespace std;
#define N 2005
vector<int>mp[N];
int T, c, n, k, sum, ans, s[N], d[N], sz[N], inf = 2e18;
void dfs1 (int u, int fa) {
	d[u] = d[fa] + 1, sz[u] = 1;
	for (int v : mp[u]) if (v != fa) dfs1 (v, u), sz[u] += sz[v];
}
void dfs2 (int u, int fa) {
	for (int v : mp[u]) if (v != fa) dfs2 (v, u), s[u] += s[v];
}
void dfs2 (int u, int t, int fa) {
	if (s[u]) ans = min (ans, t);
	for (int v : mp[u]) if (v != fa) dfs2 (v, t + 1, u);
}
struct dsu {
	int fa[N];
	void init (int n) {
		for (int i = 1; i <= n; i++) fa[i] = i;
	}
	int fd (int u) {
		while (u != fa[u]) u = fa[u] = fa[fa[u]];
		return u;
	}
	void hb (int u, int v) {
		u = fd (u), v = fd (v);
		if (u != v) fa[v] = u;
	}
} tr;
signed main() {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k, sum = inf;
		for (int i = 1, u, v; i < n; i++) cin >> u >> v, mp[u].emplace_back (v), mp[v].emplace_back (u);
		dfs1 (1, 0);
		for (int i = 0, t; i < (1 << n); i++) {
			tr.init (n), t = 0;
			for (int j = 0; j < n; j++) s[j + 1] = ( (i >> j) & 1), t += ( (i >> j) & 1);
			if (t != k) continue;
			t = 0;
			for (int j = 1; j <= n; j++) if (s[j]) for (int u : mp[j]) if (s[u]) tr.hb (j, u);
			for (int j = 1; j <= n; j++) if (s[j]) t += (tr.fd (j) == j);
			if (t > 2) continue;
			t = 0;
			for (int j = 1; j <= n; j++) ans = inf, dfs2 (j, 0, 0), t = max (ans, t);
			sum = min (sum, t);
		}
		cout << sum << '\n';
		for (int i = 1; i <= n; i++) mp[i].clear();
	}
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
还有8分钟结束了，写点东西
大约是100+100+24+15
好猎奇的分数构成
t340分的点调了一辈子没调出来
难度感觉和去年差不多
今年退役季希望有一个圆满的结局吧
while (true) NOIP2026 rp++;
*/