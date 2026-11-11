#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,C,T;
const int N=1000005;
const int M=2000005;
int head[N],nxt[M],to[M],tot;
int a[N];
bool vis[N];
int AAA=INT_MAX;
void add_edge(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int u,int pre)
{
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(vis[v]||!a[v]) continue;
		vis[v]=1;
		dfs(v,u);
	}
}
int dist[55];
int bfs()
{
	queue<int> q;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]) q.push(i),dist[i]=0;
		else dist[i]=INT_MAX;
	}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(dist[v]<=dist[u]+1) continue;
			dist[v]=dist[u]+1;
			ans=max(ans,dist[v]);
			if(C==7&&ans>=AAA) return INT_MAX;
			q.push(v);
		}
	}
	return ans;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>C>>T;
	if(C<=3)
	{
		while(T--)
		{
			cin>>n>>k;
			for(int i=1;i<=n;i++) head[i]=0; tot=0;
			for(int i=1;i<n;i++)
			{
				int u,v; cin>>u>>v;
				add_edge(u,v); add_edge(v,u);
			}
			if(n==k)
			{
				cout<<0<<'\n';
				continue;
			}
			if(n==k+1)
			{
				cout<<1<<'\n';
				continue;
			}
			int ans=INT_MAX;
			for(int s=0;s<1<<n;s++)
			{
				if(__builtin_popcount(s)!=k) continue;
				for(int i=0;i<n;i++) a[i+1]=(s>>i)&1;
				for(int i=1;i<=n;i++) vis[i]=0;
				int blockcnt=0;
				for(int i=1;i<=n;i++)
					if(a[i]&&!vis[i])
					{
						blockcnt++;
						if(blockcnt>2) break;
						dfs(i,0);
					}
				if(blockcnt>2) continue;
				ans=min(ans,bfs());
			}
			cout<<ans<<'\n';
		}
	}
	if(C==7)
	{
		while(T--)
		{
			cin>>n>>k;
			for(int i=1;i<=n;i++) head[i]=0; tot=0;
			for(int i=1;i<n;i++)
			{
				int u,v; cin>>u>>v;
				add_edge(u,v); add_edge(v,u);
			}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
				{
					a[i]=a[j]=1;
					AAA=min(AAA,bfs());
					a[i]=a[j]=0;
				}
			cout<<AAA<<'\n';
		}
	}
	return 0;
}

