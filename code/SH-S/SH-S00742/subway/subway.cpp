#include <bits/stdc++.h>
#define ll long long
#define maxn 1003
using namespace std;
ll point_id, n, m, max_l, Q;
ll d[maxn];
struct edge
{
	ll v;
	ll w;
};
vector<edge> g[maxn * 2];
bool vis[maxn * 2];
ll dist[maxn][maxn * 2];
struct bckp
{
	ll p;
	ll k;
	operator < (const bckp &other) const
	{
		return k > other.k;
	}
};
priority_queue<bckp> q;
void dij(int t)
{
	while(!q.empty()) q.pop();
	memset(dist[t], 0x3f, sizeof(dist[t]));
	memset(vis, 0, sizeof(vis));
	q.push({t, 0});
	dist[t][t] = 0;
	while(!q.empty())
	{
		ll pos = q.top().p, sum = q.top().k;
		q.pop();
		if(vis[pos])
			continue;
		vis[pos] = 1;
		for(auto cur : g[pos])
		{
			if(dist[t][pos] + cur.w <= dist[t][cur.v])
				dist[t][cur.v] = dist[t][pos] + cur.w, 
				q.push({cur.v, dist[t][cur.v]});
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> point_id >> m >> n >> max_l >> Q;
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	for(int i = 1; i <= m; i++)
	{
		int k, v, w;
		cin >> k;
		while(k--)
		{
			cin >> v >> w;
			g[n + i].push_back({v, w});
			g[v].push_back({n + i, w});
		}
	}
	for(int i = 1; i <= n; i++)
		dij(i);
	while(Q--)
	{
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] + d[x] + d[y] << endl;
	}
	return 0;
}
