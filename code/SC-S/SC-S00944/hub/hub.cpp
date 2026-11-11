#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,f[1000005][20],dep[1000005],vis[1000005],in[1000005],dist[1005][1005];
vector<int> g[1000005];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=20;i>=0;i--)
	{
		if(dep[f[a][i]]>=dep[b]) a=f[a][i];
	}
	if(a==b) return a;
	for(int i=20;i>=0;i--)
	{
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}
int dis(int a,int b)
{
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
void check(int u)
{
	in[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(vis[v]==1&&in[v]==0) check(v);
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		memset(f,0,sizeof(f));
		memset(dep,0,sizeof(dep));
        memset(dist,0,sizeof(dist));
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		if(c<=3)
		{
			int ans=1e9;
			for(int mask=0;mask<(1<<n);mask++)
			{
				memset(vis,0,sizeof(vis));
				memset(in,0,sizeof(in));
				vector<int> dot;
				for(int i=1;i<=n;i++)
				{
					if(mask&(1<<(i-1))) vis[i]=1,dot.push_back(i);
				}
				if(dot.size()!=k) continue;
				int cnt=0;
				for(int i=0;i<dot.size();i++)
				{
					if(in[dot[i]]==0) check(dot[i]),cnt++;
				}
				if(cnt>2) continue;
				int mx=-1e9;
				for(int i=1;i<=n;i++)
				{
					int mn=1e9;
					if(vis[i]) mn=0;
					else
					{
						for(int j=0;j<dot.size();j++)
						{
							int u=dot[j];
							mn=min(mn,dis(i,u));
						}
					}
					mx=max(mx,mn);
				}
				ans=min(ans,mx);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c==7)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j) continue;
					dist[i][j]=dis(i,j);
				}
			}
			int ans=1e9;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int mx=0;
					for(int k=1;k<=n;k++)
					{
						if(k==i||k==j) continue;
						mx=max(mx,min(dist[i][k],dist[k][j]));
					}
					ans=min(ans,mx);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
/*
exp:20pts
writer:1419936
*/