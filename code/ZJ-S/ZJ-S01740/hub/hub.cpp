#include <bits/stdc++.h>
#define ll long long
const int N = 1e6 + 5;
int n, k, vis[N], dis[N], in[N], res;
std::vector<int> adj[N];
void get(int x, int p) {
	for (int y : adj[x]) {
		if (y == p) continue;
		dis[y] = dis[x] + 1, get(y, x);
	}
}
void dfs(int x, int ch) {
	if (ch > k || k - ch > n - x + 1) return ;
	if (x == n + 1) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) in[i] = 0;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] || in[i]) continue;
			std::queue<int> q;
			in[i] = 1, q.emplace(i), ++cnt;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				for (int y : adj[x]) {
					if (!vis[y] || in[y]) continue;
					in[y] = 1, q.emplace(y);
				}
			}
		}
		if (cnt > 2) return ;
		int d = 0;
		for (int i = 1; i <= n; ++i) {
			if (vis[i]) continue;
			dis[i] = 0, get(i, 0);
			int dd = N;
			for (int j = 1; j <= n; ++j)
				if (vis[j]) dd = std::min(dd, dis[j]);
			d = std::max(d, dd);
		}
		res = std::min(res, d);
		return ;
	}
	vis[x] = 1, dfs(x + 1, ch + 1);
	vis[x] = 0, dfs(x + 1, ch);
}
void solve() {
	std::cin >> n >> k, res = N;
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	for (int i = 1, x, y; i < n; ++i) {
		std::cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	dfs(1, 0), std::cout << res << "\n";
}
int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; std::cin >> c >> t;
	while (t--) solve();
}