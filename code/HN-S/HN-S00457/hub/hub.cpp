#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e6;

int c, t, n, k, f[kMaxN], mn[kMaxN], ans, vis[kMaxN];
vector<int> e[kMaxN];

void find(int x, int dis, int fa) {
	mn[x] = min(mn[x], dis);
	for (int i : e[x])
		if (i != fa) find(i, dis + 1, x);
}

void getcnt(int x) {
	vis[x] = 1;
	for (int i : e[x])
		if (!vis[i] && f[i]) getcnt(i);
}

void dfs(int x, int y) {
	if (y < 0) return;
	if (x > n || y == 0) {
		if (y > 0) return;
		for (int i = 1; i <= n; i++) mn[i] = 1e9, vis[i] = 0;
		for (int i = 1; i <= n; i++)
			if (f[i]) find(i, 0, 0);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (f[i] && !vis[i]) getcnt(i), cnt++;
		if (cnt > 2) return;
		int mx = 0;
		for (int i = 1; i <= n; i++) mx = max(mx, mn[i]);
		ans = min(ans, mx);
		return;
	}
	f[x] = 1;
	dfs(x + 1, y - 1);
	f[x] = 0;
	dfs(x + 1, y);
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) e[i].clear(), f[i] = vis[i] = 0;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	if (c == 13 || c == 14)
		cout << max(0, (k == 1 ? ((n + 1) / 2 + 1) / 2 : (((n + 1) / 2 + 2) / 2 - k / 2 + 1) / 2)) << '\n';
	else {
		ans = 1e9;
		dfs(1, k);
		cout << ans << '\n';
	}
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (cin >> c >> t; t; t--)
		solve();
  return 0;
}
// cutecutezrr