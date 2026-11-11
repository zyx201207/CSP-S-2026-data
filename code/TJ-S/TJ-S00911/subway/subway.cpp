#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], t[505][1005];
long long dis[500005];
vector<int> g[1000005];

struct node
{
	int x;
	long long d;
	bool operator< (const node &b) const
	{
		return d > b.d;
	}
};

void dij(int s)
{
	priority_queue<node> q;
	cout << t[1][1] << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dis[(i - 1) * n + j] = 9e18;
		}
		if (t[i][s] != -1)
		{
			q.push({(i - 1) * n + s, 1ll * t[i][s]});
			dis[(i - 1) * n + s] = t[i][s];
		}
	}
	cout << endl;
	while (!q.empty())
	{
		int x = q.top().x;
		long long d = q.top().d;
		q.pop();
		for (int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i];
			dis[y] = dis[x];
			q.push({y, dis[y]});
		}
		int u = x / m, v = x % m;
		for (int i = 1; i <= n; i++)
		{
			if (i == u) continue;
			if (t[i][v] == -1) continue;
			if (dis[(i - 1) * n + v] > dis[x] + t[u][v] + t[i][v])
			{
				dis[(i - 1) * n + v] = dis[x] + t[u][v] + t[i][v];
				q.push({(i - 1) * n + v, dis[(i - 1) * n + v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			t[i][j] = -1;
		}
		int k, last = 0, x;
		cin >> k >> last >> t[i][last];
		cout << t[i][last] << endl;
		last = (i - 1) * m + last;
		for (int j = 2; j <= k; j++)
		{
			cin >> x >> t[i][x];
			x = (i - 1) * m + x;
			g[last].push_back(x);
			g[x].push_back(last);
			last = x;
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		dij(x);
		long long ans = 9e18;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans, dis[(i - 1) * n + y] + t[i][y]);
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
