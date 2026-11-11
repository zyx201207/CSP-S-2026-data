#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector<int> g[1000005];
int ok[1000005], ps[1000005];
int dfs(int u, int fa) {
	if (ok[u]) return 0;
	int ans = 1e18;
	for (int v : g[u]) {
		if (v == fa) continue;
		ans = min(ans, dfs(v, u) + 1);
	}
	return ans;
}
void check(int u, int fa) {
	ps[u] = 1;
	for (int v : g[u]) {
		if (v == fa) continue;
		if (ok[v]) check(v, u);
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 1e18;
		for (int i = 2; i < (1 << n) * 2; i += 2) {
			if (__builtin_popcount(i) != k) continue;
			for (int j = 1; j <= n; j++) {
				ps[j] = 0;
				ok[j] = (i >> j) & 1;
			}
			int ltk = 0;
			for (int j = 1; j <= n; j++) {
				if (!ps[j] && ok[j]) {
					ltk++;
					check(j, 0);
				}
			}
			if (ltk <= 2) {
				int Ans = 0;
				for (int j = 1; j <= n; j++) {
					Ans = max(Ans, dfs(j, 0));
				}
				ans = min(ans, Ans);
			}
		}
		for (int i = 1; i <= n; i++) g[i].clear();
		cout << ans << '\n';
	}
}
