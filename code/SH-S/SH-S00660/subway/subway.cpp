// > < happy!
#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[500005];
vector <int> to[500505], wei[500505];
int dis[505][505];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for(int i = 1, k; i <= n; ++i) {
		cin >> k;
		for(int j = 1, x, y; j <= k; ++j) {
			cin >> x >> y;
			to[i].push_back(x + n);
			wei[i].push_back(y);
			to[x + n].push_back(i);
			wei[x + n].push_back(y);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i != j) {
				dis[i][j] = 1000000000000000000ll;
			}
		}
	}
	for(int i = n + 1; i <= n + m; ++i) {
		for(int x = 0; x < to[i].size(); ++x) {
			for(int y = x + 1; y < to[i].size(); ++y) {
				dis[to[i][x]][to[i][y]] = min(dis[to[i][x]][to[i][y]], wei[i][x] + wei[i][y]);
				dis[to[i][y]][to[i][x]] = min(dis[to[i][y]][to[i][x]], wei[i][x] + wei[i][y]);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				if(dis[j][k] > dis[j][i] + dis[i][k]) {
					dis[j][k] = dis[j][i] + dis[i][k];
				}
			}
		}
	}
	for(int i = 1, x, y; i <= q; ++i) {
		cin >> x >> y;
		int ans = 2000000000000000000ll;
		for(int j = 0; j < to[n + x].size(); ++j) {
			for(int k = 0; k < to[n + y].size(); ++k) {
				ans = min(ans, dis[to[n + x][j]][to[n + y][k]] + wei[n + x][j] + wei[n + y][k]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}