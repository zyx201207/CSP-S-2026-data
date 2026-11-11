//rp++
 
#include <bits/stdc++.h> 
#define LL long long

const int N = 5e5 + 1;

int c, n, m, d, q;
std::vector<int> way[N];
int v[501][N];
bool vis[501][N];
//int dist[N][N];
int w[N];
int k[N];
int x, y;
int res = 2147483647;

void dfs(int idx, int dist)
{
	//printf("idx = %d, dist = %d y = %d\n", idx, dist, y);
	if(idx == y)
	{
		//puts("RES IS FIND");
		res = std::min(dist, res);
		return;
	}
	for(int i = 0; i < way[idx].size(); i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(v[way[idx][i]][j] != 0 && !vis[way[idx][i]][j])
			{
				//puts("abc");
				vis[way[idx][i]][j] = true;
				dfs(j, dist + v[way[idx][i]][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	std::cin >> c >> n >> m >> d >> q;
//	for(int i = 1; i <= m; i++)
//	{
//		for(int j = 1; j <= m; j++)
//		{
//			dist[i][j] = -1;
//		}
//	}
	for(int i = 1; i <= m; i++)
		std::cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		std::cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			int a, t;
			std::cin >> a >> t;
			v[i][a] = t;
			way[a].push_back(i);
		}
	}
//	puts("way");
//	for(int i = 1; i <= m; i++)
//	{
//		for(int j = 1; j <= k[i]; j++)
//			std::cout << way[i][j] << ' ';
//		std::cout << "  \n";
//	}
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= m; j++)
//		{
//			std::cout << v[i][j] << ' ';
//		}
//		std::cout << '\n';
//	}
	while(q--)
	{
		std::cin >> x >> y;
		dfs(x, 0);
		std::cout << res + w[x] + w[y] << '\n';
		res = 2147483647;
		for(int j = 1; j <= n; j++)
			for(int i = 1; i <= m; i++)
				vis[j][i] = false; 
	}
}
