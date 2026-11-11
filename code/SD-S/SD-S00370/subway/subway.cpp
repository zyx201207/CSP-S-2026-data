#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
vector<pair<int, long long>>e[1050005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
long long dis[1050005];
bool vis[1050005];
long long ans[505][505];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		int w;
		cin >> w;
		e[i].push_back({m + i, w});
		e[m + i].push_back({i, w});
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			e[m + m + i].push_back({m + a, t});
			e[m + a].push_back({m + m + i, t});
		}
	}
	while(q--)
	{
		while(!pq.empty())pq.pop();
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		int u, V;
		cin >> u >> V;
		dis[u] = 0;
		pq.push({0, u});
		while(!pq.empty())
		{
			long long w = pq.top().first;
			int _u = pq.top().second;
			pq.pop();
			if(vis[_u])continue;
			vis[_u] = 1;
			for(auto v : e[_u])
			{
				if(v.second + w < dis[v.first])
				{
					dis[v.first] = w + v.second;
					pq.push({dis[v.first], v.first});
				}
			}
		}
		cout << dis[V] << '\n';
	}
	return 0;
}
