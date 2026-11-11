#include<bits/stdc++.h>
using namespace std;
const int N=500505;
int tot,head[N],to[N<<1],nxt[N<<1];
int c,n,m,d,q,vall[N];
long long f[505][505],weight[N<<1];
inline void add_edge(int u,int v,long long w)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	weight[tot]=w;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,k,u,v;
	long long ans,w;
	memset(f,0x3f,sizeof(f));
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;++i) scanf("%d",&vall[i]);
	for(i=1;i<=n;++i)
	{
		u=i;
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d %lld",&v,&w);
			v+=n;
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
	}
	for(u=1;u<=n;++u)
	{
		for(j=head[u];j;j=nxt[j])
		{
			v=to[j];
			for(k=head[v];k;k=nxt[k])
			{
				if(i==to[k]) continue;
				f[u][to[k]]=min(f[u][to[k]],weight[j]+weight[k]);
			}
		}
	}
	for(k=1;k<=n;++k)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(i==j) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		ans=0x3f3f3f3f3f3f3f3f;
		scanf("%d %d",&u,&v);
		for(i=head[u+n];i;i=nxt[i])
		{
			for(j=head[v+n];j;j=nxt[j])
			{
				if(to[i]==to[j]) ans=min(ans,weight[i]+weight[j]);
				else ans=min(ans,f[to[i]][to[j]]+weight[i]+weight[j]);
			}
		}
		printf("%lld\n",vall[u]+vall[v]+ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
