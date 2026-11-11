#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> g[1000010];

bool chosen[20] , vis[20];
int dis[20][20];

void floodfill(int x)
{
	if (!chosen[x] || vis[x]) return;
	vis[x] = true;
	for (auto y : g[x])
	{
		floodfill(y);
	}
}

int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c , T;
	cin >> c >> T;
	while (T--)
	{
		int n , k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			g[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			int u , v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (c <= 3)
		{
			int ans = 2e9;
			for (int stat = 0; stat < (1 << n); stat++)
			{
				if (__builtin_popcount(stat) != k) continue;
				memset(vis , false , sizeof(vis));
				memset(chosen , false , sizeof(chosen));
				for (int j = 0; j < n; j++)
				{
					chosen[j + 1] = (stat & (1 << j));
				}
				int cnt = 0;
				for (int i = 1; i <= n; i++)
				{
					if (chosen[i] && !vis[i])
					{
						cnt++;
						floodfill(i);
					}
				}
				//printf("n:%d stat:%d\n" , n , stat);
				if (cnt > 2) continue;
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						dis[i][j] = 1e9;
					}
					dis[i][i] = 0;
				}
				for (int i = 1; i <= n; i++)
				{
					for (auto y : g[i])
					{
						dis[i][y] = 1;
					}
				}
				for (int k = 1; k <= n; k++)
				{
					for (int i = 1; i <= n; i++)
					{
						for (int j = 1; j <= n; j++)
						{
							dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
						}
					}
				}
				/*
				printf("n:%d stat:%d\n" , n , stat);
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						printf("%d " , dis[i][j]);
					}
					puts("");
				}
				*/
				int maxn = 0;
				for (int i = 1; i <= n; i++)
				{
					int minn = 2e9;
					for (int j = 1; j <= n; j++)
					{
						if (chosen[j]) minn = min(minn , dis[i][j]);
					}
					maxn = max(maxn , minn);
				}
				ans = min(ans , maxn);
			}
			cout << ans << '\n';
			continue;
		}
		if (c == 13 || c == 14)
		{
			if (k == n) cout << 0 << '\n';
			else if (k >= n / 2) cout << 1 << '\n';
			else
			{
				int m = n / 2;
				if (m & 1)
				{
					cout << ((m - 1) / 2 - (k - 1) / 2 + 1) / 2 + 1 << '\n';
				}
				else
				{
					cout << (m / 2 - k / 2 + 1) / 2 + 1 << '\n';
				}
			}
			continue;
		}
	}
	return 0;
}
