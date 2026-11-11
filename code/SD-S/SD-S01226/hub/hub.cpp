#include <bits/stdc++.h>
using namespace std;

#define il inline
#define ri register int
#define ll long long
#define inf 0x3f3f3f3f
il ll read();
const int N = 500505;
const int M = 500505;

int c, n, m, d, q, cnt;
ll r[N];
int fb[N], lg2[N];
struct node {
	int x, y, w;
} cb[M];
struct edge {
	int to, nxt, w;
} e[M * 2];
int h[N], tot;
int dep[N], f[N][21];
ll dis[N][21];

il bool cmp(node a, node b)
{
	return a.w < b.w;
}
il void add(int u, int v, int w)
{
	e[++tot].to = v;
	e[tot].nxt = h[u];
	e[tot].w = w;
	h[u] = tot;
}
int fin(int x)
{
	if (fb[x] == x) return x;
	return fb[x] = fin(fb[x]);
}
void dfs(int now)
{
	for (ri i=h[now]; i; i=e[i].nxt) {
		if (e[i].to == f[now][0]) continue;
		dep[e[i].to] = dep[now] + 1;
		dis[e[i].to][0] = e[i].w;
		f[e[i].to][0] = now;
		dfs(e[i].to);
	}
}
ll lca(int x, int y)
{
	if (dep[x] < dep[y]) {
		swap(x, y);
	}
	ll res = 0;
	for (ri i=lg2[dep[x]]; i>=0; i--) {
		if (dep[f[x][i]] < dep[y]) continue;
		res += dis[x][i];
		x = f[x][i];
	}
	if (x == y) {
		return res;
	}
	for (ri i=lg2[dep[x]]; i>=0; i--) {
		if (f[x][i] == f[y][i]) continue;
		res += dis[x][i] + dis[y][i];
		x = f[x][i];
		y = f[y][i];
	}
	return res + dis[x][0] + dis[y][0];
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(); n = read(); m = read(); d = read(); q = read();
	for (ri i=2; i<=n+m; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
	for (ri i=1; i<=m; i++) {
		r[i] = read();
	}
	for (ri i=1; i<=n; i++) {
		int k = read();
		for (ri j=1; j<=k; j++) {
			int a = read(), t = read();
			cb[++cnt].x = i + m;
			cb[cnt].y = a;
			cb[cnt].w = t;
		}
	}
	sort(cb + 1, cb + cnt + 1, cmp);
	for (ri i=1; i<=n+m; i++) {
		fb[i] = i;
	}
	int lt = n + m;
	for (ri i=1; lt>1; i++) {
		int fx = fin(cb[i].x), fy = fin(cb[i].y);
		if (fx == fy) continue;
		fb[fx] = fy;
		add(cb[i].x, cb[i].y, cb[i].w);
		add(cb[i].y, cb[i].x, cb[i].w);
		lt--;
	}
	dep[1] = 1;
	dfs(1);
	for (ri j=1; j<=20; j++) {
		for (ri i=1; i<=n+m; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			dis[i][j] = dis[i][j - 1] + dis[f[i][j - 1]][j - 1];
		}
	}
	while (q--) {
		int x = read(), y = read();
		cout << lca(x, y) + r[x] + r[y] << "\n"; 
	}
	return 0;
}
il ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || '9' < c) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
