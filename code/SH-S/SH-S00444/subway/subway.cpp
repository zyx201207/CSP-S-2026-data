# include <iostream>
# include <algorithm>
# include <cstdio>
# include <queue>
# include <vector>
# include <map>
# include <cstring>

typedef long long LL;
const int NR = 5e5 + 10;
int N, M, S, E, T, L, C, D, Q;
struct node{
	int v, w;
};
int w[NR], cnt[NR];
LL dis[510][510];
std::vector <node> g[NR * 2 + 10];

void floyd() {
	for (int k = 1; k <= L; k++) {
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= L; j++) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void add_edge(int u, int v, int w) {
	g[u].push_back({v, w});
	g[v].push_back({u, w});
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &L, &N, &D, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", w + i);
	}
	for (int i = 1; i <= L; i++) { // L lines
		scanf("%d", cnt + i);
		for (int j = 1; j <= cnt[i]; j++) {
			int x = 0, y = 0;
			scanf("%d", &x); 
			scanf("%d", &y);
			add_edge(x + NR, i, y);
		}
	}
	// build dis between lines
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= L; i++) dis[i][i] = 0;
	for (int i = NR + 1; i <= N + NR; i++) {
		for (int uu = 0; uu < g[i].size(); uu++) {
			for (int vv = uu + 1; vv < g[i].size(); vv++) {
				int u = g[i][uu].v, w1 = g[i][uu].w;
				int v = g[i][vv].v, w2 = g[i][vv].w;
				dis[u][v] = std::min(dis[u][v], (LL)(w1 + w2));
				dis[v][u] = dis[u][v];
			}
		}
	}
	// build up
	floyd();

	while (Q--) {	// q <= 1e5
		scanf("%d%d", &S, &T); 
		S += NR; T += NR;
		LL ans = 9e18;
		for (int uu = 0; uu < g[S].size(); uu++) {
			for (int vv = 0; vv < g[T].size(); vv++) {
				int u = g[S][uu].v, w1 = g[S][uu].w;
				int v = g[T][vv].v, w2 = g[T][vv].w;
				ans = std::min(ans, dis[u][v] + (LL)(w1 + w2));
			}
		}
		printf("%lld\n", ans + (LL)(w[S - NR] + w[T - NR]));
	}
	return 0;
}
