#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
vector<int>eg[1000005];
int vis[1000005],cnt=0,dis[1000005];
void dfs(int u,int fa)
{
	if(vis[u]&&!vis[fa]) cnt++;
	for(int v:eg[u]) 
		if(v!=fa)dfs(v,u);
}
queue<int>q;
void dfs()
{
	for(int i=1;i<=n;i++) dis[i]=1e18;
	for(int j=1;j<=n;j++) if(vis[j]) dis[j]=0,q.push(j);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:eg[u])
			if(dis[u]+1<dis[v]) 
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++) eg[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			eg[u].push_back(v);
			eg[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++)
		{
			int j=i;cnt=0;
			while(j){cnt+=(j%2);j>>=1;}
			if(cnt!=k) continue;
			cnt=0;
			for(j=1;j<=n;j++) vis[j]=0;
			for(j=1;j<=n;j++) if(i&(1<<(j-1))) vis[j]=1;
			dfs(1,0);
			if(cnt>2) continue;
			
//			cout<<"now:";
//			for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
//			cout<<"\n";
			
			dfs();
			int mx=0;
			for(j=1;j<=n;j++) mx=max(mx,dis[j]);
//			cout<<mx<<"\n";
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}
	return 0;
}