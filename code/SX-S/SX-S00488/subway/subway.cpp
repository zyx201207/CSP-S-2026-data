#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 510, Q = 1e5 + 10;
int n, m, d, q, w[N], a[N];
int p[N][M]; // p[i][j]表示编号为i的点在路线j上从站台到大厅的时间
int dis[5010][5010], c[5010][5010]; // c[i][j]表示i
bool vis[N][30];
vector <pair <int, int> > g[N];
priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> > >, greater <pair <int, pair <int, int> > > > pq;
// pq分别指到达最短时间，当前点编号，到达当前点最短路线的最后一条边的颜色
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	pq.push(make_pair(0, make_pair(s, 21)));
//	for (int i = 1; i <= d; i++)
//		if (p[s][i]) pq.push(make_pair(0, make_pair(s, i)));
	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		int step = now.first, u = now.second.first, CO = now.second.second;
		if (vis[u][CO]) continue;
		vis[u][CO] = 1;
		for (auto it : g[u]) {
			int v = it.first, co = it.second;
			if (dis[s][v] > dis[s][u] + (co == CO ? 0 : p[u][CO] + p[u][co])) {
				dis[s][v] = dis[s][u] + (co == CO ? 0 : p[u][CO] + p[u][co]);
				c[s][v] = co;
				pq.push(make_pair(dis[s][v], make_pair(v, co)));
			}
		}
	}
}
inline void solve() {
	memset(dis, 0x3f, sizeof(dis));
	cin >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) cin >> w[i], dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int k, t; cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t;
			p[a[j]][i] = t;
		}
		for (int j = 1; j <= k; j++)
			for (int l = 1; l <= k; l++) g[a[l]].push_back(make_pair(a[j], i)), g[a[j]].push_back(make_pair(a[l], i));
	}
	for (int i = 1; i <= n; i++) dijkstra(i);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
	while (q--) {
		int x, y; cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] + p[y][c[x][y]] << '\n';
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C; cin >> C;
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/