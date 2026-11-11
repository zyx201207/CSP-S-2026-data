#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define T 20 
int a[N],fa[N],f[N][T],d[N];
vector <int> g[N];
void dfs(int u,int p)
{
	f[u][0]=p;
	d[u]=d[p]+1;
	for(int i=1;i<=18;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u])
	{
		if(v==p) continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(d[u]<=d[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[f[u][i]]>=d[v])
			u=f[u][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}
int dis(int u,int v)
{
	return d[u]+d[v]-2*d[lca(u,v)];
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u!=v) fa[v]=u;
}
void tn(int n)
{
	for(int i=1;i<=n;i++) a[i]=fa[i]=d[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=18;j++)
			f[i][j]=0;
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cc,tt;
	cin>>cc>>tt;
	while(tt--)
	{
		int n,t,ans=1e12;
		cin>>n>>t;
		tn(n);
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int i=0;i<=(1<<n)-1;i++)
		{
			int cnt=0,maxn=0;
			for(int j=1;j<=n;j++) fa[j]=j;
			for(int j=1;j<=n;j++) a[j]=((i>>(j-1))&1);
			for(int j=1;j<=n;j++)
			{
				if(a[j]==0) continue;
				cnt++;
				for(auto k:g[j])
					if(a[k]==1)
						merge(j,k);
			}
			if(cnt!=t) continue;
			cnt=0;
			for(int j=1;j<=n;j++)
				if(find(j)==j&&a[j]==1)
					cnt++;
			if(cnt>2) continue;
			for(int j=1;j<=n;j++)
			{
				int minn=1e12;
				for(int k=1;k<=n;k++)
					if(a[k]==1)
						minn=min(minn,dis(j,k));
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);
		}
		cout<<ans<<endl;
	}
	return 0;
}

