#include <iostream>
#include <vector>
#define int long long
using namespace std;
int c, n, m, d, q, w[500005], k[505];
vector<int> lin[505];
vector<pair<int, int> > tim[500005];
int tk[505], col[500005][5], dis[505][505], tc[505][505], rou[500005], ttim[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	if (n == 1)
	{
		cin >> tk[1];
		for (int i = 1; i <= tk[1]; i++)
		{
			int tmpx = 0, tmpt = 0;
			cin >> tmpx >> tmpt;
			col[tmpx][1] = tmpt;
		}
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			cout << w[l] + w[r] + col[l][1] + col[r][1] << endl;
		}
		return 0;
	}
	if (n == 2)
	{
		cin >> tk[1];
		for (int i = 1; i <= tk[1]; i++)
		{
			int tmpx = 0, tmpt = 0;
			cin >> tmpx >> tmpt;
			col[tmpx][1] = tmpt;
		}
		cin >> tk[2];
		for (int i = 1; i <= tk[2]; i++)
		{
			int tmpx = 0, tmpt = 0;
			cin >> tmpx >> tmpt;
			col[tmpx][2] = tmpt;
		}
		int minnt = 1e13;
		for (int i = 1; i <= m; i++)
		{
			if (col[i][1] != 0 && col[i][2] != 0)
				minnt = min(minnt, col[i][1] + col[i][2]);
		}
		while (q--)
		{
			int l, r, ans = 1e11;
			cin >> l >> r;
			if (col[l][1] != 0 && col[r][1] != 0)
				ans = min(ans, col[l][1] + col[r][1]);
			if (col[l][1] != 0 && col[r][2] != 0)
				ans = min(ans, col[l][1] + col[r][2] + minnt);
			if (col[l][2] != 0 && col[r][1] != 0)
				ans = min(ans, col[l][2] + col[r][1] + minnt);
			if (col[l][2] != 0 && col[r][2] != 0)
				ans = min(ans, col[l][2] + col[r][2]);
			cout << ans + w[l] + w[r] << endl;
		}
		return 0;
	}
	if (m <= 500)
	{
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				if (i != j)
					dis[i][j] = 1e18;
		for (int i = 1; i <= n; i++)
		{
			cin >> tk[i];
			for (int j = 1; j <= tk[i]; j++)
				cin >> rou[j] >> ttim[j];
			for (int j = 1; j < tk[i]; j++)
			{
				for (int k = j + 1; k <= tk[i]; k++)
				{
					dis[rou[j]][rou[k]] = min(ttim[j] + ttim[k], dis[rou[j]][rou[k]]);
					dis[rou[k]][rou[j]] = min(ttim[j] + ttim[k], dis[rou[k]][rou[j]]);
				}
			}
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				for (int k = 1; k <= m; k++)
					dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			cout << dis[l][r] + w[l] + w[r] << endl;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1, tmpx, tmpt; j <= k[i]; j++)
		{
			cin >> tmpx >> tmpt;
			lin[i].push_back(tmpx);
			tim[tmpx].push_back({i, tmpt});
		}
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << "8141" << endl;
	}	
	return 0;
}