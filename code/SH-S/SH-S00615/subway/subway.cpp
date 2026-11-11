#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max();
//const ll INF = 0x7FFFFFFF;
const int N = 505;
const int M = 500005;
//const int M = 20010;
const int D = 25;

int c;		// 测试点编号 
int n, m;	// 线路 站 
int d, q;	// 每站有的地铁线 出行计划 

ll w[M];	// 站 v 站厅-口的时间  
//int k[N];	// i 线路的地铁站数量 
//ll a[N][D]; // i 线路的第 j 个地铁站
//ll t[N][D]; // i 线路的第 j 个地铁站站厅-站台的时间 

struct Edge
{
	int v;
	ll w;
};

struct Node
{
	int id;
	ll w;
	bool operator<(const Node &o) const
	{
		return w > o.w;
	}
};

vector<Edge> g[M + N];
//ll dis[N][M + N];
unordered_map<int, ll> dis[N];
bool vis[M + N];

void dj(int x)
{
	int s = x - m;
//	cout <<s << endl;
	for (int i = 0; i <= n + m; ++i)
	{
		vis[i] = false;
		dis[s][i] = INF;
	}
	priority_queue<Node> pq;
	pq.push({x, dis[s][x] = 0});
	while (!pq.empty())
	{
		int u = pq.top().id;
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (const Edge &e : g[u])
		{
			int v = e.v;
			ll w = e.w;
			if (dis[s][u] + w < dis[s][v])
			{
				pq.push({v, dis[s][v] = dis[s][u] + w});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; ++i)
	{
//		cin >> k[i];
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
//			cin >> a[i][j] >> t[i][j];
			// 令地铁 i 为一个大结点 m + i
//			int u = m + i, v = a[i][j], w = t[i][j];
			int u = m + i, v, w;
			cin >> v >> w; 
			// 建立地铁站与地铁的边，边权为从站台走到站厅的用时 
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	
	// 从车站开始dj
	for (int i = m + 1; i <= m + n; ++i)
	{
		dj(i);
	}
	
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= m; ++j)
//		{
//			cout << dis[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	while (q--)
	{
		int x, y; // start, end
		cin >> x >> y;
		ll mind = INF;
		for (int i = 1; i <= n; ++i)
		{
			mind = min(mind, dis[i][x] + dis[i][y]);
		}
//		cout << mind << endl;
//		cout << "last " << q << endl;
		cout << w[x] + mind + w[y] << endl;
	}
	
	return 0;
}
 
