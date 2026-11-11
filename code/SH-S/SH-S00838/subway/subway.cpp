#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Edge
{
	int to , w;
};

struct Node
{
	int id;
	long long dist;
	friend bool operator<(const Node &x , const Node &y)
	{
		return x.dist > y.dist;
	}
};

vector<Edge> b[500010];
priority_queue<Node> pq;

int c , n , m , d , q , a[500010];
long long g[510][510] , dis[510][510];

void dijkstra(int s , long long dist[])
{
	while (!pq.empty()) pq.pop();
	dist[s] = 0;
	pq.push({s , 0});
	while (!pq.empty())
	{
		Node nd = pq.top();
		pq.pop();
		int x = nd.id;
		if (nd.dist != dist[x]) continue;
		for (int y = 1; y <= n; y++)
		{
			if (g[x][y] > 1e18) continue;
			if (dist[y] > dist[x] + g[x][y])
			{
				dist[y] = dist[x] + g[x][y];
				pq.push({y , dist[y]});
			}
		}
	}
}

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++)
		{
			int to , w;
			cin >> to >> w;
			b[to].push_back({i , w});
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = dis[i][j] = 9e18;
		}
		g[i][i] = 0;
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%lld " , g[i][j]);
		}
		puts("");
	}
	puts("");
	*/
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			for (int k = 0; k < b[i].size(); k++)
			{
				g[b[i][j].to][b[i][k].to] = min(g[b[i][j].to][b[i][k].to] , (long long)b[i][j].w + b[i][k].w);
			}
		}
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%lld " , g[i][j]);
		}
		puts("");
	}
	puts("");
	*/
	for (int i = 1; i <= n; i++)
	{
		dijkstra(i , dis[i]);
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%lld " , dis[i][j]);
		}
		puts("");
	}
	puts("");
	*/
	while (q--)
	{
		int x , y;
		cin >> x >> y;
		long long ans = 9e18;
		for (int i = 0; i < b[x].size(); i++)
		{
			for (int j = 0; j < b[y].size(); j++)
			{
				ans = min(ans , (((dis[b[x][i].to][b[y][j].to] + a[x]) + a[y]) + b[x][i].w) + b[y][j].w);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
