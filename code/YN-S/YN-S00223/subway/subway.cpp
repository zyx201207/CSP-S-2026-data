#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5 + 5;
const int M = 505;

int c, n, m, d, q, k[M];
ll dis[M][M];
ll w[N];
vector<pair<int, int> >g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f3f3f3f, sizeof dis);

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}


	for (int i = 1; i <= n; i++) {

		cin >> k[i];

		for (int j = 1; j <= k[i]; j++) {

			int a;
			ll t;
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}

	for (int i = 1; i <= m; i++) {

		for (auto u : g[i]) {
			int x1 = u.first;
			ll x2 = u.second;

			for (auto v : g[i]) {
				int y1 = v.first;
				ll y2 = v.second;

				if (u == v) {
					dis[x1][y1] = 0;
				}

				dis[x1][y1] = min(dis[x1][y1], x2 + y2);
			}
		}
	}

	for (int t = 1; t <= n; t++) {

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {

				dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
			}
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;

		for (auto u : g[x]) {
			for (auto v : g[y]) {
				ans = min(ans, dis[u.first][v.first] + u.second + v.second);

			}
		}

		cout << ans + w[x] + w[y] << "\n";
	}

	return 0;
}