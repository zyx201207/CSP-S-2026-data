#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[550005];
vector<pair<int, int> > g[550005];
int dis[5005][5005];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			g[m + i].push_back({a, t});
			g[a].push_back({m + i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; i++) {
		for (pair<int, int> v : g[i]) {
			for (pair<int, int> k : g[i]) {
				dis[v.first - m][k.first - m] = min(dis[v.first - m][k.first - m], v.second + k.second); // g2[v.first].push_back({k.first, v.second + k.second});
			}
		}
	} // O(md^2)
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	} // O(n^3)
	while (q--) {
		int u, v;
		cin >> u >> v;
		int ans = 1e18;
		for (pair<int, int> s : g[u]) {
			for (pair<int, int> t : g[v]) {
				ans = min(ans, dis[s.first - m][t.first - m] + s.second + t.second);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
}
