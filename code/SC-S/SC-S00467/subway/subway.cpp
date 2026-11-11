#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
#define ll long long
const ll inf=1e18;
int c,n,m,d,t,w[N];
ll dis[M][M];
#define a2 array<int,2>
vector<a2> q[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),t=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++) 
		{
			int x=read(),w=read();
			q[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<q[i].size();j++)
		{
			for(int k=j+1;k<q[i].size();k++)
			{
				int u=q[i][j][0],v=q[i][k][0];
				dis[u][v]=min(dis[u][v],1ll*q[i][j][1]+q[i][k][1]);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(t--)
	{
		int u=read(),v=read();
		ll ans=inf;
		for(auto x:q[u])
		{
			for(auto y:q[v]) ans=min(ans,dis[x[0]][y[0]]+x[1]+y[1]);
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
