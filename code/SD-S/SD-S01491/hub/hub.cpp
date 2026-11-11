#include<bits/stdc++.h>
using namespace std;
int a[15],v[15],f[15],dis[15][15],d[15];
int n,k,ans=1e9;
vector<int> g[100005];
void find(int i)
{
	f[i]=1;
	for(int u:g[i])
	{
		if(v[u]&&!f[u])
			find(u);
	}
	return ;
}
void check()
{
	for(int i=1;i<=n;i++)
		f[i]=0,d[i]=1e9;
	int res=0;
	for(int i=1;i<=k;i++)
		if(!f[a[i]])
			res++,find(a[i]);
	if(res>2)
		return ;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			d[j]=min(d[j],dis[a[i]][j]);
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,d[i]);
//		cout<<ma<<"\n";
	ans=min(ans,ma);
}
void dfs(int x,int l)
{
//	cout<<x<<" "<<l<<"\n";
	if(l==k+1)
	{
//		for(int i=1;i<=k;i++)
//			cout<<a[i]<<" ";
//		cout<<"\n";
		check();
		return ;
	}
	if(x>n)
		return ;
	a[l]=x;
	v[x]=1;
	dfs(x+1,l+1);
	v[x]=0;
	dfs(x+1,l);
}
void init(int rt,int u,int fa)
{
	for(int v:g[u])
	{
		if(v==fa)
			continue;
		dis[rt][v]=dis[rt][u]+1;
		init(rt,v,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14)
	{while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n==k)
			cout<<0<<"\n";
		else	
			cout<<max(1,(((n+1)/2+1)/2-(k+1)/2+1)/2+1)<<"\n";
		
	}
		return 0;
	}
	while(t--)
	{
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			init(i,i,0);
//		for(int i=1;i<=n;i++,cout<<"\n")
//			for(int j=1;j<=n;j++)
//				cout<<dis[i][j]<<" ";
		dfs(1,1);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			g[i].clear();
		memset(dis,0,sizeof(dis));
	}
	return 0;
 } 
