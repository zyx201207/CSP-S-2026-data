#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dist;
vector<vector<int>> adj;
int n, k;

void dfs_dist(int u, int fa, int cur_dist) {
	dist[u] = min(dist[u], cur_dist);
	for (auto v : adj[u]) {
		if (v == fa)
			continue;
		dfs_dist(v, u, cur_dist + 1);
	}
}

void solve() {
	cin >> n >> k;
	adj.resize(0);
	adj.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 1e18;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fill(dist.begin(), dist.end(), 1e18);
			dfs_dist(i, 0, 0);
			dfs_dist(j, 0, 0);
			ans = min(ans, *max_element(dist.begin() + 1, dist.end()));
		}
	}
	cout << ans << endl;
	return;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T;
	cin >> T >> T;
	while (T--) {
		solve();
	}
	return 0;
}