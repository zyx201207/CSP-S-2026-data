#include <bits/stdc++.h>

using namespace std;

vector<int> get_path(const vector<int>& deg, vector<int>& to) {
	int n = deg.size() - 1;
	vector<int> fa(n), dep(n);

	auto dfs = [&](auto&& self, int u) -> void {
		for (int i = deg[u]; i < deg[u + 1]; i++) {
			int v = to[i];
			if (v == fa[u]) {
				continue;
			}
			fa[v] = u;
			dep[v] = dep[u] + 1;
			self(self, v);
		}
	};

	fa[0] = -1, dep[0] = 0;
	dfs(dfs, 0);
	int p = max_element(dep.begin(), dep.end()) - dep.begin();
	fa[p] = -1, dep[p] = 0;
	dfs(dfs, p);
	int q = max_element(dep.begin(), dep.end()) - dep.begin();
	vector<int> path;
	path.reserve(n);
	for (int x = q; x != -1; x = fa[x]) {
		path.push_back(x);
	}
	return path;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int c, t, n, k;
	cin >> c >> t;

	while (t--) {
		cin >> n >> k;
		vector<array<int, 2>> e(n - 1);
		vector<int> deg(n + 1);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v;
			e[i] = {--u, --v};
			deg[u]++, deg[v]++;
		}
		for (int i = 0; i < n; i++) {
			deg[i + 1] += deg[i];
		}
		vector<int> to((n - 1) * 2);
		for (int i = 0; i < n - 1; i++) {
			int u = e[i][0], v = e[i][1];
			to[--deg[u]] = v;
			to[--deg[v]] = u;
		}
		
		auto path = get_path(deg, to);
		vector<int> len(n), slen(n), up(n), dp(n);

		auto check = [&](int m) {
			auto dfs1 = [&](auto&& self, int u, int fa) -> void {
				len[u] = slen[u] = dp[u] = 0;
				for (int i = deg[u]; i < deg[u + 1]; i++) {
					int v = to[i];
					if (v == fa) {
						continue;
					}
					self(self, v, u);
					if (len[v] + 1 > len[u]) {
						slen[u] = len[u];
						len[u] = len[v] + 1;
					} else {
						slen[u] = max(slen[u], len[v] + 1);
					}
					dp[u] += dp[v];
				}
				dp[u] += len[u] >= m;
			};

			int cost;

			auto dfs2 = [&](auto&& self, int u, int fa) -> void {
				for (int i = deg[u]; i < deg[u + 1]; i++) {
					int v = to[i];
					if (v == fa) {
						continue;
					}
					up[v] = max(up[u], len[v] + 1 == len[u] ? slen[u] : len[u]) + 1;
					self(self, v, u);
				}
				if (up[u] <= m) {
					cost = min(cost, dp[u] + (len[u] < m));
				}
			};

			auto chk = [&](int x, int y) {
				dfs1(dfs1, x, y);
				up[x] = 0, cost = k + 1;
				dfs2(dfs2, x, y);
				if (cost > k) {
					return false;
				}
				int tmp = cost;
				dfs1(dfs1, y, x);
				up[y] = 0, cost = k + 1;
				dfs2(dfs2, y, x);
				return tmp + cost <= k;
			};

			if (c <= 8 && n <= 1000) {
				for (int i = 0; i < n - 1; i++) {
					if (chk(e[i][0], e[i][1])) {
						return true;
					}
				}
			} else {
				int L = path.size() - 1;
				int i = L / 2;
				for (int r = 0; r < 3; r++) {
					if (i + r < L && chk(path[i + r], path[i + r + 1])) {
						return true;
					}
					if (i - r > 0 && chk(path[i - r], path[i - r - 1])) {
						return true;
					}
				}
			}
			return false;
		};
		
		int l = 0, r = n, ans = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cout << ans << '\n';
	}

	// cerr << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

/*
chun ai zhan shi zrr
*/