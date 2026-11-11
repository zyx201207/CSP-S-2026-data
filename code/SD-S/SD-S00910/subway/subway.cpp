#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
int c, n, m, d, Q, w[500005], dist[500505];
bool st[500505];
vector<pair<int, int> > e[500505];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		int k, a, t;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a >> t;
			e[a].push_back({i + m, t});
			e[i + m].push_back({a, t});
		}
	}
	while(Q--)
	{
		int x, y;
		cin >> x >> y;
		memset(dist, 0x3f, sizeof(dist));
		memset(st, 0, sizeof(st));
		priority_queue<pii, vector<pii >, greater<pii > > q;
		q.push({0, x});
		dist[x] = 0; 
		while(!q.empty())
		{
			pii res = q.top();
			q.pop();
			int u = res.second;
			if(u == y)
				break;
			if(st[u])
				continue;
			st[u] = 1;
			for(int i = 0;i < e[u].size();i++)
			{
				pii cur = e[u][i];
				int v = cur.first, w = cur.second;
				if(dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					q.push({dist[v], v});
				}
			}
		}
		cout << dist[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
