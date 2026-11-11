#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 51;
int T, n, k, h[N], fa[11][N], ans;
bool b[N], vis[N];
struct edge {
	int to, nxt;
} e[N << 1];
int hd[N], cnt;
void ade(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}
void Dfs(int x, int fr) {
	h[x] = h[fr] + 1;
	fa[0][x] = fr;
	for (int i = hd[x]; i; i = e[i].nxt)
		if (e[i].to != fr)
			Dfs(e[i].to, x);
}
int lca(int x, int y) {
	if (h[x] < h[y])
		swap(x, y);
	for (int i = 10; i >= 0; i--) {
		int nx = fa[i][x];
		if (h[nx] >= h[y])
			x = nx;
	}
	if (x == y)
		return x;
	for (int i = 10; i >= 0; i--) {
		int nx = fa[i][x], ny = fa[i][y];
		if (nx != ny)
			x = nx, y = ny;
	}
	return fa[0][x];
}
int d(int x, int y) {
	return h[x] + h[y] - 2 * h[lca(x, y)];
}
void dfS(int x) {
	vis[x] = 1;
	for (int i = hd[x]; i; i = e[i].nxt)
		if (!vis[e[i].to] && b[e[i].to])
			dfS(e[i].to);
}
void dfs(int x, int ct) {
	if (ct > k || ct + n - x + 1 < k)
		return;
	if (x == n + 1) {
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] && !vis[i]) {
				c++;
				dfS(i);
			}
			if (c > 2)
				return;
		}
		int ma = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i]) continue;
			int mi = 1e9;
			for (int j = 1; j <= n; j++)
				if (b[j])
					mi = min(mi, d(i, j));
			ma = max(ma, mi);
		}
		ans = min(ans, ma);
		return;
	}
	b[x] = 1;
	dfs(x + 1, ct + 1);
	b[x] = 0;
	dfs(x + 1, ct);
}

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf ("%d%d", &T, &T);
	while (T--) {
		scanf ("%d%d", &n, &k);
		cnt = 0, ans = 1e9;
		for (int i = 1; i <= n; i++)
			hd[i] = 0;
		for (int i = 1, u, v; i < n; i++) {
			scanf ("%d%d", &u, &v);
			ade(u, v);
			ade(v, u);
		}
		Dfs(1, 0);
		for(int i = 1; i <= 10; i++)
			for (int j = 1; j <= n; j++)
				fa[i][j] = fa[i - 1][fa[i - 1][j]];
		dfs(1, 0);
		printf ("%d\n", ans);
	}
	return 0;
}

