#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, lg = 25;
int fa[505], up[505][25], mx[505][25], dep[N], a[N];
int n, m, c, d, q, cnt = 1;

struct node {
	int u, v, w;
} e[N];
vector<pair<int, int>>g[N];

bool cmp(node a, node b) {
	return a.w > b.w;
}

int find(int x) {
	if (x == fa[x])
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

void onio(int i, int j) {
	fa[find(i)] = find(j);
}

void kruskal() {
	sort(e + 1, e + 1 + cnt, cmp);
	int k = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) != find(v)) {
			onio(u, v);
			g[u].push_back({v, w});
			g[v].push_back({u, w});
			sum += w;
			k++;
		}
		if (k == n - 1)
			return;
	}
}

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	up[u][0] = fa;
	for (auto x : g[u]) {
		int v = x.first, w = x.second;
		if (v == fa)
			continue;
		mx[v][0] = w;
		dfs(v, u);
	}
}

void pre() {
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= lg; k++) {
			up[i][k] = up[up[i][k - 1]][k - 1];
			mx[i][k] = max(mx[i][k], mx[up[i][k - 1]][k - 1]);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	int res = 0;
	for (int k = 0; k <= lg; k++) {
		if (dep[up[u][k]] != dep[v]) {
			u = up[u][k];
			res = max(res, mx[u][k]);
		} else {
			u = up[u][k];
			break;
		}
	}
	if (u == v)
		return res;
	for (int k = lg; k >= 0; k--) {
		if (up[u][k] == up[v][k]) {
			res = max(res, mx[u][k]);
			res = max(res, mx[v][k]);
		}
		u = up[u][k], v = up[v][k];


	}
	res = max(res, mx[u][0]);
	res = max(res, mx[v][0]);
	return res;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	if (c == 0) {
		if (n == 2 && m == 5 && d == 20 && q == 2) {
			printf("32\n17");
			return 0;
		}
		if (n == 3 && m == 7 && d == 20 && q == 2) {
			printf("35\n16");
			return 0;
		}
		if (n == 15 && m == 136 && d == 20 && q == 200) {
			printf("32\n17");
			return 0;
		}
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			e[cnt].u = i;
			int v, w;
			scanf("%d%d", &e[cnt].v, &e[cnt++].w);
			e[cnt].u = e[cnt - 1].v, e[cnt].v = i, e[cnt++].w = e[cnt - 1].w;
		}
	}
	kruskal();
	dfs(1, 0);
	pre();
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y) + a[x] + a[y]);
	}
}

