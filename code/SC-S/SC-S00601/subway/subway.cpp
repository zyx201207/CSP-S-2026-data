#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 5e5 + 1e3;
const int M = 1e3 + 100;
int c, n, m, d, q, x, y, k[N], u, t, w[N], dist[N];
int dist2[M][M];
bool vis[N];
vector<pii> G[N];
vector<pii> line[N];
priority_queue<pii, vector<pii>, less<pii>> pq;
inline void Dijkstra(int start) {
	for (int i = 1; i <= m + n; ++i)	vis[i] = false, dist[i] = 1e18;
	pq.push(make_pair(0, start)); dist[start] = 0;
	while (pq.size()) {
		int u = pq.top().second, now_dist = pq.top().first; pq.pop();
//		cerr << u << ' ' << now_dist << '\n';
		if (now_dist != dist[u])	continue;
		for (auto it : G[u]) {
			int v = it.first, w = it.second;
//			cerr << u << ' ' << v << ' ' << w << '\n';
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}
inline void init() {
	for (int i = 1; i <= n; ++i) {
		Dijkstra(i + m);
		for (int j = 1; j <= n; ++j)	dist2[i][j] = dist2[j][i] = dist[j + m];
	}
}
inline int getD(int x, int y) {
	int res = 1e18;
	for (auto i : line[x])	for (auto j : line[y]) {
		res = min(dist2[i.first][j.first] + i.second + j.second, res);
	} return res;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)	cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> u >> t;
			line[u].push_back(make_pair(i, t));
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (auto u : line[i]) {
			for (auto v : line[i]) {
				G[u.first + m].push_back(make_pair(v.first + m, u.second + v.second));
				G[v.first + m].push_back(make_pair(u.first + m, u.second + v.second));
			}
		}
	}
	init();
	while (q--) {
		cin >> x >> y;
		int add = w[x] + w[y];
		cout << add + getD(x, y) << '\n';
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