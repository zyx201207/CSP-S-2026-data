#include"bits/stdc++.h"
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5, inf = 1e18;
int c, n, m, d, q;
int w[M], k[N];
struct node {
	int v, w;
	bool operator< (const node &x) const {
		return w > x.w;
	}
};
vector<node>g[M + N];
vector<int>dis[1505];
vector<bool>vis[1505];
void dijkstra(int s, vector<int>&dis, vector<bool>&vis) {
	fill(dis.begin(), dis.end(), inf);
	dis[s] = 0;
	fill(vis.begin(), vis.end(), 0);
	priority_queue<node>q;
	q.push({s, 0});
	while (!q.empty()) {
		int u = q.top().v;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto [v, w] : g[u])
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) 
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 0, a, t; j < k[i]; j++) {
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	if (m <= 1000) {
		for (int i = 1; i <= m; i++) {
			dis[i].resize(m + n + 1);
			vis[i].resize(m + n + 1);
			dijkstra(i, dis[i], vis[i]);
//			for (int j = 1; j <= m + n; j++)
//				cout << dis[i][j] << ' ';
//			cout << '\n';
		}
		for (int i = 1, x, y; i <= q; i++) {
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << '\n';
		}
	}
	else {
		dis[1].resize(m + n + 1);
		vis[1].resize(m + n + 1);
		for (int i = 1, x, y; i <= q; i++) {
			cin >> x >> y;
			dijkstra(x, dis[1], vis[1]);
			cout << dis[1][y] + w[x] + w[y] << '\n';
		}
	}
	return 0;
}