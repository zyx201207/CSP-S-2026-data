#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define F first
#define S second

const ll MN=510;
const ll MM=5e5+10;
const ll INF=LLONG_MAX/2-10;
ll c,n,m,d,q;
ll w[MM];
vector<pair<ll,ll>> g[MM+MN];
ll di[MM+MN];
ll dist[MN][MN];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1,k;i<=n;i++)
	{
		cin>>k;
		for(ll j=1,a,t;j<=k;j++)
		{
			cin>>a>>t;
			g[a].push_back({MM+i,t});
			g[MM+i].push_back({a,t});
		}
	}
	for(ll i=1;i<=n;i++)
	{
		priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> qu;
		for(ll j=0;j<=m;j++)
			di[j]=INF;
		for(ll j=0;j<=n;j++)
			di[MM+j]=INF;
		qu.push({0,MM+i});
		di[MM+i]=0;
		while(!qu.empty())
		{
			ll u=qu.top().S;
			ll cost=qu.top().F;
			qu.pop();
			if(cost>di[u])
				continue;
			for(auto&ee:g[u])
			{
				ll v=ee.F;
				cost=ee.S;
				if(di[v]>di[u]+cost)
				{
					di[v]=di[u]+cost;
					qu.push({di[v],v});
				}
			}
		}
		for(ll j=1;j<=n;j++)
		{
			dist[i][j]=di[MM+j];
//			cout<<dist[i][j]<<' ';
		}
//		cout<<'\n';
	}
	while(q--)
	{
		ll x,y,ans=INF;
		cin>>x>>y;
		for(auto&ex:g[x])
		{
			for(auto&ey:g[y])
			{
				ans=min(ans,ex.S+ey.S+dist[ex.F-MM][ey.F-MM]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
