#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, n, m, d, q, w[N], k[N], dist[N], vis[N];
vector<pair<int, int>> e[N];
inline int dijkstra(int s, int t) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	q.push({0, s}), dist[s] = 0;
	while (q.size()) {
		int d = q.top().first, u = q.top().second; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		if (u == t) return dist[t];
//		cout << d << " " << u << "\n";
		for (auto it : e[u]) {
			int v = it.first, w = it.second;
			if (dist[v] > d + w) dist[v] = d + w, q.push({dist[v], v});
		}
	}
	return -1;
}
inline int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}
int main() {
//	freopen("subway3.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1, len; i <= n; i++) {
		len = read();
		for (int j = 1, x, y; j <= len; j++) 
			x = read(), y = read(), e[m + i].push_back({x, y}), e[x].push_back({m + i, y});
	}
	for (int i = 1, u, v; i <= q; i++) {
		u = read(), v = read();
		printf("%d\n", dijkstra(u, v) + w[u] + w[v]);
	}
	return 0;
}
/*
真难啊

坐地铁是真要了人命啊，好复杂，好麻烦

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
/*
17:00:48 测完小样例
17:09:03 测完前 3 个大样例
32 ~ 84pts
*/