//SN-S00402 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,T; 
int n,k;
vector<int>g[15];
bool cho[15];
bool vis[15];
int dep[15];
int fa[15][5];
void check(int u,int p)
{
	vis[u]=1;
	for(int v:g[u]) if(v!=p && cho[v]) check(v,u);
}
void dfs(int u,int p)
{
	dep[u]=dep[p]+1;
	fa[u][0]=p;
	for(int j=3;j;j--) fa[u][j]=fa[fa[u][j-1]][j-1];
	for(int v:g[u]) if(v!=p) dfs(v,u); 
}
int Lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=3;j>=0;j--) if(dep[fa[u][j]]>=dep[v]) u=fa[u][j];
	if(u==v) return u;
	for(int j=3;j>=0;j--) if(fa[u][j]!=fa[v][j]) u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
int Dis(int u,int v){return dep[u]+dep[v]-2*dep[Lca(u,v)];}
int ans=INF;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v;
		g[u].pb(v); g[v].pb(u);
	}
	for(int sta=0;sta<(1<<n);sta++) 
	{
		int num=0,tot=0;
		for(int i=1;i<=n;i++) cho[i]=vis[i]=0;
		for(int i=0;i<n;i++) if(sta&(1<<i)) num++,cho[i+1]=1;
		if(num!=k) continue;
		for(int i=1;i<=n;i++) if(cho[i])
			if(!vis[i]) check(i,0),tot++;
		if(tot>2) continue;
		dfs(1,0);
		int maxn=0;
		for(int i=1;i<=n;i++) 
		{
			int dis=INF;
			for(int j=1;j<=n;j++) if(cho[j]) dis=min(dis,Dis(i,j));
			maxn=max(maxn,dis);
		}
		ans=min(ans,maxn);
	}
	cout<<ans<<"\n";
	ans=INF;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
