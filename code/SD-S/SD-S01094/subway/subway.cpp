#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e6 + 10;
const int inf = 2e18;

int C, n, m, D, Q, tot, w[MAXN], dis[510][510];
vector<pair<int, int> > adj[MAXN], out[MAXN];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> C >> n >> m >> D >> Q;
	for (int i = 1; i <= m; i ++) cin >> w[i]; 
	for (int i = 1; i <= n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t; cin >> a >> t;
			out[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) dis[i][j] = inf;
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j < (int)out[i].size(); j ++) {
			for (int k = 0; k < (int)out[i].size(); k ++) {
				if (j == k) continue;
				int u = out[i][j].first, wu = out[i][j].second, v = out[i][k].first, wv = out[i][k].second;
				dis[u][v] = min(dis[u][v], wu + wv), dis[v][u] = min(dis[v][u], wu + wv);
			}
		}
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (dis[i][k] == inf || dis[k][j] == inf) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
//	}
//	cout << "--------------\n";
	while (Q --) {
		int st, ed; cin >> st >> ed;
		int ans = inf;
		for (int i = 0; i < (int)out[st].size(); i ++) {
			int v1 = out[st][i].first, w1 = out[st][i].second;
			for (int j = 0; j < (int)out[ed].size(); j ++) {
				int v2 = out[ed][j].first, w2 = out[ed][j].second;
				if (dis[v1][v2] != inf) {
//					cout << v1 << ' ' << v2 << ' ' << w1 << ' ' << w2 << ' ' << w1 + w2 + dis[v1][v2] << '\n';
					ans = min(ans, w1 + w2 + dis[v1][v2]);
				}
			}
		}
		cout << ans + w[st] + w[ed] << '\n';
	}
}
