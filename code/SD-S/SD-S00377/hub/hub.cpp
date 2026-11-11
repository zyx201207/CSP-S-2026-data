#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10+5,L=20,inf=0x3f3f3f3f3f3f3f3f,eps=1e-8;
int a[N][N],f[N][L+5],dist[N][N],dep[N];int n,k;
vector<int> e[N];
int fa[N],ans;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void dfs(int u,int fat)
{
	f[u][0]=fat;dep[u]=dep[fat]+1;
	for(int i=1;i<=L;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:e[u])
	{
		if(v==fat) continue;
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=L;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=L;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][y];y=f[y][i];
		}
	}
	return f[x][0];
}
void dfs_ans(int u,int cnt,int mask)
{
	if(u==n+1)
	{
		if(cnt!=k) return;
		vector<int> vec;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			if((mask>>(i-1)&1)==1) vec.push_back(i);
		}
		for(auto i:vec)
		{
			for(auto j:vec)
			{
				if(a[i][j]) merge(i,j);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if((mask>>(i-1)&1)==1&&fa[i]==i) cnt++;
		} 
		if(cnt>2) return ;
//		cout<<mask<<'\n';
		int linans=-inf;
		for(int i=1;i<=n;i++)
		{
			if((mask>>(i-1)&1)==1) continue;
			int lans=inf;
//			cout<<"i "<<i<<'\n';
			for(int j=1;j<=n;j++)
			{
				if((mask>>(j-1)&1)!=1) continue;
				lans=min(lans,dist[i][j]);
//				cout<<"j "<<j<<'\n';
			}
//			cout<<"lans "<<lans<<'\n';
			linans=max(linans,lans);
		}
		ans=min(ans,linans);
		return ;
	}
	if(cnt==k) dfs_ans(u+1,cnt,mask);
	else
	{
		dfs_ans(u+1,cnt,mask);
		dfs_ans(u+1,cnt+1,mask|(1<<(u-1)));
	}
}
void solve()
{
	cin>>n>>k;
	ans=inf;
	memset(a,0,sizeof(a));
	for(int i=1;i<n;i++) 
	{
		int u,v;cin>>u>>v;
		a[u][v]++;a[v][u]++;
		e[u].push_back(v);e[v].push_back(u); 
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++) cout<<dep[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j]=dep[i]+dep[j]-2*dep[lca(i,j)];
		}
	}
	dfs_ans(1,0,0);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) e[i].clear(); 
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

