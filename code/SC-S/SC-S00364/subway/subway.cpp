#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 5e5 + 5, MAXN = 505, LOG = 30;
int c, n, m, d, q, QAQ[MAXM], x, y;

int cnt;
struct Edge {
	int u, v, w;
} edge[MAXM * 2 + MAXN * 2];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int father[MAXM + MAXN];

int find(int x) { // 查集
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];	
}

void unit(int x, int y) { // 并集
	father[find(x)] = find(y);
}

int e[MAXM * 2 + MAXN * 2], ne[MAXM * 2 + MAXN * 2], h[MAXM + MAXN], w[MAXM * 2 + MAXN * 2], idx;

void add(int u, int v, int c) {
	e[idx] = v;
	w[idx] = c;
	ne[idx] = h[u];
	h[u] = idx++;
}

void dijkstra() {
	memset(h, -1, sizeof(h));
	for (int i = 1; i <= m * 2; i++) father[i] = i;
	
	sort(edge, edge + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		int u = edge[i].u, v = edge[i].v, c = edge[i].w;
		if (find(u) != find(v)) {
			add(u, v, c);
			add(v, u, c);
			unit(u, v);
		}
	}
}

int fa[MAXM + MAXN][LOG], dep[MAXM + MAXN];
long long dep1[MAXM + MAXN];

void dfs(int u, int fa1) { // fa 指祖先，dep 指深度，dep1 指根到 u 的距离
	dep[u] = dep[fa1] + 1, fa[u][0] = fa1;
	for (int i = 1; i < LOG; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
	
	for (int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i], c = w[i];
		if (v == fa1) continue;
		dep1[v] = dep1[u] + c;
		dfs(v, u);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG - 1; i >= 0; i--) if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int read() {
	int res = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
	return res;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) QAQ[i] = read(); // 进出地铁，其实没用
	
	for (int i = 1; i <= n; i++) {
		int k;
		k = read();
		int a, t;
		for (int j = 1; j <= k; j++) {
			a = read(), t = read();
			edge[cnt].u = a, edge[cnt].v = i + m, edge[cnt].w = t, cnt++;
		}
	}
	
	dijkstra();
	dfs(1, 0);
	
	while (q--) {
		x = read(), y = read();
		int LCA = lca(x, y);
		printf("%lld\n", 1ll * QAQ[x] + QAQ[y] + dep1[x] + dep1[y] - dep1[LCA] * 2);
	}
	
	return 0;
}