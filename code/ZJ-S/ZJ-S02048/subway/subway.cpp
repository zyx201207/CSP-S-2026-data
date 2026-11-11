#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500001];
vector<pair<int, int>> g[501001];
vector<pair<int, int>> s2l[501001];
int sline(int x) { return n + x; }   // The number of the subway line
int dis[501][501];       // distance between lines

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for (int j = 1, u, w;j <= k;j++) {
			cin >> u >> w;
			//g[sline(i)].push_back({u, w});
			//g[u].push_back({sline(i), w});
			s2l[u].push_back({i, w});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1;i <= m;i++) {
		int x = s2l[i].size();
		for (auto p1 : s2l[i]) {
			for (auto p2 : s2l[i]) {
				if (p1 != p2) {
					dis[p1.first][p2.first] = p1.second + p2.second;
				} else {
					dis[p1.first][p2.first] = 0;
				}
			}
		}
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 1, st, ed;i <= q;i++) {
		cin >> st >> ed;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for (auto p1 : s2l[st]) {
			for (auto p2 : s2l[ed]) {
				ans = min(ans, p1.second + p2.second + dis[p1.first][p2.first]);
			}
		}
		cout << ans + w[st] + w[ed] << "\n";
	}
	return 0;
}
