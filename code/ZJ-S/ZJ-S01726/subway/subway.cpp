#include <bits/stdc++.h>
constexpr long long Inf = acosl(-1) * 1E18L;
int n, m, q, w[524288];
long long f[512][512];
std::vector< std::pair<int, int> > g[524288];
int main() {
	freopen("subway.in", "rb", stdin);
	freopen("subway.out", "wb", stdout);
	scanf("%*d%d%d%*d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for(int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		for(int j = 1, a, t; j <= k; j++)
			scanf("%d%d", &a, &t), g[a].emplace_back(i, t);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = i == j ? 0 : Inf;
	for(int i = 1; i <= m; i++)
		for(std::pair<int, int> j : g[i])
			for(std::pair<int, int> k : g[i]) {
				int	u = j.first, v = k.first,
					w = j.second + k.second;
				f[u][v] = std::min<long long>(f[u][v], w);
			}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	for(int i = 1, x, y; i <= q; i++) {
		scanf("%d%d", &x, &y);
		long long ans = Inf;
		for(std::pair<int, int> j : g[x])
			for(std::pair<int, int> k : g[y]) {
				int	u = j.first, v = k.first,
					w = j.second + k.second;
				ans = std::min<long long>(ans, f[u][v] + w);
			}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}

