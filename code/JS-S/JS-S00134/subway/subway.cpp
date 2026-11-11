#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int num, val;
}a[505][20005];
int n, m, c, Q, d, dis[505], vis[505], cnt[505], w[505];
vector < pair < int, int > > g[505];
priority_queue < pair < int, int > , vector < pair < int, int > >, greater < pair < int, int > > > q;

void A ()
{
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 1)
			continue;
		g[a[i][1].num].push_back({a[i][2].num, a[i][1].val + a[i][2].val});
		g[a[i][2].num].push_back({a[i][1].num, a[i][1].val + a[i][2].val});		
	}
	while (Q--)
	{
		while (!q.empty())
			q.pop();
		int s, t;
		cin >> s >> t;
		for (int i = 1; i <= n; i++)
			dis[i] = 1e18, vis[i] = 0;
		dis[s] = 0;
		q.push({0, s});
		while (!q.empty())
		{
			int now = q.top().second;
			q.pop();
			if (vis[now])
				continue;
			vis[now] = 1;
			for (auto e : g[now])
			{
				if (!vis[e.first] && dis[e.first] > dis[now] + e.second)
				{
					dis[e.first] = dis[now] + e.second;
					q.push({dis[e.first], e.first});
				}
			}
		}
		cout << dis[t] + w[s] + w[t] << "\n";
	}
}

signed main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> cnt[i];
		for (int j = 1; j <= cnt[i]; j++)
			cin >> a[i][j].num >> a[i][j].val;
	}
	if (c == 0 || c == 7 || c == 8 || c == 9 || c == 10 || c == 11)
		A();
	return 0;
}
