#include <bits/stdc++.h>
using namespace std;
long long dis[3000005], n, m, s, c, d, q, a[505][10005], t[505][10005];
bool vis[3000005];
long long anss[1005][1005];

struct node {
	long long x, y;
};
vector<node>e[3000005];

void dfskl() {
	priority_queue<pair<int, int>>pq;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].x;
			int w = e[u][i].y;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
			}
			pq.push({-dis[v], v});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		long long w;
		cin >> w;
		e[i].push_back({i + m, w});
		e[i + m].push_back({i, w});
	}
	for (int i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			e[m + a[i][j]].push_back({m * (i + 1) + a[i][j], t[i][j]});
			e[m * (i + 1) + a[i][j]].push_back({m + a[i][j], t[i][j]});
		}
		for (int j = 1; j <= k - 1; j++) {
			e[m * (i + 1) + a[i][j]].push_back({m * (i + 1) + a[i][j + 1], 0});
			e[m * (i + 1) + a[i][j + 1]].push_back({m * (i + 1) + a[i][j], 0});
		}
	}
	for (int i = 1; i <= q; i++) {
		long long u, v;
		cin >> u >> v;
		s = u;
		if (anss[u][v] != 0) {
			cout << anss[u][v] << "\n";
			continue;
		}
		dfskl();
		//cout << 1;
		for (int j = 1; j <= m; j++) {
			anss[u][j] = dis[j];
			anss[j][u] = dis[j];
		}
		cout << dis[v] << "\n";
	}
	return 0;
}