#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, M = 5e5 + 5, Q = 1e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q, w[M], k[N], x[Q], y[Q];
vector<pair<int, int>> a[M];

int dis[N][N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];

		int tmpa, tmpb;
		for(int j = 1; j <= k[i]; j++) {
			cin >> tmpa >> tmpb;
			a[tmpa].push_back({i, tmpb});
		}
	}
	for(int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}

	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}

	for(int _ = 1; _ <= m; _++) {
		for(const auto &i : a[_]) {
			for(const auto &j : a[_]) {
				dis[i.first][j.first] = min(dis[i.first][j.first], i.second + j.second);
			}
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int _ = 1; _ <= q; _++) {
		int ans = INF;

		for(const auto &i : a[x[_]]) {
			for(const auto &j : a[y[_]]) {
				ans = min(ans, i.second + dis[i.first][j.first] + j.second);
			}
		}

		ans += w[x[_]] + w[y[_]];

		cout << ans << "\n";
	}

	return 0;
}