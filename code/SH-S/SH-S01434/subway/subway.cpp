#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[1005], k[505], a[505][1005];
int t[505][1005];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	if (c >= 7 && c <= 11) {
		int dis[1005][1005];
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; i++) dis[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			if (k[i] == 1) {
				cin >> a[i][1] >> t[i][1];
			} else {
				cin >> a[i][1] >> t[i][1] >> a[i][2] >> t[i][2];
				int u = a[i][1], v = a[i][2];
				dis[u][v] = min(t[i][1] + t[i][2], dis[u][v]);
				dis[v][u] = min(t[i][1] + t[i][2], dis[v][u]);
			}
		}
		for (int g = 1; g <= m; g++) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= m; j++) {
					dis[i][j] = min(dis[i][j], dis[i][g] + dis[g][j]);
				}
			}
		}
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			cout << (x == y ? 0 : dis[x][y] + w[x] + w[y]) << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			int u, v;
			for (int j = 1; j <= k[i]; j++) {
				cin >> u >> v;
			}
		}
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			cout << (x == y ? 0 : w[x] + w[y]) << '\n';
		}
	}
	return 0;
}
