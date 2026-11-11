#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int c, T, n, k, dis[N][N], vis[N];
vector<int> g[N];
void dfs (int S, int u) {
	vis[u] = 1;
	for (int v : g[u])
		if ((S >> (v - 1) & 1) && !vis[v])
			dfs(S, v);
}
bool check (int S) {
	for (int i = 1; i <= n; ++i)
		vis[i] = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!(S >> i & 1) || vis[i + 1])
			continue;
		++cnt;
		if (cnt > 2)
			return false;
		dfs(S, i + 1);
	}
	return true;
}
void dfs2 (int s, int u, int d) {
	dis[s][u] = d;
	for (int v : g[u])
		if (!dis[s][v] && s != v)
			dfs2(s, v, d + 1);
}
void solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		g[i].clear();
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			dis[i][j] = 0;
		dfs2(i, i, 0);
	}
	int ans = n;
	for (int S = 1; S < (1 << n); ++S) {
		if (!check(S))
			continue;
		int t = 0, mx = 0;
		for (int i = 0; i < n; ++i)
			t += (S >> i & 1);
		if (t != k)
			continue; 
		for (int i = 1; i <= n; ++i) {
			int mn = n;
			for (int j = 0; j < n; ++j)
				if (S >> j & 1)
					mn = min(mn, dis[i][j + 1]);
			mx = max(mx, mn);
		}
		ans = min(ans, mx);
	}
	cout << ans << endl;
}
int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
