#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7, M = 507;
int C, n, m, d, q, w[N];
int dis[M][M];
vector<pair<int, int> > g[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int num, v, w;
		cin >> num;
		while (num--) {
			cin >> v >> w;
			g[v].push_back({i, w});
		}
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < g[i].size(); ++j) {
			int v1 = g[i][j].first, w1 = g[i][j].second;
			for (int k = j + 1; k < g[i].size(); ++k) {
				int v2 = g[i][k].first, w2 = g[i][k].second;
				dis[v1][v2] = dis[v2][v1] = min(dis[v1][v2], w1 + w2);
			}
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int x, y, ans = 1e18;
		cin >> x >> y;
		for (auto e1 : g[x]) {
			int v1 = e1.first, w1 = e1.second;
			for (auto e2 : g[y]) {
				int v2 = e2.first, w2 = e2.second;
				ans = min(ans, w[x] + w[y] + w1 + w2 + dis[v1][v2]);
			}
		}
		cout << ans << '\n';
	}
}