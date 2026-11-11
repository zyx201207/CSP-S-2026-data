#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 10, M = 1e3 + 10;
int c, n, m, d, q;
int w[M];
vector<pair<int, int>> G[M + N];
int dis[M][M + N], vis[M + N];

void dijkstra(int beg, int gol) {
	memset(vis, 0, sizeof vis);
	dis[beg][beg] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, beg});
	while(pq.size()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto edge : G[u]) {
			int d = edge.first, v = edge.second;
			if (d + dis[beg][u] < dis[beg][v]) {
				dis[beg][v] = d + dis[beg][u];
				pq.push({dis[beg][v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			G[a].push_back({t, m + i});
			G[m + i].push_back({t, a});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (dis[x][y] == 0x3f3f3f3f) dijkstra(x, y);
		cout << dis[x][y] + w[x] + w[y] << '\n';
	}
	return 0; 
}

