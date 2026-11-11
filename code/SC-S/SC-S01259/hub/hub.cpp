#include <bits/stdc++.h>
using namespace std;
int c, T, n, k, a, b;
namespace Main1{
	const int N = 3010;
	int f[N][N], h[N][N], mxd[N], sz[N], now, dist[N][N], fa[N];
	vector<int> g[N];
	void dfs(int u) {
		sz[u] = 1, mxd[u] = f[u][1] = h[u][1] = 0;
		for(int i = 2; i <= k; i ++) f[u][i] = h[u][i] = N;
		for(int v : g[u]) {
			if(v == fa[u]) continue;
			fa[v] = u;
			dfs(v);
			mxd[u] = max(mxd[u], mxd[v] + 1);
			for(int i = 1; i <= min(sz[u], k); i ++) h[u][i] = max(f[u][i], mxd[v] + 1);
			for(int i = 1; i <= min(sz[u], k); i ++)
				for(int j = 1; j <= sz[v] && i + j <= k; j ++)
					h[u][i + j] = min(h[u][i + j], max(f[u][i], f[v][j]));
			sz[u] += sz[v];
			for(int i = 1; i <= min(sz[u], k); i ++) f[u][i] = h[u][i];
		}
		for(int i = 1; i <= min(sz[u], k); i ++) f[u][k] = min(f[u][k], f[u][i]);
	}
	void dfs2(int u, int fa, int d) {
		dist[now][u] = d;
		for(int v : g[u]) {
			if(v == fa) continue;
			dfs2(v, u, d + 1);
		}
	}
	void solve() {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i ++) g[i].clear();
		for(int i = 1; i < n; i ++) {
			scanf("%d%d", &a, &b);
			g[a].push_back(b), g[b].push_back(a);
		}
		int ans = N;
		for(int C = 1; C <= n; C ++) {
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= n; j ++)
					dist[i][j] = 0;
			fa[C] = 0;
			dfs(C);
			for(int i = 1; i <= n; i ++) {
				now = i;
				dfs2(fa[i], i, 1);
			}
			for(int i = 1; i <= n; i ++) {
				int res = 0;
				for(int j = 1; j <= n; j ++) res = max(res, dist[i][j]);
				ans = min(ans, max(res, f[i][k]));
				for(int j = i + 1; j <= n; j ++) {
					res = 0;
					for(int k = 1; k <= n; k ++) res = max(res, min(dist[i][k], dist[j][k]));
					for(int l = 1; l < k; l ++) ans = min(ans, max(res, max(f[i][l], f[j][k - l])));
				}
			}
		}
		printf("%d\n", ans);
	}
}
namespace Main2{
	const int N = 100010;
	int dist[N], dep[N], res, now;
	vector<int> g[N];
	void dfs(int u, int fa) {
		dep[u] = dep[fa] + 1;
		if(dep[u] > res) {
			res = dep[u];
			now = u;
		}
		for(int v : g[u])
			if(v != fa)
				dfs(v, u);
	}
	void solve() {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i ++) g[i].clear();
		for(int i = 1; i < n; i ++) {
			scanf("%d%d", &a, &b);
			g[a].push_back(b), g[b].push_back(a);
		}
		dfs(1, 0);
		res = 0;
		dfs(now, 0);
		printf("%d\n", res);
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if(c == 7 || c == 11 || c == 12) while(T --) Main2::solve();
	else while(T --) Main1::solve();
	return 0;
}