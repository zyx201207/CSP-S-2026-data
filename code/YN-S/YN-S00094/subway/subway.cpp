#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 505;
const ll INF = 4e18;

ll dist[MAXN][MAXN];
vector<pair<int, ll>> at[500005];
ll w[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);

	for (int i = 1; i <= m; ++i)
		scanf("%lld", &w[i]);

	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int a;
			ll t;
			scanf("%d %lld", &a, &t);
			at[a].push_back({i, t});
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j] = (i == j ? 0 : INF);
	for (int v = 1; v <= m; ++v) {
		int sz = (int)at[v].size();
		for (int i = 0; i < sz; ++i) {
			for (int j = i + 1; j < sz; ++j) {
				int x = at[v][i].first;
				int y = at[v][j].first;
				ll cost = at[v][i].second + at[v][j].second;
				if (cost < dist[x][y]) {
					dist[x][y] = dist[y][x] = cost;
				}
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (dist[i][k] >= INF)
				continue;
			for (int j = 1; j <= n; ++j) {
				if (dist[k][j] >= INF)
					continue;
				ll val = dist[i][k] + dist[k][j];
				if (val < dist[i][j])
					dist[i][j] = val;
			}
		}
	}

	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);

		if (x == y) {
			puts("0");
			continue;
		}

		ll ans = INF;
		for (auto &p : at[x]) {
			int i = p.first;
			ll ti = p.second;
			for (auto &r : at[y]) {
				int j = r.first;
				ll tj = r.second;
				if (dist[i][j] >= INF)
					continue;
				ll cur = w[x] + ti + dist[i][j] + tj + w[y];
				if (cur < ans)
					ans = cur;
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
