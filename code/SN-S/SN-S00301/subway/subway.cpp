//注意到无疑是简单题
//d和n数据范围这么小，无疑是突破口
//代码还稍微有点繁杂，争取四点半之前写完调完
//首先要维护每个站厅所对应的每个站台和站台个数，开一个数组
//然后要存储每个站台的所属站厅和线路编号，开一个结构体
//然后要建一张求线路之间最短路的图，并且做dijkstra，用邻接矩阵就行了 
#include<bits/stdc++.h>

using namespace std;

#define N 500005
#define int long long

int n, m, Q, D, W[N]; 
struct node{int id, t;};//站台对应的线路编号和站厅到站台时间 
vector<node> b[N];
int g[505][505], dis[505][505], vis[505];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

void dijkstra(int s)
{
	for(int i = 1; i <= n; i++)vis[i] = 0;
	q.push({0, s});
	while(!q.empty())
	{
		int u = q.top().second; q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int v = 1; v <= n; v++)
			if(u != v && dis[s][v] > dis[s][u] + g[u][v])
			{
				dis[s][v] = dis[s][u] + g[u][v];
				if(!vis[v])q.push({dis[s][v], v});
			}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> n >> m >> D >> Q;
	for(int i = 1; i <= m; i++)cin >> W[i];
	for(int j = 1; j <= n; j++)
	{
		int k, u, t; 
		cin >> k;
		for(int i = 1; i <= k; i++)
			cin >> u >> t, b[u].push_back({j, t});
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)dis[i][j] = dis[j][i] = g[i][j] = g[j][i] = 1e16;
			else dis[i][j] = g[i][j] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int x = 0; x < b[i].size(); x++)
			for(int y = x + 1; y < b[i].size(); y++)
			{
				int idx = b[i][x].id, idy = b[i][y].id;
				g[idx][idy] = g[idy][idx] = min(g[idx][idy], b[i][x].t + b[i][y].t);
			}
	}
	for(int i = 1; i <= n; i++)dijkstra(i);
	int u, v;
	while(Q--)
	{
		cin >> u >> v;
		int ans = 1e16;
		for(int x = 0; x < b[u].size(); x++)
			for(int y = 0; y < b[v].size(); y++)
				ans = min(ans, dis[b[u][x].id][b[v][y].id] + b[u][x].t + b[v][y].t);
		ans += W[u] + W[v];
		cout << ans << "\n";
	}
	return 0;
}
