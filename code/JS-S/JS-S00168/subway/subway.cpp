#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q, w[500005], k[505], dis[505][505];

struct node
{
	int num, val;
};

vector < node > v[500005];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &k[i]);
		for (int j = 1; j <= k[i]; j++)
		{
			int x, y;
			scanf("%lld%lld", &x, &y);
			v[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)	
			dis[i][j] = 1145141919810000000;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < (int)v[i].size(); j++)
			for (int k = 0; k < (int)v[i].size(); k++)
				dis[v[i][j].num][v[i][k].num] = min(dis[v[i][j].num][v[i][k].num], v[i][j].val + v[i][k].val);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		int x, y, ans = 1145141919810000000;
		scanf("%lld%lld", &x, &y);
		for (int j = 0; j < (int)v[x].size(); j++)
			for (int k = 0; k < (int)v[y].size(); k++)
				ans = min(ans, w[x] + w[y] + v[x][j].val + v[y][k].val + dis[v[x][j].num][v[y][k].num]);
		printf("%lld\n", ans);
	}
	return 0;

}
