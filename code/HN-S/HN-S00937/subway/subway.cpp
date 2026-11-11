#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 5e5 + 10, kMaxM = 510, kInf = 1e18;

int w[kMaxN], dis[kMaxM][kMaxM], c, n, m, d, q;
vector<pair<int, int> > e[kMaxN];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = i == j ? 0 : kInf;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, x, y; j <= k; j++) {
			cin >> x >> y, e[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			for (int k = 0; k < e[i].size(); k++) {
				if (e[i][j].first != e[i][k].first) {
					dis[e[i][j].first][e[i][k].first] = min(dis[e[i][j].first][e[i][k].first], e[i][j].second + e[i][k].second);
				}
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int x, y; q--;) {
		cin >> x >> y;
		int ans = kInf;
		for (int i = 0; i < e[x].size(); i++) {
			for (int j = 0; j < e[y].size(); j++) {
				ans = min(ans, e[x][i].second + e[y][j].second + dis[e[x][i].first][e[y][j].first]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
