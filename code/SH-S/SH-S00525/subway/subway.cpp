#include <bits/stdc++.h>
using namespace std;
#define int long long int 
int w[550005];
int dist[550005];
//int vis[550005];
vector <pair<int,int>> g[550005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			int a,t;
			cin >> a >> t;
			g[i].push_back({a+n,t});
			g[a+n].push_back({i,t});
		}
	}

	while (q--)
	{
		int x,y;
		cin >> x >> y;
		fill(dist+1,dist+n+m+1,1e9);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({0,x+n});
		dist[x+n] = 0;
		while (!pq.empty())
		{
			pair<int,int> t = pq.top();
			pq.pop();
			
			int u = t.second;
			if (dist[u] < t.first)
				continue;
			for (pair<int,int> uv : g[u])
			{
				int v = uv.first,w = uv.second;
				if (dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					pq.push({dist[v],v});
				}
			}
		}
		cout << dist[n+y]+w[x]+w[y] <<'\n';
	}
}
