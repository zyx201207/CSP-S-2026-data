#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int maxm = 5e5 + 10;
const long long INF = 1e18;
int c, n, m, d, q;
long long w[maxm], dis[maxn][maxn];
vector<pair<long long, long long>> g[maxm];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k, a, t;
		cin >> k;
		for(int j = 0; j < k; j++) {
			cin >> a >> t;
			g[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			dis[i][j] = dis[j][i] = INF;
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		int cnt = g[i].size();
		for(int j = 0; j < cnt; j++) {
			for(int k = j + 1; k < cnt; k++) {
				int x = g[i][j].first, y = g[i][k].first;
				long long z = g[i][j].second + g[i][k].second;
				dis[x][y] = dis[y][x] = min(dis[x][y], z);
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
	/*
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cerr << dis[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	while(q--) {
		int st, ed;
		long long ans = INF;
		cin >> st >> ed;
		for(int i = 0; i < g[st].size(); i++) {
			for(int j = 0; j < g[ed].size(); j++) {
				int x = g[st][i].first, y = g[ed][j].first;
				long long z = g[st][i].second + g[ed][j].second + dis[x][y];
				ans = min(ans, z + w[st] + w[ed]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
