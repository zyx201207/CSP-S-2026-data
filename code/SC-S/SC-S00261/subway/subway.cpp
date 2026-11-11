#include <iostream>
using ll = long long;

const int N = 505, M = 500005;

int c, n, m, d, q, t[M], b[M][25];
ll f[N][N], w[M], a[M][25];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q); 
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i != j) f[i][j] = 1e18;
	for(int i = 1; i <= m; ++i) scanf("%lld", &w[i]);
	for(int i = 1, k; i <= n; ++i) {
		scanf("%d", &k);
		int z;
		ll tm;
		for(int j = 1; j <= k; ++j) {
			scanf("%d%lld", &z, &tm);
			a[z][++t[z]] = tm;
			b[z][t[z]] = i;
		}
	}
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= t[i]; ++j)
			for(int k = 1; k <= t[i]; ++k)
				f[b[i][j]][b[i][k]] = std::min(f[b[i][j]][b[i][k]], a[i][j] + a[i][k]);
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	for(int i = 1, u, v; i <= q; ++i) {
		scanf("%d%d", &u, &v);
		ll ans = 1e18;
		for(int j = 1; j <= t[u]; ++j)
			for(int k = 1; k <= t[v]; ++k)
				ans = std::min(ans, a[u][j] + f[b[u][j]][b[v][k]] + a[v][k]);
		printf("%lld\n", ans + w[u] + w[v]);
	}
}