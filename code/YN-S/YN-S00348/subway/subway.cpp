#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 2e3 + 5;
const int N = 505;
int c, n, m, d, q, w[M], a[N][M], t[N][M], k;
int x, y;
int dis[M][M];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] = LLONG_MAX;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for (int j = 1; j <= k; j++) {
			for (int p = j + 1; p <= k; p++) {
				dis[a[i][p]][a[i][j]] = t[i][j] + t[i][p];
				dis[a[i][j]][a[i][p]] = t[i][j] + t[i][p];
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX) {
					continue;
				}
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}