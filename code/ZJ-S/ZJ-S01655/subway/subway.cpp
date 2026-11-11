#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXN = 5e5+10;
const int MXM = 5e2+10;
const int MXE = 5e5+10;
const ll inf = (1ll<<60);

int ecnt,head[MXN];
struct edge{
	int w,to,next;
}e[MXE];
inline void add(int u,int v,int w){
	e[++ecnt]={w,v,head[u]};
	head[u]=ecnt;
}

//n = # of stations
//m = # of lines
int n,m,ex[MXN];
ll f[MXM][MXM];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,D,Q;
	cin>>C>>m>>n>>D>>Q;
	for(int i=1;i<=n;i++)
		scanf("%d",&ex[i]);
	for(int i=1;i<=m;i++)
	{
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int pos,w;
			scanf("%d%d",&pos,&w);
			add(pos,i,w);
		}
	}
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
		if(i!=j) f[i][j]=inf;
	for(int i=1;i<=n;i++)
	  for(int j=head[i];j;j=e[j].next)
		for(int k=head[i];k;k=e[k].next)
		{
			if(j==k) continue;
			int u=e[j].to,v=e[k].to;
			ll w=e[j].w+e[k].w;
			f[u][v]=min(f[u][v],w);
			f[v][u]=min(f[v][u],w);
		}
	for(int k=1;k<=m;k++)
	  for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		  if(i!=j&&j!=k&&k!=i)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(Q--)
	{
		int u,v;scanf("%d%d",&u,&v);
		ll ans = inf;
		for(int i=head[u];i;i=e[i].next)
		  for(int j=head[v];j;j=e[j].next)
			ans=min(ans,e[i].w+e[j].w+f[e[i].to][e[j].to]);
		printf("%lld\n",ans+ex[u]+ex[v]);
	}
	return 0;
}
