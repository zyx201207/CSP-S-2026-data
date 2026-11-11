#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
int dep[1000005];
int f[1000005][25];
vector<int> g[1000005];
bool is[1000005],vis[1000005];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1; f[x][0]=fa;
	for(int i=1;(1<<i)<=dep[x];i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v==fa) continue;
		dfs(v,x);
	}
}
int lca(int x,int y)
{
	if(x==y) return x;
	if(dep[x]>=dep[y]) swap(x,y);
	for(int i=log2(dep[y]);i>=0;i--)
		if(dep[f[y][i]]>=dep[x]) y=f[y][i];
	if(x==y) return x;
	for(int i=log2(dep[x]);i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y)
{
	int ft=lca(x,y);
	return dep[x]+dep[y]-2*dep[ft];
}
void dfs2(int x)
{
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if((!is[v])||vis[v]) continue;
		dfs2(v);
	}
}
void check()
{
	for(int i=1;i<=n;i++) vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!is[i]) continue;
		if(!vis[i]) cnt++,dfs2(i);
		if(cnt>2) return;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(is[i]) continue;
		int mi=n+1;
		for(int j=1;j<=n;j++)
		{
			if(!is[j]) continue;
			mi=min(mi,dis(i,j));
		}
		sum=max(sum,mi);
	}
	ans=min(ans,sum);
	return;
}
void dfs1(int x,int cnt)
{
	if(cnt+(n-x+1)<k) return;
	if(cnt>k) return;
	if(x==n+1)
	{
		if(cnt==k) check();
		return;
	}
	is[x]=1;
	dfs1(x+1,cnt+1);
	is[x]=0;
	dfs1(x+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n) {cout << "0\n"; continue;}
		dfs(1,0);
		ans=n+1;
		dfs1(1,0);
		cout << ans << "\n";
	}
	return 0;
}
