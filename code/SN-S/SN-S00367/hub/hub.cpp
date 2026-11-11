// SN-S00367 李天江 西安交通大学附属中学
#include <bits/stdc++.h>

using namespace std;
int n, k;
array<array<int, 1005>, 1005> dis, dp;
array<int, 1000005> depth, tree_size, tmp;
array<vector<int>, 1000005> e;

void dfs(int u, int fa, int step, int rt) {
	dis[rt][u] = step;
	for (const int v: e[u]) {
		if (v != fa) {
			dfs(v, u, step + 1, rt);
		}
	}
}

void calc(int u, int fa) {
	for (int i = 1; i <= k; ++i) {
		dp[u][i] = 0;
	}
	dp[u][0] = 1;

	tree_size[u] = 1;

	for (const int v: e[u]) {
		if (v != fa) {
			depth[v] = depth[u] + 1;
			calc(v, u);

			dp[u][0] = max(dp[u][0], dp[v][0] + 1);
			for (int i = 1; i <= tree_size[u] + tree_size[v]; ++i) {
				tmp[i] = 2e9;
			}

			for (int i = 1; i <= tree_size[u]; ++i) {
				for (int j = 0; j <= tree_size[v] && i + j <= k; ++j) {
					tmp[i + j] = min(tmp[i + j], max(dp[u][i], dp[v][j]));
				}
			}

			tree_size[u] += tree_size[v];
			for (int i = 1; i <= tree_size[u]; ++i) {
				dp[u][i] = tmp[i];
			}
		}
	}
}

void solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		e[i].clear();
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	if (n == k) {
		cout << "0\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		dfs(i, 0, 0, i);
	}

	int ans = 2e9;

	/*calc(1, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			clog << dp[i][j] << ' ';
		}
		clog << '\n';
	}
	return;*/

	for (int i = 1; i <= n; ++i) {
		for (const int j: e[i]) {
			if (i < j) {
//				clog << i << ' ' << j << '\n';

				depth[i] = depth[j] = 0;
				calc(i, j);
				calc(j, i);

				for (int u = 1; u <= n; ++u) {
					if (depth[u] == dis[i][u]) {
						int term = 0;
						for (int v = 1; v <= n; ++v) {
							if (depth[v] != dis[j][v] && depth[v] - depth[u] != dis[u][v]) {
								term = max(term, min(dis[u][v], dis[j][v]));
							}
						}

						for (int x = 1; x < k; ++x) {
							ans = min(ans, max({dp[u][x], dp[j][k - x], term}));
						}
					} else {
						int term = 0;
						for (int v = 1; v <= n; ++v) {
							if (depth[v] != dis[i][v] && depth[v] - depth[u] != dis[u][v]) {
								term = max(term, min(dis[u][v], dis[i][v]));
							}
						}

						for (int x = 1; x < k; ++x) {
							ans = min(ans, max({dp[u][x], dp[i][k - x], term}));
						}
					}
				}

				int term_i = 0, term_j = 0;
				for (int u = 1; u <= n; ++u) {
					if (depth[u] != dis[i][u]) {
						term_i = max(term_i, dis[i][u]);
					}

					if (depth[u] != dis[j][u]) {
						term_j = max(term_j, dis[j][u]);
					}
				}

//				clog << term_i << ' ' << term_j << ' ' << dp[i][k] << ' ' << dp[j][k] << '\n';
				ans = min({ans, max(term_i, dp[i][k]), max(term_j, dp[j][k])});
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_c, t;
	cin >> test_c >> t;
	for (int _ = 0; _ < t; ++_) {
		solve();
	}
	return 0;
}
