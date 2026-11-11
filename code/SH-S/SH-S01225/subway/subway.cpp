#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int num[500010];
vector<pair<int, int> > g[50010];
int a[510][50010], t[510][50010];
bool vis[500010];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, Q;
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
	{
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][j];
			g[i].push_back(make_pair(a[i][j], t[i][j]));
		}
	}
	while (Q--)
	{
		int x, y;
		cin >> x >> y;
		q.push(x);
		int tmp[500010] = {};
		for (int i = 1; i <= m; i++)
		{
			tmp[i] = int(100000000000);
		}
		tmp[x] = 0;
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			vis[now] = 1;
			for (int w = 1; w <= n; w++)
			{
				int flag = 0;
				for (int i = 0; i < g[w].size(); i++)
				{
					if (g[w][i].first == now)
						flag = i;
				}
				if (flag != 0)
					for (int i = 0; i < g[w].size(); i++)
					{
						if (i != flag)
						{
							tmp[g[w][i].first] = min(tmp[g[w][i].first], tmp[now] + g[w][i].second + g[w][flag].second);
							if (!vis[g[w][i].first])
							{
								q.push(g[w][i].first);
								vis[g[w][i].first] = 1;
							}
						}
					}
			}
		}
		cout << num[x] + tmp[y] + num[y] << endl;
	}
	return 0;
}
