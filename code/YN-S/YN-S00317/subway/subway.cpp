#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
using P = pair<long long, int>;

struct node {
	int v;
	long long w;
};
vector<node>g[2 * N];
int c, n, m, d, q;
long long a[N];
int vis[2 * N];
long long dist[2 * N];
long long ans;

void dijkstra(int start, int end) {
	dist[start] = 0;
	priority_queue<P, vector<P>, greater<P>>que;
	que.push(P{dist[start], start});
	vis[start] = 0;
	while (!que.empty()) {
		int u = que.top().second;
		que.pop();
		for (node e : g[u]) {
			int v = e.v;
			long long w = e.w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
			if (!vis[v]) {
				dist[v] = dist[u] + w;
				que.push(P{dist[v], v});
				vis[v] = 1;
			}
		}
	}
	cout << dist[end] + a[start] + a[end] << "\n";
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q; //c表示测试点序号 n表示地铁线数 m表示站点数 d表示一个站点最多有d条线路 q表示询问次数
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {//O(Zk);
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int to;
			long long t;
			cin >> to >> t;
			g[m + i].emplace_back(node{to, t});
			g[to].emplace_back(node{m + i, t});
		}
	}
//	for (int i = 1; i <= m + n; i++) {
//		for (int j = 0; j < g[i].size(); j++) {
//			cout << i << "-" << g[i][j].v << ":" << g[i][j].w << "\n";
//		}
//	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		memset(vis, 0, sizeof(vis));
//		for (int i = 1; i <= m + n; i++) {//O(q(m+n));
//			dist[i] = 1e9;
//		}
		ans = 3e18;
		dijkstra(u, v);
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
*/