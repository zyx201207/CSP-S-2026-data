#include<bits/stdc++.h>
using namespace std;

const int M = 5e5+7, N = 500+7, D = 20+7;
const long long MAXD = 2e18;
int c, n, m, d, q;
int k[N];
int w[M], t[N][M];
vector<int> ptol[M];
int type[N];

long long edges[N][N];
long long dis[N];
void djstr(int s)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = MAXD;
	}
	dis[s] = 0;
	for (int turn = 1; turn <= n-1; turn++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dis[j] + edges[j][i] < dis[i])
				{
					dis[i] = dis[j] + edges[j][i];
				}
			}
		}
	}
}
//void check_t()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			printf("%d ", t[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void check_ptol()
//{
//	for (int j = 1; j <= m; j++)
//	{
//		for (int i = 1; i <= ptol[j][0]; i++)
//		{
//			printf("%d ", ptol[j][i]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void check_edges()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%lld ", edges[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &w[i]);
		ptol[i].push_back(0);
	}
	//printf("\n");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
		{
			int a, tt;
			scanf("%d %d", &a, &tt);
			t[i][a] = tt;
			++ptol[a][0];
			ptol[a].push_back(i); 
		}
	}
	//check_t();
	//check_ptol(); 
	for (int i = 1; i <= n; i++)
	{
		for (int ii = 1; ii <= n; ii++)
		{
			if (i == ii)    edges[i][ii] = 0;
			else    edges[i][ii] = MAXD;
		}
	}
	
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i < ptol[j][0]; i++)
		{
			for (int ii = i+1; ii <= ptol[j][0]; ii++)
			{
				int a = ptol[j][i];
				int b = ptol[j][ii];
				long long len = ((long long)t[a][j])+t[b][j];
				edges[a][b] = edges[b][a] = min(edges[a][b], len);
				//printf("%d %d %d %d %d\n", j, i, ii, a, b);
				//printf("%lld %lld %lld\n", (long long)t[a][j], (long long)t[b][j], len);
				//printf("\n");
			}
		}
	}
	//printf("\n");
	//check_edges();
	
	while (q--)
	{
		int x, y, s, e;
		scanf("%d%d", &x, &y);
		long long ans = MAXD;
		for (int sid = 1; sid <= ptol[x][0]; sid++)
		{
			djstr(ptol[x][sid]);
			for (int eid = 1; eid <= ptol[y][0]; eid++)
			{
				if (dis[ptol[y][eid]] <= ans)
				{
					ans = dis[ptol[y][eid]];
					s = ptol[x][sid];
					e = ptol[y][eid];
				}
			}
		}
		//printf("%lld %d %d\n", ans, s, e);
		ans += w[x] + t[s][x] + t[e][y] + w[y];
		printf("%lld\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
