#include <bits/stdc++.h>
using namespace std;

int c, t, n, k;
vector<int> tree[100];
bool choo[100];
bool vis[100];
int dis[100];
int ans;

void dfs1(int u) {
	for (int& v : tree[u]) {
		if (choo[v] && !vis[v]) {
			vis[v] = 1;
			dfs1(v);
		}
	}
}

void dfs2(int u, int fa) {
	for (int& v : tree[u]) {
		if (v != fa) {
			dis[v] = dis[u] + 1;
			dfs2(v, u);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		ans = 100;
		fill(tree + 1, tree + n + 1, vector<int>(0));
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		for (int S = 0; S < (1 << n); S++) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (S & (1 << (i - 1))) {
					cnt++;
				}
			}
			if (cnt != k) {continue;}
			memset(choo, 0, sizeof choo);
			for (int i = 1; i <= n; i++) {
				if (S & (1 << (i - 1))) {
					choo[i] = 1;
				}
			}
			int part = 0;
			memset(vis, 0, sizeof vis);
			for (int i = 1; i <= n; i++) {
				if (choo[i] && !vis[i]) {
					vis[i] = 1;
					part++;
					dfs1(i);
				}
			}
			if (part > 2) {continue;}
			int res = 0;
			for (int i = 1; i <= n; i++) {
				if (!choo[i]) {
					memset(dis, 0, sizeof dis);
					dfs2(i, 0);
					int minn = 100;
					for (int j = 1; j <= n; j++) {
						if (choo[j]) {
							minn = min(minn, dis[j]);
						}
					}
					if (minn < 100) {
						res = max(res, minn);
					}
				}
			}
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
	return 0;
}

