#include<bits/stdc++.h>
using namespace std;
const long long N = 505, M = 5e5 + 5, inf = 1e18;
long long n, m, q, k, x, y, w[M], cnt[M], nw, mn, dis[N][N], f[N], ans[N][N], Ans;
vector <pair<int, int> > v[M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> q >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
		v[i].push_back({0, 0});
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			cin >> x >> y;
			v[x].push_back({i, y});
			cnt[x]++;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (i != j)
			{
				dis[i][j] = inf;
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= cnt[i];j++)
		{
			for (int l = j + 1;l <= cnt[i];l++)
			{
				dis[v[i][j].first][v[i][l].first] = dis[v[i][l].first][v[i][j].first] = v[i][j].second + v[i][l].second;
			}
		}
	}
	for (int t = 1;t <= n;t++)
	{
		for (int i = 1;i <= n;i++)
		{
			f[i] = 0;
			ans[t][i] = inf;
		}
		nw = t, ans[t][t] = 0;
		for (int i = 1;i <= n;i++)
		{
			f[nw] = 1;
			for (int j = 1;j <= n;j++)
			{
				ans[t][j] = min(ans[t][j], ans[t][nw] + dis[nw][j]);
			}
			mn = inf;
			for (int j = 1;j <= n;j++)
			{
				if (!f[j] && ans[t][j] < mn)
				{
					mn = ans[t][j], nw = j;
				}
			}
		}
	}
	while (q--)
	{
		cin >> x >> y;
		Ans = inf;
		for (int i = 1;i <= cnt[x];i++)
		{
			for (int j = 1;j <= cnt[y];j++)
			{
				Ans = min(Ans, w[x] + v[x][i].second + ans[v[x][i].first][v[y][j].first] + v[y][j].second + w[y]);
			}
		}
		cout << Ans << "\n";
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
