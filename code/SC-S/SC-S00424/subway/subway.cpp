#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
namespace io {
	const int S = 1 << 20;
	char buf[S], *p1, *p2;
	#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	inline int read() {
		int res = 0, f = 1;
		char ch = gc();
		while (!isdigit(ch)) { if (ch == '-') f = -1; ch = gc(); }
		while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = gc();
		return res * f;
	}
	inline void print(ll x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) print(x / 10);
		putchar(x % 10 ^ 48);
	}
}
using namespace io;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, k, tot, nodet, edget;
int w[M], head[N + M], deep[N + M], fa[N + M], f[N + M][20];
ll dist[N + M][20];
struct edge {
	int to, next, data;
} e[(N + M) << 1];
struct Edge {
	int u, v, w;
	friend bool operator < (Edge x, Edge y) {
		return x.w < y.w;
	}
};
vector<Edge> vec;
void add(int u, int v, int w) {
	e[++tot] = { v, head[u], w };
	head[u] = tot;
}
void init() {
	nodet = n + m;
	k = log2(nodet);
	edget = vec.size();
	for (int i = 1; i <= nodet; i++)
		fa[i] = i;
}
int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
void krus() {
	sort(vec.begin(), vec.end());
	for (int i = 0; i < edget; i++) {
		int u =vec[i].u, v = vec[i].v;
		int ru = find(u), rv = find(v);
		if (ru == rv) continue;
		fa[rv] = ru;
		add(u, v, vec[i].w), add(v, u, vec[i].w);
	}
}
void dfs(int u) {
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (f[u][0] == v) continue;
		f[v][0] = u;
		dist[v][0] = e[i].data;
		deep[v] = deep[u] + 1;
		dfs(v);
	}
}
void build() {
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= nodet; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			dist[i][j] = dist[i][j - 1] + dist[f[i][j - 1]][j - 1];
		}
	}
}
ll lca_data(int u, int v) {
	ll sum = 0;
	if (deep[u] < deep[v]) swap(u, v);
	for (int i = k; i >= 0; i--) {
		if (deep[f[u][i]] >= deep[v])
			sum += dist[u][i], u = f[u][i];
	}
	if (u == v) return sum;
	for (int i = k; i >= 0; i--) {
		if (f[u][i] != f[v][i]) {
			sum += dist[u][i] + dist[v][i];
			u = f[u][i], v = f[v][i];
		}
	}
	sum += dist[u][0] + dist[v][0];
	return sum;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
		w[i] = read();
	for (int i = 1, k, v, t; i <= n; i++) {
		k = read();
		for (int j = 1; j <= k; j++) {
			v = read(), t = read();
			vec.push_back({ m + i, v, t });
		}
	}
	init(), krus(), dfs(1), build();
	for (int i = 1, u, v; i <= q; i++) {
		u = read(), v = read();
		print(lca_data(u, v) + w[u] + w[v]);
		putchar('\n');
	}
	return 0;
}
