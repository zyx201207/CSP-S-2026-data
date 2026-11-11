
#include <bits/stdc++.h>
using namespace std;

int read() {
	int k = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())	if (f == '-')	f = -1;
	for (; isdigit(c); c = getchar())	k = k * 10 + (c ^ 48);
	return k * f;
}

#define int long long
const int N = 510, M = 5e5 + 10;
typedef array<int, 2> pii;
vector<pii> g[M];
int c, n, m, d, q, w[M], dis[N][N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) {
		w[i] = read();
	}
	for (int i = 1, k, a, t; i <= n; ++i) {
		k = read();
		while (k--) {
			a = read(), t = read();
			g[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1, len = 0; i <= m; ++i) {//O(m*d*d)=5e5*400=2e8
		len = g[i].size();
		for (int a = 0; a < len; ++a) {
			for (int b = a + 1; b < len; ++b) {
				int u = g[i][a][0], v = g[i][b][0], w = g[i][a][1] + g[i][b][1];
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			}
		}
	}
	for (int i = 1; i <= n; ++i)	dis[i][i] = 0;
	for (int i = 1; i <= n; ++i) {//O(n^3)=500*500*500=1.25e8
		for (int j = 1; j <= n; ++j) {
			if (dis[j][i] >= 0x3f3f3f3f3f3f3f3f)	continue;
			for (int k = 1; k <= n; ++k) {
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	int x, y;
	int ans, la, lb;
	int u, v, len;
	while (q--) {//O(q*d*d)=1e5*400=4e7
		x = read(), y = read();
		ans = 0x3f3f3f3f3f3f3f3f, la = g[x].size(), lb = g[y].size();
		for (int i = 0; i < la; ++i) {
			for (int j = 0; j < lb; ++j) {
				u = g[x][i][0], v = g[y][j][0], len = g[x][i][1] + g[y][j][1];
				ans = min(ans, dis[u][v] + len + w[x] + w[y]);
			}
		}
		if (ans >= 0x3f3f3f3f3f3f3f3f)	printf("-1\n");
		else	printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

*/