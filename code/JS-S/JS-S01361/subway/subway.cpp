#include <bits/stdc++.h>

using namespace std;
#define MAXN 510
#define MAXM 501000
#define LL long long

LL dis[MAXN][MAXN];

int c, n, m, d, q;
LL w[MAXM];
vector<int> a[MAXN], t[MAXN], s[MAXM], tt[MAXM];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		a[i].resize(k);
		t[i].resize(k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d%d", &a[i][j], &t[i][j]);
			// cout << a[i][j] << ' ' << t[i][j] << endl;
			s[a[i][j]].push_back(i);
			tt[a[i][j]].push_back(t[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = 0x3f3f3f3f3f3f3f3fll;
		}
	for (int i = 1; i <= m; i++)
	{
		// cout << i << ' ' << s[i].size() << endl;
		for (int x = 0; x < s[i].size(); x++)
			for (int y = x + 1; y < s[i].size(); y++)
			{
				int sx = s[i][x];
				int sy = s[i][y];
				LL dist = tt[i][x] + tt[i][y];
				// cout << i << ' ' << sx << ' ' << sy << ' '<< dist << ' ' << x << ' ' << y << endl;
				dis[sx][sy] = min(dis[sx][sy], dist);
				dis[sy][sx] = min(dis[sy][sx], dist);
			}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dis[i][j] << ' ';
	// 	cout << endl;
	// }
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dis[i][j] << ' ';
	// 	cout << endl;
	// }
	// LL tmp[510];
	// for (int i = 0; i <= n; i++)
	// 	tmp[i] = 0x3f3f3f3f3f3f3f3fll;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		LL ans = 0x3f3f3f3f3f3f3f3fll;

		// for (int i = 0; i < s[x].size(); i++)
		// {
		// 	int sx = s[x][i];
		// 	int tx = tt[x][i];
		// 	tmp[sx] = tx;
		// }
		// for (int i = 0; i < s[y].size(); i++)
		// {
		// 	int sy = s[y][i];
		// 	int ty = tt[y][i];
		// 	ans = min(ans, w[x] + w[y] + tmp[sy] + ty);
		// }
		// for (int i = 0; i < s[x].size(); i++)
		// {
		// 	int sx = s[x][i];
		// 	int tx = tt[x][i];
		// 	tmp[sx] = 0x3f3f3f3f3f3f3f3fll;
		// }
		// cout << x << ' ' << y << endl;

		for (int i = 0; i < s[x].size(); i++)
			for (int j = 0; j < s[y].size(); j++)
			{
				int sx = s[x][i];
				int sy = s[y][j];
				int tx = tt[x][i];
				int ty = tt[y][j];
				// cout << sx << ' ' << sy << ' ' << tx + ty + dis[sx][sy] << endl;
				ans = min(ans, w[x] + w[y] + tx + ty + dis[sx][sy]);
			}
		cout << ans << '\n';
	}
	return 0;
}