#include <cstdio>

const int N = 505, M = 5e5+5;
int c, n, m, d, q;
int w[M], k[M], t[N][M], a[N][M];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d", &c, &n, &m, &d);
	for(int i=1; i<=m; i++)
	{
		scanf("%d", &w[i]);
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &k[i]);
		for(int j=1; j<=k[i]; j++)
		{
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	while(q --)
	{
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		long long ans = 0;
		for(int i=1; i<=k[1]; i++)
		{
			if(a[1][i] == xx)
			{
				ans += w[xx];
				ans += t[1][i];
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
