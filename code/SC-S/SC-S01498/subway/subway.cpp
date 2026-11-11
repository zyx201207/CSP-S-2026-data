#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
const int maxn = 2e3+5;
struct bb {
	int u, v, w, next;
} bb[maxn];
int tot, head[maxn];
void read(int u, int v, int w) {
	bb[++tot].u = u;
	bb[tot].v = v;
	bb[tot].w = w;
	bb[tot].next = head[u];
	head[u] = tot;
}
int dq[maxn], sta[maxn];
struct point {
	int node, dis;
	point(int a, int b) {
		node = a, dis = b;
	}

	bool operator<(point a)const {
		return dis > a.dis;
	}
};
priority_queue<point>q1;
int dis[maxn][maxn];
int f[maxn];
void djs(int x) {
	memset(dis[x], 0x3f, sizeof(dis[x]));
	memset(f, 0, sizeof(f));
	dis[x][x] = 0;
	q1.push({x, 0});
	while (!q1.empty()) {
		int u = q1.top().node;
		int w = q1.top().dis;
		q1.pop();
		if (f[u]) {
			continue;
		}
		f[u] = 1;
		for (int i = head[u]; i != 0; i = bb[i].next) {
			int v = bb[i].v;
			if (dis[x][v] >= w + bb[i].w + dq[u]) {
				dis[x][v] = w + bb[i].w + dq[u];
				q1.push({v, dis[x][v]});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &sta[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; ++j) {
			int v, w;
			scanf("%d%d", &v, &w);
			if (v == i) {
				dq[v] = w;
			} else {
				read(i, v, w);
				read(v, i, w);
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		djs(i);
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", dis[x][y] + sta[x] + sta[y]);
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

0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
*/