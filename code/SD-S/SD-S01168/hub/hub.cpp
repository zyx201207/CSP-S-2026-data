#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
const int N=1e5+100;
int rd()
{
	int x=0,y=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')y=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*y;
}
int n,kt,fa[N][21],dep[N],vis[N];
vector<int>g[N]; 
vector<int>tmp;
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	rep(i,1,20)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:g[u])
	{
		if(v==father)continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	per(i,20,0)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	per(i,20,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs2(int u)
{
	vis[u]=2;
	for(auto v:g[u])
	{
		if(vis[v]==1)dfs2(v);
	}
}
int dis(int u,int v)
{
	return dep[u]+dep[v]-dep[lca(u,v)]*2;
}
void mian()
{
	n=rd();kt=rd();
	rep(i,1,n)g[i].clear();
	rep(i,1,n-1)
	{
		int u=rd(),v=rd();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int ans=1e9;
	for(int i=0;i<(1<<n);++i)
	{
		tmp.clear();
		rep(j,1,n)vis[j]=0;
		for(int j=1;j<=n;++j)if((i>>j-1)&1)tmp.push_back(j),vis[j]=1;
		if(tmp.size()!=kt)continue;
		int cnt=0;
		rep(j,1,n)if(vis[j]==1)dfs2(j),++cnt;
		int res=0;
		if(cnt<=2)
		{
			rep(j,1,n)
			{
				if(vis[j]==2)continue;
				int d=1e9;
				rep(k,1,kt)d=min(d,dis(tmp[k-1],j));
				res=max(res,d);	
			}
			ans=min(ans,res); 
		}
	} 
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=rd(),T=rd();
	while(T--)mian();
	
	return 0;
}

