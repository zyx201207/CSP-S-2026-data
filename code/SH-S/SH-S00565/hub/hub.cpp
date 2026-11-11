#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v;
}edges[1000010];
int c,t,n,k,ans,fa[1000010],vis[1000010],a[15][15],dep[1000010];
vector<int> adj[1000010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int idx,int sum)
{
	if(sum>k||sum+n-idx+1<k) return;
	if(idx==n+1)
	{
		int cnt=0,res=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<n;i++)
			if(vis[edges[i].u]&&vis[edges[i].v])
				fa[find(edges[i].u)]=find(edges[i].v);
		for(int i=1;i<=n;i++)
			if(vis[i]&&find(i)==i)
				cnt++;
		if(cnt>2) return;
		for(int i=1;i<=n;i++)
		{
			int minn=1e9;
			for(int j=1;j<=n;j++)
				if(vis[j])
					minn=min(minn,a[i][j]);
			res=max(res,minn);
		}
		return ans=min(ans,res),void();
	}
	vis[idx]=1,dfs(idx+1,sum+1),vis[idx]=0,dfs(idx+1,sum);
}
void solve(int u)
{
	for(int v:adj[u])
		if(dep[v]>dep[u]+1)
			dep[v]=dep[u]+1,solve(v);
}
int main()//20pts
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k,ans=1e9;
		for(int i=1;i<n;i++) cin>>edges[i].u>>edges[i].v,adj[edges[i].u].push_back(edges[i].v),adj[edges[i].v].push_back(edges[i].u);
		if(n<=10)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j)
						a[i][j]=1e9;
			for(int i=1;i<n;i++) a[edges[i].u][edges[i].v]=a[edges[i].v][edges[i].u]=1;
			for(int p=1;p<=n;p++)
				for(int i=1;i<=n;i++)
						for(int j=1;j<=n;j++)
							a[i][j]=min(a[i][j],a[i][p]+a[p][j]);
			dfs(1,0),cout<<ans<<'\n';
		}
		else if(k==2)
		{
			for(int i=1,sum;i<n;i++)
				for(int j=i+1;j<=n;j++)
				{
					dep[i]=dep[j]=sum=0,solve(i),solve(j);
					for(int p=1;p<=n;p++) sum=max(sum,dep[i]);
					ans=min(ans,sum);
				}
			cout<<ans<<'\n';
		}
		else cout<<"0\n";
	}
}
/*

*/
