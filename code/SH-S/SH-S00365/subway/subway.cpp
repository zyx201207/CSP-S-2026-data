#include <bits/stdc++.h>
#define int long long
#define MAXN 500005
#define INF 9187201950435737471

using namespace std;

int c, n, m, d, q, a, b, ans, cst1[MAXN], floyd[505][505];

struct node {
	int v, w;
};

vector<node> g[MAXN];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(floyd, 127, sizeof floyd);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) scanf("%lld", &cst1[i]);
	for (int i = 1, k; i <= n; ++i) {
		floyd[i][i] = 0;
		scanf("%lld", &k);
		for (int j = 1, u, w; j <= k; ++j) {
			scanf("%lld%lld", &u, &w);
			g[u].push_back({i, w});
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			for (int k = j + 1; k < g[i].size(); ++k) {
				node &jj = g[i][j], &kk = g[i][k];
				floyd[jj.v][kk.v] = min(floyd[jj.v][kk.v], jj.w + kk.w);
				floyd[kk.v][jj.v] = min(floyd[kk.v][jj.v], jj.w + kk.w);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (i == k) continue;
			for (int j = i + 1; j <= n; ++j) {
				if (floyd[i][k] != INF && floyd[k][j] != INF && floyd[i][k] + floyd[k][j] < floyd[i][j]) {
					floyd[i][j] = floyd[i][k] + floyd[k][j];
					floyd[j][i] = floyd[i][k] + floyd[k][j];
				}
			}
		}
	}
	while (q --) {
		ans = INF;
		scanf("%lld%lld", &a, &b);
		for (const node &i : g[a]) {
			for (const node &j : g[b]) {
				if (floyd[i.v][j.v] != INF) {
					ans = min(ans, floyd[i.v][j.v] + i.w + j.w);
				}
			}
		}
		ans += cst1[a] + cst1[b];
		printf("%lld\n", ans);
	}
	return 0;
} 
