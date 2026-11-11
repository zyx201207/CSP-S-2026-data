#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[1000006];
int dep[1000006],f[1000005][30];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]==fa) continue;
		f[g[x][i]][0]=x;
		dfs(g[x][i],x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<=dep[y]) swap(x,y);
	for(int i=30;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(dep[x]==dep[y]) return x;
	for(int i=30;i>=0;i--)
	{
		if(dep[f[x][i]]!=dep[f[y][i]])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int fa[1000006],vis[1000006];
int t1=-1,t2=-1;
int ans=0;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int n,k;
void dfss(int x,int sum)
{
	if(sum==k)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,vis[i]);
		}
		ans=min(ans,maxn);
		return;
	}
	if(x==n) return;
	if(t1==-1)
	{
		dfs(x+1,sum);
		t1=x;
		int tt=vis[x];
		vis[x]=0;
		dfs(x+1,sum+1);
		t1=-1;
		vis[x]=tt;
	}
	else if(t2==-1)
	{
		dfs(x+1,sum);
		t2=x;
		int tt=vis[x];
		vis[x]=0;
		dfs(x+1,sum+1);
		t2=-1;
		vis[x]=tt;
	}
	else
	{
		int tx=find(t1),ty=find(t2);
		for(int i=0;i<g[x].size();i++)
		{
			int ttt=find(g[x][i]);
			if(ttt==tx)
			{
				fa[x]=t1;
				int tt=vis[x];
				vis[x]=0;
				dfs(x+1,sum+1);
				fa[x]=x;
				vis[x]=tt;
				dfs(x+1,sum);
				break;
			}
			if(ttt==ty)
			{
				fa[x]=t2;
				int tt=vis[x];
				vis[x]=0;
				dfs(x+1,sum+1);
				fa[x]=x;
				vis[x]=tt;
				dfs(x+1,sum);
				break;
			}
		} 
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;(1<<i)<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[j][i]=f[f[j][i-1]][i-1];
			}
		}
		int max1=0,max2=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			int maxn=1e9;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				int t=lca(i,j);
				maxn=min(dep[i]-dep[t]+dep[j]-dep[t],maxn);
			}
			if(maxn>max1)
			{
				sum=max2;
				max2=max1;
				max1=maxn;
			}
			else if(maxn>max2)
			{
				sum=max2;
				max2=maxn;
			}
			else if(maxn>sum) sum=maxn;
			vis[i]=maxn;
		}
		if(k==1)
		{
			cout<<max2<<'\n';
			continue;
		}
		if(k==2)
		{
			cout<<sum<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		dfss(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
