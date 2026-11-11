#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c;
ll n,m,d,q;
ll w[500010];
struct plt{
	ll ln;
	ll tm;
};
vector<plt> p[500010];
ll g[510][510];
ll dis[510][510];
bool vis[510];
void floyd()
{
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		dis[i][i]=0;
		for(int j=1;j<=n;++j)
		{
			ll mn=0;
			for(int k=1;k<=n;++k)
			{
				if(!vis[k]&&dis[i][k]<dis[i][mn]) mn=k;
			}
			vis[mn]=1;
			for(int k=1;k<=n;++k)
			{
				if(!vis[k]&&g[mn][k])
				{
					dis[i][k]=min(dis[i][k],dis[i][mn]+g[mn][k]);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		ll e;
		cin>>e;
		for(int j=1;j<=e;++j)
		{
			ll x,y;
			cin>>x>>y;
			p[x].push_back((plt){i,y});
		}
	}
	
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<p[i].size();++j)
		{
			for(int k=j+1;k<p[i].size();++k)
			{
				if(g[p[i][j].ln][p[i][k].ln]) g[p[i][j].ln][p[i][k].ln]=min(g[p[i][j].ln][p[i][k].ln],p[i][j].tm+p[i][k].tm);
				else g[p[i][j].ln][p[i][k].ln]=p[i][j].tm+p[i][k].tm;
			}
		}
	}
	floyd();
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=1000000000000000000;
		for(int i=0;i<p[x].size();++i)
		{
			for(int j=0;j<p[y].size();++j)
			{
				ans=min(ans,dis[p[x][i].ln][p[y][j].ln]+w[x]+w[y]+p[x][i].tm+p[y][j].tm);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
