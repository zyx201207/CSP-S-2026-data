#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int tstcntc, t, n, k, fa[N][20], lg[N], dep[N], a[N], vis[N], allans;
vector<int> g[N];
string s01;

void dfs111(int x, int f) {
	fa[x][0] = f;
	dep[x] = dep[f] + 1;
	for (int i = 1; i < 20; i++) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i : g[x]) {
		if (i != f) {
			dfs111(i, x);
		}
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	while (dep[y] > dep[x]) {
		y = fa[y][lg[dep[y] - dep[x]]];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}

void dfstree(int x) {
	vis[x] = 1;
	for (int i : g[x]) {
		if (vis[i]) continue;
		if (s01[i - 1] == '1') {
			dfstree(i);
		}
	}
}

void dfs01(int x, int cnt) {
	if (cnt > k || cnt + n - x < k) return;
	if (x == n) {
		if (cnt != k) return;
		int cnt = 0;
		fill(vis + 1, vis + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && s01[i - 1] == '1') {
				dfstree(i);
				cnt++;
				if (cnt > 2) break;
			}
		}
		if (cnt > 2) return;
//		cout << s01 << '\n';
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int mi = 1e9;
			for (int j = 1; j <= n; j++) {
				if (s01[j - 1] == '0') continue;
				int lc = lca(i, j);
				mi = min(mi, dep[i] + dep[j] - 2 * dep[lc]);
			}
			ans = max(ans, mi);
		}
		allans = min(allans, ans);
		return;
	}
	s01 += '1';
	dfs01(x + 1, cnt + 1);
	s01.back() = '0';
	dfs01(x + 1, cnt);
	s01.pop_back();
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 2; i <= N - 5; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	for (cin >> tstcntc >> t; t--;) {
		allans = 1e9;
		s01 = "";
		cin >> n >> k;
		fill(dep + 1, dep + n + 1, 0);
		fill(fa[1], fa[n + 1], 0);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 1, x, y; i < n; i++) {
			cin >> x >> y;
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		dfs111(1, 0);
		dfs01(0, 0);
		cout << allans << '\n';
	}
	return 0;
}

