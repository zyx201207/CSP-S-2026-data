/*
by Zhangshujun 15:20
exp:100pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 505;
constexpr int MAXM = 5e5 + 5;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
struct node {
	int u, dis;
	inline bool operator < (const node& b) const {
		return dis > b.dis;
	}
};
int w[MAXM];
vector<pair<int, int>> Station[MAXM];
int dist[MAXN][MAXN];
int c, n, m, d, q;
signed main() {
#ifndef DEBUG
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#else
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	freopen(".\\subway\\subway.in", "r", stdin);
//	freopen(".\\subway\\subway.out", "w", stdout);
#endif
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i], Station[i].reserve(d);
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 1, a, t; j <= k; ++j) {
			cin >> a >> t, Station[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j] = INF;
	for (int i = 1; i <= n; ++i)
		dist[i][i] = 0;

	for (int i = 1; i <= m; ++i) {
		for (const auto &sta1 : Station[i])
			for (const auto &sta2 : Station[i]) {
				if (sta1.first == sta2.first) continue;
				int u = sta1.first, v = sta2.first, w = sta1.second + sta2.second;
				dist[u][v] = min(dist[u][v], w);
			}

	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	int l, r;
	while (q--) {
		cin >> l >> r;
		int ans = INF;
		for (const auto &sta1 : Station[l])
			for (const auto &sta2 : Station[r]) {
				int u = sta1.first, v = sta2.first, w = sta1.second + sta2.second;
				ans = min(ans, dist[u][v] + w);
			}
		cout << ans + w[l] + w[r] << '\n';
	}
	return 0;
}