#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, gt[500005], a[22], t[22];
//int dis[500005];
int dis[1001][1001];
//int f[500005], cnt, cur, dep[500005], fa[500005][22];
struct node {
//	int u, v, w;
//}a[500005];
//bool operator < (const node &x, const node &y) {
//	return x.w < y.w;
//}
//struct node2 {
	int v, w;
};
vector <node> g[500005];
//int find(int x) {
//	return f[x] == x ? x : f[x] = find(f[x]);
//}
//void un(int x, int y) {
//	int fx = find(x), fy = find(y);
//	f[fx] = fy;
//}
//void kruskal() {
//	for (int i = 1; i <= cnt; i++) {
//		if (find(a[i].u) != find(a[i].v)) {
//			un(a[i].u, a[i].v);
//			g[a[i].u].push_back({a[i].v, a[i].w});
//			g[a[i].v].push_back({a[i].u, a[i].w});
//		}
//	}
//}
//void dfs(int x, int ft) {
//	dep[x] = dep[ft] + 1;
//	fa[x][0] = ft;
//	for (int i = 1; i < 21; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
//	for (auto [y, w] : g[x]) {
//		dis[y] = dis[x] + w;
//		if (y != ft) dfs(y, x);
//	}
//}
//int lca(int u, int v) {
//	if (dep[u] < dep[v]) swap(u, v);
//	for (int i = 20; i > -1; i--) {
//		if (dep[fa[u][i] > dep[v]) u = fa[u][i];
//	}
//	if (u == v) return v;
//	for (int i = 20; i > -1; i--) {
//		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
//	}
//	return fa[u][0];
//}
//int dist(int u, int v) {
//	int w = lca(u, v);
//	return dis[u] + dis[v] - 2 * dis[w];
//}
//void dijkstra(int x, int y) {
//	for (int i = 1; i <= m; i++) dis[i] = 1e9;
//	queue <int> q;
//	q.push(x);
//	dis[x] = 0;
//	while (q.size()) {
//		int u = q.front();
//		q.pop();
//		if (u == y) continue;
//		for (node e : g[x]) {
//			int v = e.v, w = e.w;
//			if (dis[v] <= dis[u] + w) continue;
//			dis[v] = dis[u] + w;
//			q.push(v);
//		}
//	}
//} 
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> gt[i];
//		f[i] = i; 
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> a[j] >> t[j];
		for (int j = 2; j <= k; j++) {
			for (int l = 1; l < j; l++) {
//				a[++cnt] = {a[j], a[l], t[j] + t[l]};
				g[a[j]].push_back({a[l], t[j] + t[l]});
				g[a[l]].push_back({a[j], t[j] + t[l]});
				dis[a[j]][a[l]] = dis[a[l]][a[j]] = t[j] + t[l];
				
			}
		}
	}
//	sort(a + 1, a + 1 + cnt);
//	kruskal();
//	dfs(1, 0);
	for (int k = 1; k <= m; k++) {
		dis[k][k] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = i + 1; j <= m; j++) {
				if (dis[i][j] == 0) dis[i][j] = 1e9;
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
//		dijkstra(x, y);
//		cout << gt[x] + gt[y] + dis[y] << '\n';
		cout << gt[x] + gt[y] + dis[x][y] << '\n';
	}
	return 0;
}
/*
i,id1<--t1+t2-->i,id2
´ø²ÎÊýDJ 
*/ 
