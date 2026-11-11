#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5, M = 505;
int C, n, m, d, Q;
int w[N];
vector<pair<int, int>>v[N];
int dis[M][M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	memset(dis, 0x3f,sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		int k, a, t;
		cin >> k;
		while (k--) {
			cin >> a >> t;
			v[a].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < (int)v[i].size(); j++)
			for (int k = 0; k < j; k++) {
				auto p1 = v[i][j], p2 = v[i][k];
				int x = p1.first, y = p2.first;
				dis[x][y] = min(dis[x][y], p1.second + p2.second), dis[y][x] = dis[x][y];
			}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (Q--) {
		int x, y, ans = LONG_LONG_MAX;
		cin >> x >> y;
		for (int i = 0; i < (int)v[x].size(); i++)
			for (int j = 0; j < (int)v[y].size(); j++)
				ans = min(ans, dis[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
