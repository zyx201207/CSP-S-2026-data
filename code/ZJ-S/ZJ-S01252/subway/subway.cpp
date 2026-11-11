#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5,maxn=505;
#define ll long long
ll read()
{
	ll ans=0;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-48;
		c=getchar();
	}
	return ans;
}
struct edge{
	ll v,w;
};
ll n,m,c,d,q;
ll w[maxm],dis[maxn][maxn]; 
vector<edge> mp[maxm];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	ll k,x,t;
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			x=read(),t=read();
			mp[x].push_back({i,t}); 
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int u=1;u<=m;u++)
	{
		for(int j=0;j<mp[u].size();j++)
		{
			for(int k=j+1;k<mp[u].size();k++)
			{
				ll v1=mp[u][j].v,v2=mp[u][k].v;
				dis[v1][v2]=dis[v2][v1]=mp[u][j].w+mp[u][k].w;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	ll u,v;
	while(q--)
	{
		u=read(),v=read();
		ll ans=1e18;
		for(int i=0;i<mp[u].size();i++)
		{
			for(int j=0;j<mp[v].size();j++)
			{
				int du=mp[u][i].v,dv=mp[v][j].v;
				ans=min(ans,mp[u][i].w+mp[v][j].w+dis[du][dv]);
			}
		}
		ans+=w[u]+w[v];
		printf("%lld\n",ans);
	} 
	return 0;
}//15:18
