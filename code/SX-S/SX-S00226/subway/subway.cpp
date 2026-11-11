#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
int w[500010];
vector<pair<int, int>> du[500010];

int dis[510][510];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

int quest(int x, int y) {
	int ans = 0x3f3f3f3f3f3f3f3f;
	for (auto u : du[x]) {
		for (auto v : du[y]) {
			ans = min(ans, dis[u.first][v.first] + u.second + v.second);
		}
	}
	return (ans + w[x] + w[y]);
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k, a, ti;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> a >> ti;
			du[a].push_back({i, ti});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		for (int u = 0; u < du[i].size(); u++) {
			for (int v = 0; v < du[i].size(); v++) {
				int w = du[i][u].second + du[i][v].second;
				dis[du[i][u].first][du[i][v].first] = min(dis[du[i][u].first][du[i][v].first], w);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	floyd();
	int x, y;
	while (q--) {
		cin >> x >> y;
		cout << quest(x, y) << '\n';
	}
	return 0;
}
