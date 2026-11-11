#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const long long N = 3e6+5, M = 505;
long long c, n, m, d, q, w[N], dis[M][M];
vector<pii> vt[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++)
		cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (long long j = 1; j <= k; j++) {
			long long x, y;
			cin >> x >> y;
			vt[x].push_back(make_pair(i, y));
		}
	}
	for (long long i = 0; i <= n; i++) {
		for (long long j = 0; j <= n; j++) {
			if (i != j)
				dis[i][j] = 1e18;
		}
	}
	for (long long i = 1; i <= m; i++) {
		long long id = vt[i].size();
		for (long long j = 0; j < id; j++) {
			for (long long k = j + 1; k < id; k++) {
				long long xx = vt[i][j].first, yy = vt[i][k].first;
				dis[xx][yy] = vt[i][j].second + vt[i][k].second;
				dis[yy][xx] = vt[i][j].second + vt[i][k].second;
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			for (long long k = 1; k <= n; k++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = min(dis[j][i], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		long long x, y, ans = 1e18;
		cin >> x >> y;
		long long xx = vt[x].size(), yy = vt[y].size();
		for (long long i = 0; i < xx; i++) {
			for (long long j = 0; j < yy; j++) {
				long long xxx = vt[x][i].first, yyy = vt[y][j].first;
				ans = min(ans, vt[x][i].second + vt[y][j].second + dis[xxx][yyy]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
