#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long LL;

int c, n, m, d, q;
int w[500005];
vector<pair<int, int>> g[500005];
LL dis[502][502];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			g[a].push_back({ i, t });
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto u : g[i])
			for (auto v : g[i])
				if (u.first != v.first)
					dis[u.first][v.first] = min(dis[u.first][v.first], (LL)u.second + v.second);
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		LL mn = inf;
		for (auto u : g[x])
			for (auto v : g[y]) mn = min(mn, dis[u.first][v.first] + u.second + v.second);
		cout << w[x] + mn + w[y] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/