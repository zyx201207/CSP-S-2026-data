#include<bits/stdc++.h>
using namespace std;
struct g{
	long long to,next_,val;
}edge[5000005];
long long w[500005],a[500005],t[500005],head[500005],tot;
long long c,n,m,D,Q,k[505],vis[500005],d[1005][1005];
void add(long long x,long long y,long long z)
{
	edge[++tot].to=y;
	edge[tot].val=z;
	edge[tot].next_=head[x];
	head[x]=tot;
}
priority_queue<pair<long long,long long> > q;
void dij(long long s)
{
	for(long long i=1;i<=m;i++)
	{
		d[s][i]=(long long)1<<60;
		vis[i]=0;
	}
	d[s][s]=0;
	q.push({0,s});
	while(q.size())
	{
		long long x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(long long i=head[x];i;i=edge[i].next_)
		{
			long long y=edge[i].to,z=edge[i].val;
			if(vis[y]) continue;
			if(d[s][y]>d[s][x]+z)
			{
				d[s][y]=d[s][x]+z;
				q.push({-d[s][y],y});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&Q);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
			for(long long z=1;z<j;z++)
			{
				add(a[z],a[j],t[j]+t[z]);
				add(a[j],a[z],t[j]+t[z]);
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		dij(i);
	}
	while(Q--)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",d[x][y]+w[x]+w[y]);
	}
	return 0;
}