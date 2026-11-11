#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500010], k[1010];
long long dis[5010][5010];

struct node
{
	long long a, t;
}arr[510][20010];

void floyd()
{
	for(int i = 1;i <= m;i ++)
		for(int j = 1;j <= m;j ++)
			for(int l = 1;l <= m;l ++)
				if(i != j && j != l && i != l)
					dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	if(n <= 5000)
	{
		memset(dis, 0x3f3f3f3f, sizeof(dis));
		for(int i = 1;i <= m;i ++)
			scanf("%d", &w[i]), dis[i][i] = 0;
		
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d", &k[i]);
			for(int j = 1;j <= k[i];j ++)
				scanf("%lld %lld", &arr[i][j].a, &arr[i][j].t);
			
			for(int j = 1;j <= k[i];j ++)
				for(int l = j + 1;l <= k[i];l ++)
				{
					int u = arr[i][j].a, v = arr[i][l].a;
					dis[u][v] = dis[v][u] = min(min(dis[v][u], dis[u][v]), arr[i][j].t + arr[i][l].t);				
				}
		}
		floyd();
		for(int i = 1, x, y;i <= q;i ++)
		{
			scanf("%d %d", &x, &y);
			printf("%lld\n", dis[x][y] + w[x] + w[y]);
		}
		return 0;			
	}
	return 0;
}
