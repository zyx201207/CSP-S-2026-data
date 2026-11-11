#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 11, M = (int)1e3 + 5;
int n, k, sz[N], dp[M][M], dist[N], fa[N], tmp[M], f[M];
vector<int> edges[N];
bool b[M][M];

inline int dfs1(int x, int fx) {
	int len = (int)edges[x].size();
	fa[x] = fx;
	int pos = x;
	for (int i = 0; i < len; i++) {
		int y = edges[x][i];
		if (fx != y && !b[x][y]) {
			dist[y] = dist[x] + 1;
			int u = dfs1(y, x);
			if (dist[u] > dist[pos])
				pos = u;
		}
	}
	return pos;
}

inline void dfs2(int x, int fx) {
	int len = (int)edges[x].size();
	sz[x] = 1;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		int y = edges[x][i];
		if (y != fx && !b[x][y]) {
			++cnt;
			dfs2(y, x);
			for (int j = 0; j <= sz[x] && j <= k; j++)
				f[j] = dp[x][j], dp[x][j] = 1 << 29;
			for (int j = 0; j <= sz[x] && j <= k; j++) {
				if (cnt > 1 && j)
					dp[x][j] = min(dp[x][j], max(f[j], dp[y][0] + 1));
				else
					dp[x][j] = min(dp[x][j], dp[y][0] + 1);
				for (int l = 1; l <= sz[y] && l + j < k; l++)
					if (cnt > 1)
						dp[x][j + l + 1] = min(dp[x][j + l + 1], max(f[j], dp[y][l]));
					else
						dp[x][j + l + 1] = min(dp[x][j + l + 1], dp[y][l]);
			}
			sz[x] += sz[y];
//	for (int i = 0; i <= k; i++)
//		printf("dp[%d][%d]=%d\n", x, i, dp[x][i]);
		}
	}
//	printf("sz[%d]=%d\n", x, sz[x]);
	if (!cnt)
		dp[x][0] = dp[x][1] = 0;
}

inline void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans = 1 << 30;
	for (int i = 1; i <= n; i++) {
		int len = (int)edges[i].size();
		for (int j = 0; j < len; j++) {
			int y = edges[i][j];
			if (i > y)
				continue;
			b[y][i] = b[i][y] = 1;
			dist[i] = 0;
			int x = dfs1(i, 0);
			dist[x] = 0;
			int z = dfs1(x, 0);
			int dis = dist[z];
			while (z != x && dist[z] > dis >> 1)
				z = fa[z];
			for (x = 1; x <= n; x++)
				for (int u = 0; u <= k; u++)
					dp[x][u] = 1 << 29;
			dfs2(z, 0);
			for (x = 0; x <= k; x++)
				tmp[x] = dp[z][x];
			dist[y] = 0;
			x = dfs1(y, 0);
			dist[x] = 0;
			z = dfs1(x, 0);
			dis = dist[z];
			while (z != x && dist[z] > dis >> 1)
				z = fa[z];
			for (x = 1; x <= n; x++)
				for (int u = 0; u <= k; u++)
					dp[x][u] = 1 << 29;
//					printf("%d\n", z);
			dfs2(z, 0);
//			printf("%d %d\n", i, y);
			for (x = 1; x < k; x++)
				ans = min(ans, max(dp[z][x], tmp[k - x]));//, printf("%d %d\n", dp[z][x], tmp[k  - x]);
			b[y][i] = b[i][y] = 0;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		edges[i].clear();
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C, T;
	scanf("%d%d", &C, &T);
	while (T--)
		solve();
	return 0;
}
