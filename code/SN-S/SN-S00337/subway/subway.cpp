// by 0x0F
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3fll;
int w[500010];
vector<pair<int, int> > st[500010];
int dis[510][510];
void solve() {
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t; cin >> a >> t;
			st[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = dis[j][i] = inf;
	for (int i = 1; i <= m; i++) {
		int sz = st[i].size();
		for (int x = 0; x < sz; x++)
			for (int y = x + 1; y < sz; y++) {
				int &u = st[i][x].first, &v = st[i][y].first;
				int &vu = st[i][x].second, &vv = st[i][y].second;
				dis[u][v] = min(dis[u][v], vu + vv);
				dis[v][u] = min(dis[u][v], vu + vv);
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
//		cout << x << " " << y << endl;
		int ans = inf;
		for (int j = 0; j < st[x].size(); j++)
			for (int k = 0; k < st[y].size(); k++) {
				int &u = st[x][j].first, &v = st[y][k].first;
				int &vu = st[x][j].second, &vv = st[y][k].second;
//				cout << vu << " " << vv << " " << u << " " << v << " " << dis[u][v] << endl;
				ans = min(ans, w[x] + w[y] + vu + vv + dis[u][v]);
			}
		cout << ans << endl;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}
