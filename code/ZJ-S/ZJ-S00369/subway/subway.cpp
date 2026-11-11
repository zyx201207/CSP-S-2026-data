#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+505;
ll n,m,c,d,q,cnt=0;
ll ww[N];
ll head[N],to[N*2],nxt[N*2],val[N*2],tot=0;
int fa[N],f[N][22],dep[N];
ll dis[N];
struct po
{
	ll u,v,w;
	bool operator <(const po y)
	{
		return w<y.w;
	}
}ne[N];
inline void addedge(int u,int v,int w)
{
	ne[++cnt]={u,v,w};
}
inline void add(int u,int v,int w)
{
	to[++tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
	to[++tot]=u;
	val[tot]=w;
	nxt[tot]=head[v];
	head[v]=tot;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kuscaer()
{
	sort(ne+1,ne+cnt+1);
	int num=1;
	for(int i=1;i<=cnt;i++)
	{
		int u=find(ne[i].u),v=find(ne[i].v);
		if(u==v) continue;
		fa[u]=v;
		add(ne[i].u,ne[i].v,ne[i].w);
		num++;
		if(num==n+m) break;
	}
}
void dfs(int u,int father)
{
	f[u][0]=father;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==father) continue;
		dis[v]=dis[u]+val[i];
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void init()
{
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n+m;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}	
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int j=20;j>=0;j--)
	{
		if(f[x][j]!=0&&dep[f[x][j]]>=dep[y]) x=f[x][j];
	}
	if(x==y) return x;
	for(int j=20;j>=0;j--)
	{
		if(f[x][j]!=0&&f[y][j]!=0&&f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	}
	x=f[x][0];
	return x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n+m;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&ww[i]);
	}
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1,x,y;j<=k;j++)
		{
			scanf("%d%d",&x,&y);
			addedge(m+i,x,y);
		}
	}
	kuscaer();
	dfs(1,0);
	init();
	for(int i=1,x,y;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",ww[x]+ww[y]+dis[x]+dis[y]-2*dis[lca(x,y)]);
	}
	return 0;
}