#include <bits/stdc++.h>
#define GunMu int
using namespace std;
const int maxn = 505; // Lines
const int maxm = 2e4 + 5; // Stations
GunMu c, d;
int n, m, q;
int into[maxm];
int plat[maxm][maxn];
int vis[maxm];
int start;
int ans;
int dis_transfer[maxm][maxm];
int dis_walk[maxm][maxm];

struct node
{
	int v, line;
};
vector<node> edge[maxm];

void dfs(int now, int l)
{
	printf("Searching at Stn.%d, Line %d\n", now, l);
	for (auto i : edge[now])
	{
		int v = i.v, line = i.line;
		printf("    Found station %d. It\'s on Line %d.\n", v, line);
		if (dis_walk[v][start])
		{
			printf("    It has been searched before, the distance is %d.\n", dis_walk[v][start]);
			dis_walk[start][v] = dis_walk[v][start];
			dis_transfer[start][v] = dis_transfer[v][start];
		}
		if (!vis[v])
		{
			if (l != line)
			{
				if (dis_walk[start][v])
				{
					dis_transfer[start][v] = min(dis_transfer[start][v], dis_transfer[start][now] + plat[now][l] + plat[now][line]);
					dis_walk[start][v] = dis_transfer[start][v] + plat[v][line];
				}
				else
				{
					dis_transfer[start][v] = dis_transfer[start][now] + plat[now][l] + plat[now][line];
					dis_walk[start][v] = dis_transfer[start][v] + plat[v][line];
				}
			}
			else if (dis_transfer[start][v])
			{
				dis_transfer[start][v] = min(dis_transfer[start][v], dis_transfer[start][now]);
				dis_walk[start][v] = dis_transfer[start][v] + plat[v][line];
			}
			else
			{
				dis_transfer[start][v] = dis_transfer[start][now];
				dis_walk[start][v] = dis_transfer[start][v] + plat[v][line];
			}
			printf("    It hasn\'t been visited this roll. Now the distance is %d.\nContinue ", dis_walk[start][v]);
			vis[v] = 1;
			dfs(v, line);
			vis[v] = 0;
			printf("Reverse back to Stn.%d\n", now);
		}
		else
		{
			printf("    It has been visited. Stop visiting station %d.\n", v);
		}
	}
}

signed main()
{
	freopen("subway1.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &into[i]);
	}
	if (n <= 50)
	{ // dfs O(n*m^2) orz
		for (int i = 1; i <= n; ++i)
		{
			int stn, u, w;
			scanf("%d%d%d", &stn, &u, &w);
			plat[u][i] = w;
			for (int j = 2; j <= stn; ++j)
			{
				int v;
				scanf("%d%d", &v, &w);
				plat[v][i] = w;
				edge[u].push_back({v, i});
				edge[v].push_back({u, i});
				u = v;
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			printf("The station %d:\n", i);
			for (auto j : edge[i])
			{
				printf("Stn.%d, Line %d\n", j.v, j.line);
			}
		}
		for (start = 1; start <= n; ++start)
		{
			memset(vis, 0, sizeof(vis));
			vis[start] = 1;
			dfs(start, 0);
		}
		while (q--)
		{
			int u, v;
			cin >> u >> v;
			if (u == v)
			{
				ans = 0;
			}
			else
			{
				ans = into[u] + into[v] + dis_walk[u][v];
			}
			cout << ans << endl;
		}
	}
}
