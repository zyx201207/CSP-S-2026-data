#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll c,n,m,d,q,tot;
struct node
{
	ll u,w;
};
vector<node>g[20005];
ll dis[20005];
void dijstra(ll s,ll e)
{
	for(ll i=1;i<=20000;i++)
	{
		dis[i]=1e18;
	}
	dis[s]=0;
	priority_queue<pii>q;
	q.push({0,s});
	while(!q.empty())
	{
		ll ds=q.top().first,tmp=q.top().second;
		q.pop();
		if(ds!=-dis[tmp])
		{
			continue;
		}
		for(ll i=0;i<g[tmp].size();i++)
		{
			node v=g[tmp][i];
			ll u=v.u;
			ll w=v.w;
			if(dis[u]>dis[tmp]+w)
			{
				dis[u]=dis[tmp]+w;
				q.push({-dis[u],u});
			}
		}
	}
	cout<<dis[e]<<"\n";
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		ll w;
		cin>>w;
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}
	tot=2*m;
	for(ll i=1;i<=n;i++)
	{
		ll k,pre;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll a,t;
			cin>>a>>t;
			tot++;
			g[tot].push_back({a+m,t});
			g[a+m].push_back({tot,t});
			if(j==1)
			{
				pre=tot;
			}
			else
			{
				g[tot].push_back({pre,0});
				g[pre].push_back({tot,0});
			}
		}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		dijstra(x,y);
	}
	return 0;
}
