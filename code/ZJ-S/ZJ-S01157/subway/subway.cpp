#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point
{
	ll a,t,line;
};
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,st,ed,a,t,w[500010],k[510],dist[500010];
bool vis[500010];
vector<point> g[500010],lin[510];
ll bfs(ll s,ll t)
{
	for(ll i = 1;i <= m;i++) dist[i] = INF,vis[i] = 0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	q.push({w[s],s});
	dist[s] = w[s];
	while(!q.empty())
	{
		ll u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v : g[u])
		{
			for(auto l : lin[v.line])
			{
				if(l.a != u)
				{
					if(dist[l.a] > dist[u] + v.t + l.t)
					{
						dist[l.a] = dist[u] + v.t + l.t;
						q.push({dist[l.a],l.a});
					}
				}
			}
		}
	}
	return dist[t] + w[t];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i <= m;i++) cin >> w[i];
	for(ll i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(ll j = 1;j <= k[i];j++)
		{
			cin >> a >> t;
			lin[i].push_back({a,t,i});
			g[a].push_back({a,t,i});
		}
	}
	while(q--)
	{
		cin >> st >> ed;
		cout << bfs(st,ed) << endl;
	}
	return 0;
}
