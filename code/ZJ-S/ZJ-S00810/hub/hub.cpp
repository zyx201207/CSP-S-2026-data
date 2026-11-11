#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5, inf = 1e9;
int n, k, ans = inf;
vector <int> g[N];
bool ch[N];
int fa[N];
int f[N][25];
void init();
int find(int x);
void merge(int x, int y);
void build_fa(int now, int fa);
void build_f(int now, int fa);
int cal();
void dfs(int dep, int cnt);
void solve();
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
void init() {
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
}
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fy] = fx;
}
void build_fa(int now, int fa) {
	for (int nxt: g[now]) {
		if (nxt == fa) continue;
		merge(now, nxt);
		build_fa(nxt, now);
	}
}
void build_f(int now, int fa) {
	for (int nxt: g[now]) {
		if (nxt == fa) continue;
		f[nxt][0] = now;
		build_f(nxt, now);
	}
}
int cal() {
	for (int i = 1; i <= n; i++) {
		if (!ch[i]) continue;
		for (int j = 1; j <= n; j++) {
			if (!ch[j]) continue;
		}
	}
}
void dfs(int dep, int cnt) {
	if (cnt > k) return;
	if (dep == n) {
		if (cnt < k) return;
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) {
			if (fa[i] != i || !ch[i]) continue;
			build_fa(i, 0);
		}
		int cntf = 0;
		for (int i = 1; i <= n; i++)
			if (ch[i] && fa[i] == i) cntf++;
		if (cnt > 2) return;
		ans = min(ans, cal());
	}
	ch[dep + 1] = 1;
	dfs(dep + 1, cnt + 1);
	ch[dep + 1] = 0;
	dfs(dep + 1, cnt);
}
void solve() {
	cin >> n >> k;
	init();
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	build_f(1, 0);
	for (int len = 1; len <= 20; len++)
		for (int i = 1; i <= n; i++)
			f[i][len] = f[f[i][len - 1]][len - 1];
	dfs(0, 0);
}
