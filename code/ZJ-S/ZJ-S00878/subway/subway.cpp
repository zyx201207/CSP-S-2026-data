#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q, a[N], dis[505][505];
vector < pair < int, int > > g[N];
inline int read()
{
	int x = 1, p = 0;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') x = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		p = (p << 1) + (p << 3) + (c ^ 48);
		c = getchar();
	}
	return x * p;
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (register int i = 1;i <= m; ++ i)
	{
		a[i] = read();
	}
	for (register int i = 1;i <= n; ++ i)
	{
		for (register int j = 1;j <= n; ++ j)
		{
			dis[i][j] = 1e18;
		}
		dis[i][i] = 0;
	}
	for (register int i = 1, k;i <= n; ++ i)
	{
		k = read();
		for (register int j = 1, x, y;j <= k; ++ j)
		{
			x = read(), y = read();
			g[x].push_back({i, y});
		}
	}
	for (register int i = 1;i <= m; ++ i)
	{
		for (register int j = 0;j < g[i].size(); ++ j)
		{
			for (register int k = j + 1;k < g[i].size(); ++ k)
			{
				int f1 = g[i][j].first, f2 = g[i][k].first, s1 = g[i][j].second, s2 = g[i][k].second;
				dis[f1][f2] = dis[f2][f1] = min(dis[f1][f2], s1 + s2);
			}
		}
	}
	for (register int k = 1;k <= n; ++ k)
	{
		for (register int i = 1;i <= n; ++ i)
		{
			for (register int j = 1;j <= n; ++ j)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (register int i = 1;i <= n; ++ i)
//	{
//		for (register int j = 1;j <= n; ++ j)
//		{
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
	while (q --)
	{
		int x, y, res = 1e18; x = read(), y = read();
		for (register int i = 0;i < g[x].size(); ++ i)
		{
			for (register int j = 0;j < g[y].size(); ++ j)
			{
				res = min(res, g[x][i].second + g[y][j].second + dis[g[x][i].first][g[y][j].first]);
			}
		}
		cout << res + a[x] + a[y] << "\n";
	}
	return 0;
}//Oct31==Dec25?
