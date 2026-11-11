#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 10;
const ll INF = 2e18;
int test, n, m, d, q;
ll w[N], dis[510][510];
vector<pair<ll, ll>> way[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> test >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		ll x, y;
		for (int j = 1; j <= k; j++) {
			cin >> x >> y;
			way[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int)way[i].size(); j++) {
			for (int k = j + 1; k < (int)way[i].size(); k++) {
				ll u = way[i][j].first, v = way[i][k].first, w = way[i][j].second + way[i][k].second;
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
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
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		ll res = INF;
		for (int j = 0; j < (int)way[x].size(); j++) {
			for (int k = 0; k < (int)way[y].size(); k++) {
				ll u = way[x][j].first, v = way[y][k].first, w = way[x][j].second + way[y][k].second;
				res = min(res, dis[u][v] + w);
			}
		}
		cout << res + w[x] + w[y] << '\n';
	}
	return 0;
}
