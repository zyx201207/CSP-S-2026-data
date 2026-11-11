#include<bits/stdc++.h>
using namespace std;
#define N 1010
int c,T,n,k,tot,ans,f[N],vis[N],dep[N],head[N],ff[N][15];
struct Node{
	int to,nex;
}a[N<<1];
inline void add(int u,int v)
{
	a[++tot].to=v;
	a[tot].nex=head[u];
	head[u]=tot;
}
inline int find(int x)
{
	while(x!=f[x])
		x=f[x]=f[f[x]];
	return x;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		f=(c=='-')?-1:f,c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
void dfs1(int x,int fa)
{
	for(int i=1;i<=13;++i)
		ff[x][i]=ff[ff[x][i-1]][i-1];
	for(int i=head[x];~i;i=a[i].nex)
	{
		int y=a[i].to;
		if(y==fa) continue;
		ff[y][0]=x,dep[y]=dep[x]+1,dfs1(y,x);
	}
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=13;i>=0;--i)
		if(dep[ff[u][i]]>=dep[v])
			u=ff[u][i];
	if(u==v) return u;
	for(int i=13;i>=0;--i)
		if(ff[u][i]!=ff[v][i])
			u=ff[u][i],v=ff[v][i];
	return ff[u][0];
}
void dfs2(int x,int now)
{
	if(now>k) return ;
	if(x==n+1)
	{
		for(int i=1;i<=n;++i) f[i]=i;
		int cnt=0,res=-1;
		for(int i=2;i<=n;++i)
			if(vis[i]&&vis[ff[i][0]])
				f[i]=ff[i][0];
		for(int i=1;i<=n;++i)
			if(vis[i]&&find(i)==i) ++cnt;
		if(cnt!=2) return ;
		for(int i=1;i<=n;++i)
		{
			int dis=1e9;
			for(int j=1;j<=n;++j)
			{
				if(!vis[j]) continue;
				dis=min(dis,dep[i]+dep[j]-(dep[lca(i,j)]<<1));
			}
			res=max(res,dis);
		}
		ans=min(ans,res);
		return ;
	}
	dfs2(x+1,now);
	vis[x]=1,dfs2(x+1,now+1),vis[x]=0;
}
inline void solve()
{
	n=read(),k=read(),tot=0,ans=1e9;
	for(int i=1;i<=n;++i) head[i]=-1;
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0),dfs2(1,0);
	memset(ff,0,sizeof(ff));
	memset(dep,0,sizeof(dep));
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--)
		solve();
	return 0;
}
/*
0 2
3 1
1 2
2 3
*/
