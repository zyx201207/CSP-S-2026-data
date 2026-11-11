#include <bits/stdc++.h>
#define pk push_back
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
const int inf = 1e18;
int n, m, c, d, q;
int dis[N][N];
vector<pair<int, int>> g[M];
int w[M];
void build() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	int u, v;
	int tu, tv;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			u = g[i][j].first;
			tu = g[i][j].second;
			for (int k = j + 1; k < g[i].size(); k++) {
				v = g[i][k].first;
				tv = g[i][k].second;
//				cout << u << " <-> " << v << "  " << i << " " << tu << " "<< tv << "\n";
				dis[u][v] = min(dis[u][v], tu + tv);
				dis[v][u] = min(dis[v][u], tu + tv);
			}
		}
	}
	return ;
}
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}	
	return ;
}
void solve() {
	int x, y;
	cin >> x >> y;
	int ans = inf;
	int u, v;
	int tu, tv;
	for (int i = 0; i < g[x].size(); i++) {
		u = g[x][i].first;
		tu = g[x][i].second;
		for (int j = 0; j < g[y].size(); j++) {
			v = g[y][j].first;
			tv = g[y][j].second;
			ans = min(ans, tu + tv + dis[u][v]);
		}
	}
	cout << ans + w[x] + w[y] << "\n";
	return ;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int k, cur, t;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> cur >> t;
			g[cur].pk({i, t});
//			cout << "edge: " << cur << " " << i << " " << t << "\n";
		}
	}
	build();
	floyd();
	while (q--) {
		solve();
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
