#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, T;
int n, d;
vector<vector<int>> adj;
vector<int> dist;
vector<int> sz;

void dfs_dist(int u, int cur_dist) {
//	cout << u << " " << cur_dist << endl;
	if (dist[u] < cur_dist) {
		return;
	} else if (dist[u] == cur_dist) {
		sz[u]++;
	} else {
		sz[u] = 1;
		dist[u] = cur_dist;
	}

	for (auto v : adj[u]) {
		dfs_dist(v, cur_dist + 1);
	}
}

void solve() {
	cin >> n >> d;
	if (n > 7000) {
		cout << "0\n";
		return;
	}
	adj.resize(0);
	adj.resize(n + 1, {});
	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (vec[j] - vec[i] <= d) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	dist.resize(n + 1);
	sz.resize(n + 1);
	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (auto v : adj[i]) {
//
//		}
//	}
	for (int i = 1; i <= n; i++) {
		fill(dist.begin(), dist.end(), 1e18);
		dist[i] = 0;
		fill(sz.begin(), sz.end(), 0);
		dfs_dist(i, 0);

		for (int j = 1; j <= n; j++) {
//			cout << sz[j] << ' ';
			if (j == i)
				continue;
			ans += (sz[j] == 2);
		}
//		cout << endl;
	}
	cout << ans / 2 << endl;
	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}