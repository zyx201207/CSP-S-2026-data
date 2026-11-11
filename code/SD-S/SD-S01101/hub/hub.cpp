#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
int c,t,fa[5005][25],dep[5005],dp[4005][4005],siz[4005],n,k;
vector<int>vec[5005];
void dfs(int p,int fat)
{
	fa[p][0]=fat,dep[p]=dep[fat]+1,siz[p]=1;
	for(auto it:vec[p])
	{
		if(it==fat) continue;
		dfs(it,p);	
		siz[p]+=siz[it];
	}	
} 
void init()
{
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];	
	} 
	if(u==v) return u;
	for(int i=20;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i]; 
	}
	return fa[u][0];
}
int solve(int u,int v)
{
	int lc=lca(u,v);
	return dep[u]+dep[v]-2*dep[lc]; 
}
void dfs1(int p,int fat)
{
	for(auto it:vec[p])
	{
		if(it==fat) continue;
		dfs1(it,p);
		int now=siz[p]-siz[it];
		for(int i=0;i<=min(now,k);i++)
		{
			for(int j=0;j<=min(siz[it],k);j++) 
			{
				
			}
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			vec[u].push_back(v),vec[v].push_back(u);
		}
		dfs(1,0);init();dfs1(1,0);
		for(int i=0;i<=k;i++)
		{
			int nxt=k-i;
			
		}
	}
	return 0;
}
