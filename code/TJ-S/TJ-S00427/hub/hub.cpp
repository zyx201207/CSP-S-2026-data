#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,k,ans,sum=1e9;
vector<int> G[15];
bool used[15];
int fa[15];
int fat[15][15];
int dep[15];
int clt;
int LCA[15][15];
int Find(int x)
{
	if(fa[x]==x) return fa[x];
	return fa[x]=Find(fa[x]);
}
bool Union(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx==fy) return false;
	fa[fx]=fy;
	return true;
}
void dfs0(int u,int f)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==f) continue;
		dep[v]=dep[u]+1;
		fat[v][0]=u;
		dfs0(v,u);
	}
}
void csh()
{
	for(int j=1;j<=10;j++)
	{
		for(int i=1;i<=n;i++)
		{
			fat[i][j]=fat[fat[i][j-1]][j-1];
		}
	}
}
int lca(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=10;i>=0;i--)
	{
		if(dep[fat[a][i]]>=dep[b]) a=fat[a][i];
	}
	if(a==b) return a;
	for(int i=10;i>=0;i--)
	{
		if(fat[a][i]!=fat[b][i]) a=fat[a][i],b=fat[b][i];
	}
	return fat[a][0];
}
void dfs(int u,int f)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==f) continue;
		if(used[v]&&used[u])
		{
			if(Union(u,v)) clt--;
		}
		dfs(v,u);
	}
}
void cx(int now,int cnt)
{
	if(cnt==k)
	{
		memset(fa,0,sizeof(fa));
		for(int i=1;i<=n;i++)
		{
			if(used[i]) fa[i]=i;
		}
		clt=k;
		dfs(1,0);
		if(clt<=2)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				if(!used[i])
				{
					int dis=1e9;
					for(int j=1;j<=n;j++)
					{
						if(used[j]) dis=min(dis,dep[i]+dep[j]-2*dep[LCA[i][j]]); 
					}
					ans=max(ans,dis);
				}
			}
			sum=min(sum,ans);
		}
		return;
	}
	if(now==n+1) return;
	used[now]=1;
	cx(now+1,cnt+1);
	used[now]=0;
	if(n-now+cnt>=k) cx(now+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs0(1,0);
		csh();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				LCA[i][j]=LCA[j][i]=lca(i,j);
			}
		}
		cx(1,0);
		cout<<sum<<endl;
		for(int i=1;i<=n;i++) G[i].clear();
		memset(used,0,sizeof(used));
		memset(fa,0,sizeof(fa));
		memset(fat,0,sizeof(fat));
		memset(dep,0,sizeof(dep));
		memset(LCA,0,sizeof(LCA));
		ans=0;
		sum=1e9;
	}
	return 0;
}

