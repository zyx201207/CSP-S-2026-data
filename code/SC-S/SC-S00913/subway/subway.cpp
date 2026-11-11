#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
const int N=5e5+5;
long long head[N],wi[N],to[N],num,ne[N],t[N],dis[N],vis[N],bc[10000][10000];
long long c,n,m,d,q,k;
priority_queue<pair<long long,long long> >q1;
void add(int u,int v,int w)
{
	ne[num]=head[u];
	wi[num]=w;
	to[num]=v;
	head[u]=num++;
}
void dij(int zz)
{
	q1.push({0,zz});
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	vis[zz]=1;
	dis[zz]=0;
	while(q1.size())
	{
		int now=q1.top().second;
		q1.pop();
		for(int i=head[now];i!=-1;i=ne[i])
		{
			int w=wi[i];
			int go=to[i];
			if(dis[now]+w+t[now]<dis[go])
			{
				dis[go]=dis[now]+w;
				if(!vis[go])
				{
					q1.push({-dis[go],go});
					vis[go]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++)scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(m+i,x,y);
			add(x,m+i,y);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if(bc[x][y]!=0)
		{
			printf("%lld\n",bc[x][y]);
		}
		else
		{
			dij(x);
			for(int j=1;j<=m;j++)bc[x][j]=dis[j];
			printf("%lld\n",dis[y]+t[x]+t[y]);
		}
	}
	return 0;
}