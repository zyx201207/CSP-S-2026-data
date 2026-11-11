#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const long long Inf = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
	long long v, w;
};
long long c, n, m, d, q, w[500005], k, a, t, x, y, dis[505][505], ans;
vector <Edge> g[500005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;++i)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;++i)
	{
		cin >> k;
		for (int j = 1;j <= k;++j)
		{
			cin >> a >> t;
			g[a].emplace_back((Edge){i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1;i <= n;++i)
	{
		dis[i][i] = 0;
	}
	for (int i = 1;i <= m;++i)
	{
		for (int j = 0;j < (int)g[i].size() - 1;++j)
		{
			for (int k = j + 1;k < (int)g[i].size();++k)
			{
				dis[g[i][j].v][g[i][k].v] = dis[g[i][k].v][g[i][j].v] = min(dis[g[i][j].v][g[i][k].v], g[i][j].w + g[i][k].w);
			}
		}
	}
	for (int k = 1;k <= n;++k)
	{
		for (int i = 1;i <= n;++i)
		{
			for (int j = 1;j <= n;++j)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--)
	{
		cin >> x >> y;
		ans = Inf;
		for (int i = 0;i < (int)g[x].size();++i)
		{
			for (int j = 0;j < (int)g[y].size();++j)
			{
				ans = min(ans, w[x] + w[y] + g[x][i].w + g[y][j].w + dis[g[x][i].v][g[y][j].v]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
