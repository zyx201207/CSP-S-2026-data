#include<bits/stdc++.h>

#define int long long

using namespace std;

int w[500005];
int id[500005][21], ti[500005][21], cnt[500005];
int dis[505][505];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			id[x][++cnt[x]] = i, ti[x][cnt[x]] = y;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= cnt[i]; j++)
			for (int k = j + 1; k <= cnt[i]; k++) {
				int x = id[i][j], y = id[i][k];
				dis[x][y] = dis[y][x] = min(dis[x][y], ti[i][j] + ti[i][k]);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (int i = 1; i <= cnt[x]; i++)
			for (int j = 1; j <= cnt[y]; j++)
				ans = min(ans, dis[id[x][i]][id[y][j]] + ti[x][i] + ti[y][j]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}