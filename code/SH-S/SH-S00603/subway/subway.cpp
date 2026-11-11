#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 10;
int c, n, m, d, q;	//测试点 地铁路数 地铁站数 地铁站最多被经过次数 询问数
int w[M];
int to[M], t[M];
int dis[M][30];
bool vis[M][30];
vector<pair<int, pair<int, int> > > ee[M][30];	//ee[i][j]表示一条从第j条铁路的i号站点
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > qu;
void dijkstra(int r)
{
	qu.push({0, {r, 0}});
	dis[r][0] = 0;
	while(!qu.empty())
	{
		auto head = qu.top();
		qu.pop();
		int u = head.second.first, id = head.second.second;
		if(vis[u][id]) continue;
		vis[u][id] = true;
		for(auto it : ee[u][id])
		{
			int ww = it.first, v = it.second.first, newid = it.second.second;
			if(dis[u][id] + ww < dis[v][newid])
			{
				dis[v][newid] = dis[u][id] + ww;
				qu.push({dis[u][id] + ww, {v, newid}});
			}
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++) cin >> to[j] >> t[j];
		for(int j = 1; j <= k; j ++)
		{
			ee[to[j]][0].push_back({t[j], {to[j] ,i}});
			ee[to[j]][i].push_back({t[j], {to[j], 0}});
		}
		for(int j = 2; j <= k; j ++)
		{
			ee[to[j - 1]][i].push_back({0, {to[j], i}});
			ee[to[j]][i].push_back({0, {to[j - 1], i}});
		}
	}
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		memset(vis, 0, sizeof vis);
		memset(dis, 0x7f, sizeof dis);
		dijkstra(x);
		int ans = dis[y][0] + w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
