#include <bits/stdc++.h>
using namespace std;
vector<int>G[200000];
int dep[200000];
int fa[200000][32];
void dfs(int x,int pa)
{
	dep[x]=dep[pa]+1;
	fa[x][0]=pa;
	for(int i=1;i<=30;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto y:G[x])
	{
		if(y==pa)continue;
		fa[y][0]=x;
		dfs(y,x);
	}
}
int lca(int u,int v)
{
	int cnt=0;
	if(dep[u]>dep[v])swap(u,v);
	for(int i=30;i>=0;i--)
	{
		if(dep[fa[v][i]]>=dep[u])
		{
			v=fa[v][i];
		}
	}
	if(u==v) return v;
	for(int i=30;i>=0;i--)
	{
		if(fa[v][i]!=fa[u][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,K;
		cin>>n>>K;
		for(int j=1;j<n;j++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		int maxn=1e9;
		if(K==2)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					int maxn1=0;
					for(int l=1;l<=n;l++)
					{
						maxn1=max(maxn1,min(dep[j]+dep[l]-2*dep[lca(j,l)],dep[k]+dep[l]-2*dep[lca(k,l)]));
					}
					maxn=min(maxn,maxn1);
				}
			}
			cout<<maxn<<endl;
		}
		else if(K==3)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					for(int o=1;o<=n;o++)
					{
						int maxn1=0;
						for(int l=1;l<=n;l++)
						{
							maxn1=max(maxn1,min({dep[j]+dep[l]-2*dep[lca(j,l)],dep[k]+dep[l]-2*dep[lca(k,l)],dep[o]+dep[l]-2*dep[lca(o,l)]}));
						}
						maxn=min(maxn,maxn1);
					}
				}
			}
			cout<<maxn<<endl;
		}
	}
}
