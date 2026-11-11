#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
vector <pair <int, int> > a[500005];
//vector <pair <int, int> > g[505010]; 
int dis[505][505];
//int dis[505010][505];
//bool vis[505010][505];
/*
the station x : g[x]
the line x : g[500001 + x]
{point, time}
*/ 

//void dijkstra(int s, int id)
//{
//	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
//	dis[s][id] = 0;
//	q.push({0, s});
//	while (!q.empty())
//	{
//		pair <int, int> p = q.top();
////		cout << p.second << '\n';
//		q.pop();
//		if (vis[p.second][id]) continue;
//		vis[p.second][id] = 1;
//		for (int j = 0; j < g[p.second].size(); j++)
//		{
//			pair <int, int> i = g[p.second][j];
//			if (vis[i.first][id]) continue;
//			if (dis[p.second][id] + i.second < dis[i.first][id])
//			{
//				dis[i.first][id] = dis[p.second][id] + i.second;
//				q.push({dis[i.first][id], i.first});
//			}
//		}
//	}
//}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int au, tv;
			cin >> au >> tv;
			a[au].push_back({tv, i});
//			g[500001 + i].push_back({au, tv});
//			g[au].push_back({500001 + i, tv});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			for (int k = j + 1; k < a[i].size(); k++)
			{
				dis[a[i][j].second][a[i][k].second] = dis[a[i][k].second][a[i][j].second] = min(dis[a[i][j].second][a[i][k].second], a[i][j].first + a[i][k].first);
			}
		}
	} 
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
//	memset(vis, 0, sizeof(vis));
//	memset(dis, 0x3f, sizeof(dis));
//	for (int i = 1; i <= n; i++)
//		dijkstra(500001 + i, i);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		int minn = 0x3f3f3f3f3f3f3f3f;
		for (int j = 0; j < a[x].size(); j++)
		{
			for (int k = 0; k < a[y].size(); k++)
			{
				minn = min(minn, dis[a[x][j].second][a[y][k].second] + a[x][j].first + a[y][k].first);
			}
		}
//		cout << ans << ' ' << minn << ' ';
		cout << ans + minn << '\n';
	}
	return 0;
}
