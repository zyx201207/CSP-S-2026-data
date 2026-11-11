#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 310;
int a[N];
int c, t, n, m;
struct node
{
	int dis, pos;
	bool operator < (const node &x) const{
		return x.dis < dis;
	}
};
int vis[N], dis[N], ans[N];
vector <pair <int, int> > g[N];
priority_queue <node> q;
void dijkstra(int s)
{
	//memset(dis, 0x3f, sizeof dis);
	for(int i = 0; i <= n; i++) dis[i] = 1e18;
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty())
	{
		node x = q.top();
		q.pop();
		int u = x.pos;
		//if(vis[u]) continue;
		//vis[u] = 1;
		// for(auto qos : g[u])
		// {
		// 	int v = qos.first, w = qos.second;
		for(int i = 0; i < g[u].size(); i++)
		{
			pair <int,int> qos = g[u][i];
			int v = qos.first, w = qos.second;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
				ans[v] = 1;
			}
			else if(dis[v] == dis[u] + w)
			{
				q.push({dis[v], v});
				ans[v]++;
			}
		}
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	if(c <= 10)
	{
		while(t--)
		{
			cin >> n >> m;
			for(int i = 0; i <= n; i++) g[i].clear(), vis[i] = 0;
			for(int i = 1; i <= n; i++) cin >> a[i];
			for(int i = 1; i <= n; i++)
			{
				for(int j = i + 1; j <= n; j++)
				{
					if(abs(a[j] - a[i]) <= m) g[i].push_back({j, 1});
				}
			}
			int sum = 0;
			for(int i = 1; i < n; i++)
			{
				dijkstra(i);
				// for(int j = i + 1; j <= n; j++) cout << dis[j] << " ";
				// cout << "\n";
				// for(int j = 1; j <= n; j++) cout << ans[j] << " ";
				// cout << "\n";
				for(int j = i + 1; j <= n; j++) if(ans[j] == 2) sum++;
				for(int j = 1; j <= n; j++) ans[j] = 0, vis[j] = 0;
			}
			cout << sum << "\n";
		}
	}
	else
	{
		while(t--)
		{
			cin >> n >> m;
			int sum, ans = 0;
			for(int i = 1; i <= n; i++) cin >> a[i];
			sum = a[2] - a[1];
			ans = max((n - m / sum - 1), (int)0);
			cout << ans << "\n";
		}
	}
}