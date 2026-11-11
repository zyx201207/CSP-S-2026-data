#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 5e5 + 5;
int w[N], test_c, n, m, d, Q, dis[505][505];
vector <pair <int, int>> line[N], e[N], subway[N];
signed main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	in >> test_c >> n >> m >> d >> Q;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) in >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; in >> k;
		dis[i][i] = 0;
		while (k--) {
			int v, w; in >> v >> w;
			line[i].push_back({v, w}), subway[v].push_back({i, w});
		}
	}
	for (int s = 1; s <= m; s++)
		for (int i = 0; i < subway[s].size(); i++) {
			int u = subway[s][i].first, uw = subway[s][i].second;
			for (int j = 0; j < i; j++) {
				int v = subway[s][j].first, vw = subway[s][j].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], uw + vw);
			}
		}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (Q--) {
		int ans = 1e18, s, t; in >> s >> t;
		for (pair <int, int> spii : subway[s]) {
			int u = spii.first, uw = spii.second;
			for (pair <int, int> tpii : subway[t]) {
				int v = tpii.first, vw = tpii.second;
				ans = min(ans, vw + uw + dis[u][v]);
			}
		}
		out << w[s] + w[t] + ans << '\n';
	}
	return 0;
}