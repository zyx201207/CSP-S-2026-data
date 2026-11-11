//2026 CSP-S RP++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, n, m, d, Q, W[5005], dist[5005][5005], U[5005], tot, cnt, head[10005];
bool vis[5005];
queue<int> q;

struct Edge {
	int to, nxt, w;
} edge[10005];

void add(int u, int v, int w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].nxt = head[u];
	edge[cnt].w = w;
	head[u] = cnt;
}

void spfa(int x) {
	memset(dist[x], 0x3f, sizeof(dist[x]));
	dist[x][x] = 0;
	q.push(x);
	vis[x] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (dist[x][v] > dist[x][u] + edge[i].w) {
				dist[x][v] = dist[x][u] + edge[i].w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &T, &n, &m, &d, &Q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &W[i]);
	}
	tot = m;
	for (int i = 1, k; i <= n; i++) {
		scanf("%lld", &k);
		for (int j = 1, w; j <= k; j++) {
			scanf("%lld%lld", &U[j], &w);
			tot++;
			add(tot, U[j], w), add(U[j], tot, w);
			if (j != 1) {
				add(tot, tot - 1, 0), add(tot - 1, tot, 0);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		spfa(i);
	}
	for (int i = 1, x, y; i <= Q; i++) {
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", W[x] + W[y] + min(dist[y][x], dist[x][y]));
	}
	return 0;
}
