#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
typedef pair<int, int> PII;
const int N = 1e6 + 5, inf = 1e9 + 5;
int n, d, ans, tot;
int a[N];
int cc, tt;
int head[N], ver[N], edge[N], nxt[N];
int dis[N], vis[N], f[N];
priority_queue<PII, vector<PII>, greater<PII> > q;
void add(int x, int y) {
	ver[++tot] = y, edge[tot] = 1, nxt[tot] = head[x], head[x] = tot;
}
void init() {
	for (int i = 1; i <= n; ++i)
		dis[i] = inf, vis[i] = f[i] = 0;
	while (!q.empty()) q.pop();
}
void dijkstra(int s) {
	dis[s] = 0, f[s] = 1;
	q.push( {dis[s], s} );
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], w = edge[i];
			if (dis[y] > dis[x] + w) {
				dis[y] = dis[x] + w, f[y] = f[x];
				q.push( {dis[y], y} );
			} else if (dis[y] == dis[x] + w)
				f[y] ++;
		}
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cc = read(), tt = read();
	while (tt --) {
		n = read(), d = read(), tot = ans = 0;
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if (a[i] + d >= a[j])
					add(i, j), add(j, i);
		for (int i = 1; i <= n; ++i) {
			init();
			dijkstra(i);
			for (int j = i + 1; j <= n; ++j)
				if (f[j] == 2) ans ++;
		}
		init();
		for (int i = 1; i <= n; ++i) head[i] = 0;
		for (int i = 1; i <= tot; ++i) ver[i] = edge[i] = nxt[i] = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
