#include<bits/stdc++.h>//44pts
#define int long long
using namespace std;
const int N = 5e3 + 5, inf = 1e18;
struct Edge {
	int v, w;
};
vector<Edge> g[N];
struct Node {
	int u, dis;
	bool operator<(const Node &i) const {
		return dis > i.dis;
	}
};
int c, n, m, d, q;
int w[N], k[N], a[N], t[N];
int dist[N][N];
bool vis[N];
void dij(int s) {
	for (int i = 1; i <= m; ++ i) {
		vis[i] = 0;
		dist[s][i] = inf;
	}
	priority_queue<Node> pq;
	pq.push({s, 0});
	dist[s][s] = 0;
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		int u = now.u, dis = now.dis;
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		for (Edge e : g[u]) {
			int v = e.v, w = e.w;
			if (dist[s][v] > dis + w) {
				dist[s][v] = dis + w;
				pq.push({v, dist[s][v]});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++ i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++ j) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k[i]; ++ j) {
			for (int p = j + 1; p <= k[i]; ++ p) {
				g[a[j]].push_back({a[p], t[p] + t[j]});
				g[a[p]].push_back({a[j], t[p] + t[j]});
			}
		}
	}
	for (int i = 1; i <= m; ++ i) {
		dij(i);
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}

