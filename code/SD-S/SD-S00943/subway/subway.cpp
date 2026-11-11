#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w;
const int MAX = 1.5e6 + 5;
int head[MAX], nxt[MAX], ver[MAX], edge[MAX], tot, dis[MAX], vis[MAX];
void add(int x, int y, int z) {
	++tot;
	ver[tot] = y;
	edge[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}

struct Q {
	int x = 0, y, i, ans;
} query[MAX];

void dijkstra(int start) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	dis[start] = 0;
	
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], z = edge[i];
			if (dis[y] > dis[x] + z) {
				dis[y] = dis[x] + z;
				pq.push({dis[y], y});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &w);
		add(i, m + i, w);
		add(m + i, i, w);
	}
	int k, u, v;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j) {
			scanf("%d%d", &u, &v);
			add(u + m, 2 * m + i, v);
			add(2 * m + i, u + m, v);
		}
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &query[i].x, &query[i].y);
		query[i].i = i;
	}
	sort(query + 1, query + 1 + q, [](const Q& a, const Q& b) { return a.x < b.x; } );
	for (int i = 1; i <= q; ++i) {
		if (query[i].x != query[i - 1].x) dijkstra(query[i].x);
		query[i].ans = dis[query[i].y];
	}
	sort(query + 1, query + 1 + q, [](const Q& a, const Q& b) { return a.i < b.i; } );
	for (int i = 1; i <= q; ++i) {
		printf("%d\n", query[i].ans);
	}
	return 0; 
}
