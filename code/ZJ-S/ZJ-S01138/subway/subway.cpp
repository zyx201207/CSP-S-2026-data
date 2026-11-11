#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N], k[N];
vector<pair<int, int>> g[N];
struct node {
	int u, d;
	bool operator < (const node& nd) const {
		return d > nd.d;
	}
};
bool vis[N];
int dis[N];
int dijkstra(int s, int e) {
	priority_queue<node> q;
	q.push({s, 0});
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	memset(vis, 0, sizeof vis);
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto to : g[u]) {
			int v = to.first;
			int w = to.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
//	for (int i = 1; i <= m + m + n; ++i) {
//		cout << dis[i] << ' ';
//	}
//	cout << endl;
	return dis[e];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	vector<vector<int> > a(n + 1, vector<int> (m + 1));
	vector<vector<int> > t(n + 1, vector<int> (m + 1));
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
		g[i + m].push_back({i, w[i]});
		g[i].push_back({i + m, w[i]});
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		int id = m + m + i;
		for (int j = 1; j <= m; ++j) {
			if (!a[i][j] && !t[i][j]) continue;
			g[id].push_back({a[i][j], t[i][j]});
			g[a[i][j]].push_back({id, t[i][j]});
		}
	}
//	for (int i = 1; i <= m + m + n; ++i) {
//		cout << i << ":\n";
//		for (auto v : g[i]) {
//			cout << v.first << ' ' << v.second << endl;
//		}
//		cout << endl;
//	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dijkstra(x + m, y + m) << endl;
	}
	return 0;
}