#include <bits/stdc++.h>
using namespace std;
int n, k, u, v, d[1000005], maxd, res, f[1000005], vis[1000005], mid, vv[1000005];
vector<int> e[1000005];
void dfs(int x, int fa, int dep) {
	d[x] = dep;
	f[x] = fa;
	if (dep > maxd) maxd = dep, u = x;
	for (int i : e[x]) {
		if (i == fa) continue;
		dfs(i, x, dep + 1);
	}
	return;
}
void dfs2(int x, int fa, int dep) {
	if (dep > maxd) maxd = dep, v = x;
	for (int i : e[x]) {
		if (i == fa) continue;
		dfs2(i, x, dep + 1);
	}
	return;
}
void dfs3(int x, int l) {
	if (vis[x] || l > mid) {
		res = max(res, l);
		return;
	}
	for (int i : e[x]) {
		if (vv[i]) continue;
		vv[i] = 1;
		dfs3(i, l + 1);
		vv[i] = 0;
	}
	return;
}
int check(int h) {
	int x = u;
	for (int i = 1; i <= h && f[x] != 0; i++) x = f[x];
	vis[x] = 1;
	int y = v;
	for (int i = 1; i <= h && f[y] != 0; i++) y = f[y];
	vis[y] = 1;
	int t = y;
	for (int i = 1; i <= k - 2; i++) {
		t = f[t];
		vis[t] = 1;
	}
	res = 0;
	for (int i = 1; i <= n; i++) {
		dfs3(i, 0);
	}
	if (res <= h) return 1;
	return 0;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		maxd = 0;
		for (int i = 1; i <= n; i++) e[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0, 1);
		maxd = 0;
		dfs2(u, 0, 1);
		int l = 0, r = d[u] + d[v] - 1;
		int ans;
		while (l <= r) {
			mid = l + r >> 1;
			if (check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}