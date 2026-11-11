#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, zhan, dis[6001][6001];

struct node
{
	int x, w;
	bool operator < (const node & b) const
	{
		return w > b.w;
	}
};
vector<node> g[1500010];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		int w;
		cin >> w;
		g[i].push_back({i + 1500, w});
		g[i + 1500].push_back({i, w});
		dis[i][i + 1500] = w;
		dis[i + 1500][i] = w;
	}
	for (int i = 1; i <= n; i++)
	{
		int a[d + 1], t[d + 1];
		int k;
		cin >> k;
		for (int p = 1; p <= k; p++)
		{
			cin >> a[p] >> t[p];
			zhan++;
			g[a[p] + 1500].push_back({1500 * 2 + zhan, t[p]});
			g[1500 * 2 + zhan].push_back({a[p] + 1500, t[p]});
			dis[a[p] + 1500][1500 * 2 + zhan] = t[p];
			dis[1500 * 2 + zhan][a[p] + 1500] = t[p];
			if (p > 1)
			{
				g[1500 * 2 + zhan - 1].push_back({1500 * 2 + zhan, 0});
				g[1500 * 2 + zhan].push_back({1500 * 2 + zhan - 1, 0});
				dis[1500 * 2 + zhan - 1][1500 * 2 + zhan] = 0;
				dis[1500 * 2 + zhan][1500 * 2 + zhan - 1] = 0;
			}
		}
	}
	for (int p = 1; p <= 4500; p++)
	{
		for (int i = 1; i <= 4500; i++)
		{
			if (dis[i][p] == 0x3f3f3f3f)
				continue;
			for (int j = 1; j <= 4500; j++)
			{
				if (dis[p][j] == 0x3f3f3f3f)
					continue;
				if (dis[i][p] + dis[p][j] < dis[i][j])
					dis[i][j] = dis[i][p] + dis[p][j];
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] << '\n';
	}
	return 0;
}
