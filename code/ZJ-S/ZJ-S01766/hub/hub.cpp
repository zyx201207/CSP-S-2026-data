#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;

int n, a[N], k, vis[N];
vector<int> g[N];

int dfs(int u, int fa, int len) {
	//~ cout << u << '\n';
	if (a[u] == 1) return len;
	int res = n + 1;
	for (auto v : g[u]) {
		if (v == fa) continue;
		res = min(res, dfs(v, u, len + 1));
	}
	return res;
}

void dfs2(int u, int fa) {
	if (a[u] == 0) return;
	vis[u] = 1;
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs2(v, u);
	}
	return;
}

void solve() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int cnt;
	int ans = 0x3f3f3f3f, res = 0;
	for (int msk = 1; msk < (1 << n); msk++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			a[i + 1] = (msk >> i) & 1;
			vis[i + 1] = 0;
			cnt += a[i + 1];
		}
		res = 0;
		if (cnt != k) continue;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] && !vis[i]) {
				++cnt;
				dfs2(i, i);
			}
		}
		if (cnt > 2) continue;
		for (int i = 1; i <= n; i++) {
			res = max(res, dfs(i, i, 0));
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) g[i].clear();
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, c; cin >> c >> t;
	while (t--) solve();
	return 0;
}
/*

0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
