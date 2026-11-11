#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;
const int N = 505, M = 5e5 + 5;
const ll INF = 9223372036854775800;
struct Edge
{
	int v;
	ll w;
	bool operator > (const Edge &xx) const
	{
		return w > xx.w;
	}
};
int idx, c, n, m, d, q, k[N], B = 5e5;
ll W[M], dis[M*2];
bool vis[M*2];
vector<Edge> g[M*2];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	IOS;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> W[i];
	if(c == 0) B = 2e4;
	else if(c >= 1 && c <= 3) B = 10;
	else if(c >= 4 && c <= 6) B = 300;
	else if(c >= 7 && c <= 8) B = 400;
	else if(c >= 9 && c <= 11) B = 1000;
	else if(c >= 12 && c <= 15) B = 2e4;
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1, v; j <= k[i]; j++)
		{
			ll w;
			cin >> v >> w;
			g[++idx].push_back({v + B, w});
			g[v + B].push_back({idx, w});
			if(j >= 2)
			{
				g[idx].push_back({idx - 1, 0});
				g[idx - 1].push_back({idx, 0});
			}
		}
	}
	while(q--)
	{
		int start, end;
		cin >> start >> end;
		for(int i = 1; i < 2 * B; i++)
		{
			if(dis[i] != INF) dis[i] = INF, vis[i] = 0;
		} 
		priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
		pq.push({start + B, 0});
		dis[start + B] = 0;
		while(!pq.empty())
		{
			int u = pq.top().v;
			pq.pop();
			vis[u] = 1;
			for(Edge i : g[u])
			{
				int v = i.v;ll w = i.w;
				if(dis[v] > dis[u] + w)
				{
					dis[v] = dis[u] + w;
					if(vis[v] == 0)
						pq.push({v, dis[v]});
				}
			}
		}
		cout << dis[end + B] + W[start] + W[end] << '\n';
	}
	return 0;
}
