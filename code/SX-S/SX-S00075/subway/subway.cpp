#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 505;
const int D = 30;
const int Q = 1e5+5;
const int K = 5e5+5;
int c, n, m, d, q;
int a, t, k, w[K], x[Q], y[Q];

struct node {
	int to, next, w;
} edge[K * 2];
int head[K], tot = 0;

void add(int u, int v, int cost) {
	edge[++tot].next = head[u];
	edge[tot].to = v;
	edge[tot].w = cost;
	head[u] = tot;
}
int dist[N + K];
priority_queue<pii, vector<pii>, greater<pii>> p;

int dij(int s, int ed) {
	memset(dist, 0x3f, sizeof(dist));
	p.push(make_pair(0, s));
	dist[s] = 0;
	while (!p.empty()) {
		pii z = p.top();
		p.pop();
		int u = z.second;
		for (int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			if (dist[v] > dist[u] + edge[i].w) {
				dist[v] = dist[u] + edge[i].w;
				p.push(make_pair(-dist[v], v));
			}
		}
	}
	return dist[ed];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		//第i条线，编号为m+i
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			//这条线上的站点
			scanf("%d%d", &a, &t);
			add(a, m + i, t);
			add(m + i, a, t);
//			printf("add(%d,%d,%d)\nadd(%d,%d,%d)\n", a, m + i, t, m + i, a, t);
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", dij(x[i], y[i]) + w[x[i]] + w[y[i]]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3
1 5 2 7 4 6
3
2 3 3 4 5 7
1 3
1 2
*/