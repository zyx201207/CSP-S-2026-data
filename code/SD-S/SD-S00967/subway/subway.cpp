#include<bits/stdc++.h>
using namespace std;
int fir[500002],nxt[500002],to[500002],tp=0;
long long w[500002],dis[502][502];
int t[500002],sz[500002];
void add(int u,int v,int d)
{
	tp++;
	nxt[tp]=fir[u];
	fir[u]=tp;
	to[tp]=v;
	w[tp]=d;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q,k,a,uu,vv;
	long long s;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%lld",&a,&s);
			add(a,i,s);
			sz[a]++;
		}
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		if(sz[i]<2)
		{
			continue;
		}
		for(int u=fir[i];u;u=nxt[u])
		{
			for(int v=fir[i];v;v=nxt[v])
			{
				uu=to[u];
				vv=to[v];
				if(uu!=vv)
				{
					dis[uu][vv]=min(dis[uu][vv],w[u]+w[v]);
					dis[vv][uu]=min(dis[vv][uu],dis[uu][vv]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	int x,y;
	for(;q;q--)
	{
		scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int u=fir[x];u;u=nxt[u])
		{
			for(int v=fir[y];v;v=nxt[v])
			{
				uu=to[u];
				vv=to[v];
				ans=min(ans,dis[uu][vv]+w[u]+w[v]);
			}
		}
		ans+=t[x];
		ans+=t[y];
		printf("%lld\n",ans);
	}
	return 0;
}
