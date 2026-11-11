#include<bits/stdc++.h>
#define pii pair<int, int> 
using namespace std;
const int MAXN = 505, MAXM = 505, MAXD = 25; 
int c, n, m, d, q; // 测试点，线路数，站数，最多换乘，计划数 
int w[MAXM];
int k, a, t; // i 号线：站数，第 j 站，第 j 站展厅到 i 号线站台的时间 
int x, y;
struct edge {
	int to, val;
};
struct cmp {
	bool operator ()(edge x, edge y) {
		return x.val > y.val;
	}
};
vector<edge> G[MAXM * MAXD]; // 第 i 站（i:站厅，km + i: k号线的站台） 
bool vis[MAXM * MAXD];
int dis[MAXM * MAXD][MAXM * MAXD];
void dijkstra(int x) {
	priority_queue<edge, vector<edge>, cmp> pq;
	pq.push({x, 0});
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= (n + 1) * m; i++) dis[x][i] = 1e9;
	dis[x][x] = 0;
	vis[x] = true;
	while (!pq.empty()) {
		int u = pq.top().to;
		pq.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].to, w = G[u][i].val;
			if (!vis[v] && dis[x][u] + w < dis[x][v]) {
				dis[x][v] = dis[x][u] + w;
				vis[v] = true;
				pq.push({v, dis[x][v]});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int last = a;
			scanf("%d%d", &a, &t);
			G[a].push_back({i * m + a, t});
			G[i * m + a].push_back({a, t});
			if (j > 1) {
				G[i * m + last].push_back({i * m + a, 0});
				G[i * m + a].push_back({i * m + last, 0});
			}
		}
	}
	for (int i = 1; i <= m; i++) dijkstra(i);
	while (q--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", w[x] + dis[x][y] + w[y]);
	}
	return 0;
}
