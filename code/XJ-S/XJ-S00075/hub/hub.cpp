#include<bits/stdc++.h>
using namespace std;
int n,k,t[100005],vis[100005],ans=1e9;
vector<int>g[100005];
void dfs1(int u,int fa)
{
	if(t[u]==0)
	return;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa||t[v]==0||vis[v]==1)
		continue;
		dfs1(v,u);
	}
}
int dfs2(int u,int fa,int cnt)
{
	if(t[u]==1)
	return cnt;
	int minn=1e9;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa)
		continue;
		minn=min(minn,dfs2(v,u,cnt+1));
	}	
	return minn;
}
void check()
{
	int kk=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	if(!vis[i]&&t[i])
	{
		kk++;
		dfs1(i,0);
	}
	if(kk>2)
	return;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int h=dfs2(i,0,0);
		if(h>maxn) 
		maxn=h;
	}
	ans=min(ans,maxn);
}
void f(int step,int h)
{
	if(step==n+1)
	{
		if(h==k)
		check();
		return;
	}
	f(step+1,h);
	if(h==k)
	return;
	t[step]=1;
	f(step+1,h+1);
	t[step]=0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		f(1,0);
		for(int i=1;i<=n;i++)
		g[i].clear();
		cout<<ans<<"\n";
		ans=1e9;
	}
}
