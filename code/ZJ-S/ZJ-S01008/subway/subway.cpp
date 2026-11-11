#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 inf = 1e16;

struct Node
{
	int u, t;
};

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	vector<vector<pair<int, int>>> bel(m + 1);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int u_, t_;
			cin >> u_ >> t_;
			bel[u_].push_back({i, t_});
		}
	}
	vector<vector<i64>> f(n + 1, vector<i64>(n + 1, inf));
	for (int id = 1; id <= m; id++)
	{
		for (int i = 0; i < bel[id].size(); i++)
		{
			for (int j = i + 1; j < bel[id].size(); j++)
			{
				int u = bel[id][i].first, v = bel[id][j].first;
				i64 t1 = bel[id][i].second, t2 = bel[id][j].second;
				f[u][v] = t1 + t2;
				f[v][u] = t1 + t2;
			}
		}
	}
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		i64 ans = w[x] + w[y];
		i64 tmp = inf;
		for (int i = 0; i < bel[x].size(); i++)
		{
			for (int j = 0; j < bel[y].size(); j++)
			{
				int u = bel[x][i].first, v = bel[y][j].first;
				i64 t1 = bel[x][i].second, t2 = bel[y][j].second;
				if (f[u][v] != inf)
				{
					tmp = min(tmp, f[u][v] + t1 + t2);
				}
			}
		}
		cout << ans + tmp << "\n";
	}
	return 0;
}
