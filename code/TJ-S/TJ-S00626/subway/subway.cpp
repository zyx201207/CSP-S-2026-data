#include<cstdio>
#include<algorithm>
const int MAXN = 1010;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int c, n, m, d, q, w[MAXN];
long long dist[MAXN][MAXN];
int a[MAXN], t[MAXN];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &m, &n, &d, &q);
	for(int i = 1; i <= n; ++ i) scanf("%d", &w[i]);
	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= n; ++ j) dist[i][j] = INF;
	for(int i = 1; i <= n; ++ i) dist[i][i] = 0;
	for(int _ = 1; _ <= m; ++ _)
	{
		int k;
		scanf("%d", &k);
		for(int i = 1; i <= k; ++ i) scanf("%d%d", &a[i], &t[i]);
		for(int i = 1; i <= k; ++ i) 
			for(int j = 1; j <= k; ++ j) 
				dist[a[i]][a[j]] = std::min(dist[a[i]][a[j]], (long long)t[i] + t[j]);
	}
	for(int k = 1; k <= n; ++ k)
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	while(q --)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", dist[x][y] + w[x] + w[y]);
	}
	return 0;
}
