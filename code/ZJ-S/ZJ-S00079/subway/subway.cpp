#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
ll read()
{
	ll k=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}
const int N=510,M=5e5+10;
ll c,n,m,d,q,x,y,k[N],w[M],vis[M];
ll dis[N][N];
vector<pair<ll,ll>>b[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1; i<=m; ++i)
		w[i]=read();
	for(int i=1; i<=n; ++i)
	{
		k[i]=read();
		for(int j=1; j<=k[i]; ++j)
		{
			x=read();vis[x]++;
			y=read();
			b[x].push_back({i,y});
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(i!=j)
				dis[i][j]=1e18;
		}
	}
	for(int i=1; i<=m; ++i)
	{
		for(int j=0; j<vis[i]; ++j)
		{
			for(int k=j+1; k<vis[i]; ++k)
			{
				x=b[i][j].F;y=b[i][k].F;
				dis[x][y]=min(dis[x][y],b[i][j].S+b[i][k].S);
				dis[y][x]=min(dis[y][x],b[i][j].S+b[i][k].S);
			}
		}
	}
	for(int k=1; k<=n; ++k)
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	while(q--)
	{
		x=read();y=read();
		ll ans=1e18;
		for(auto i:b[x])
		{
			for(auto j:b[y])
				ans=min(ans,w[x]+w[y]+dis[i.F][j.F]+i.S+j.S);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
