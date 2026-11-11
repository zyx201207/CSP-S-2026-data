#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[510],visl[510],vis[510],ans=0;
struct nos
{
	ll vl,v,t;
};
vector<nos>g[510];
ll find(ll v)
{
	ll fl;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<g[i].size();j++)
		{
			if(g[i][j].v==v&&!visl[i])
			{
				visl[i]=1;
				fl=i;
				break;
			}
		}
	}
	return fl;
}
void dfs(ll f,ll e)
{
	if(f==e)
	{
		return ;
	}
	ll fl=find(f);
	for(ll i=0;i<g[fl].size();i++)
	{
		ll v=g[fl][i].v;
		ll vl=find(v);
		if(!vis[v])
		{
			vis[v]=1;
			if(fl!=vl)
			{
				ans+=g[vl][v].t;
			}
			ans+=g[fl][v].t;
			dfs(v,e);
			if(fl!=vl)
			{
				ans-=g[vl][v].t;
			}
			ans+=g[fl][v].t;
			vis[v]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll a;
			cin>>a;
			ll t1;
			cin>>t1;
			g[i].push_back({i,a,t1});
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		memset(visl,0,sizeof(visl));
		ll x,y;
		ans=w[x]+w[y];
		cin>>x>>y;
		vis[x]=1;
		dfs(x,y);
		cout<<ans<<endl;
	}
}
