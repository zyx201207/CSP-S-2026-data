#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,n,d;
int a[5010];
int head[5010];
struct lsqxx
{
	int to;
	int nxt;
}edge[5010*5010];
int cnt=0;
void add_edge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
int dis[5010];
int vis[5010];
void bfs1(int U,int V)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.push(U);
	dis[U]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];~i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
struct Node
{
	int u,d;
};
bool bfs2(int U,int V,int di)
{
	memset(vis,0,sizeof(vis));
	queue<Node>q;
	q.push({U,0});
	int cnn=0;
	while(!q.empty())
	{
		int u=q.front().u;
		int d=q.front().d;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];~i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(v==V&&d+1==di)
			{
				++cnn;
				if(cnn>2)
				{
					return 0;
				}
			}
			q.push({v,d+1});
		}
	}
	return cnn>=2;
}
void solve()
{
	memset(head,-1,sizeof(head));
	cnt=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int u=1;u<=n;++u)
	{
		for(int v=u-1;v>=1&&a[u]-a[v]<=d;--v)
		{
			add_edge(v,u);
			add_edge(u,v);
		}
	}
	int ans=0;
	for(int u=1;u<n;++u)
	{
		for(int v=u+1;v<=n;++v)
		{
			bfs1(u,v);
			ans+=bfs2(u,v,dis[v]);
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _;
	cin>>C>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
