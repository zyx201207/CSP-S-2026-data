#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct info {
	int to;
	ll w;
};

int c, n, m, d, q;
ll w[505];
ll tt[500005][505];
ll dist[505][505];
bool b[505][505];
vector<info> edges[500005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			edges[i].push_back({a, t});
			tt[i][a] = t;
			tt[a][i] = t;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (auto ff : edges[i]) {
			int j = ff.to;
			int w1 = ff.w;
			for (auto fff : edges[i]) {
				int k = fff.to;
				int w2 = fff.w;
				if (j == k) {
					continue;
				}
				b[j][k] = true;
				b[k][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!b[i][j]) {
				dist[i][j] = -1;
			} else {
				dist[i][j] = 0;
			}
		}
		dist[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((dist[i][k] == -1) || (dist[j][k] == -1)) {
					continue;
				}
				dist[i][j] = min(dist[i][j], dist[i][k] + tt[i][k] + tt[k][i] + dist[k][j]);
			}
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;

		ll ans = w[x] + w[y];

		cout << ans + dist[x][y] << '\n';
	}
}
