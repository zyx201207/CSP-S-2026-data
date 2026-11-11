#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int MX = 5e5 + 5;
const int inf = 1e18;

int c,n,m,d,q;
vector<pii> e[MX];
int cnt[MX];
int dis[MX * 4];
int mx;

void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	fill(dis + 1,dis + mx + 1,inf);
	dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
		if(du > dis[u]) continue;
		for(int i = 0;i < e[u].size();i++)
		{
			int v = e[u][i].first;
			int w = e[u][i].second;
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	mx = 2 * m;
	for(int i = 1;i <= m;i++)
	{
		int w; cin >> w;
		e[i].push_back({m + i,w});
		e[m + i].push_back({i,w});
		cnt[i] = 2;
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		if(k == 2)
		{
			int u,t1,v,t2;
			cin >> u >> t1 >> v >> t2;
			e[u + m].push_back({v + m,t1 + t2});
			e[v + m].push_back({u + m,t1 + t2});
			continue;
		}
		int pre = 0;
		for(int j = 1;j <= k;j++)
		{
			int u,t;
			cin >> u >> t;
			e[cnt[u] * m + u].push_back({m + u,t});
			e[m + u].push_back({cnt[u] * m + u,t});
			if(pre != 0)
			{
				e[pre].push_back({cnt[u] * m + u,0});
				e[cnt[u] * m + u].push_back({pre,0});
			}
			pre = cnt[u] * m + u;
			mx = max(mx,pre);
			cnt[u]++;
		}
	}
	while(q--)
	{
		int s,t;
		cin >> s >> t;
		dij(s);
		cout << dis[t] << '\n';
	}
	return 0;
}
