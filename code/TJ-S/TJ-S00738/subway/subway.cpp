#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
int C,n,m,D,q;
ll w[500010];
vector<pair<int,ll>> g[600010];
vector<pair<ll,pair<int,int>>> edge;
ll dis[600010],d[510][510];
int belong[600010];
bool vis[600010];
void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	for(int i=m+1;i<=n+m;++i)
	{
		dis[i]=0;
		belong[i]=i-m;
		pq.push(mk(0,i));
	}
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<g[x].size();++i)
		{
			int y=g[x][i].first,w=g[x][i].second;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				belong[y]=belong[x];
				pq.push(mk(dis[y],y));
			}
		}
	}
}
bool ED;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,t;
			cin>>a>>t;
			g[i+m].pb(mk(a,t));
			g[a].pb(mk(i+m,t));
			edge.pb(mk(t,mk(a,i+m)));
		}
	}
	dijkstra();
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;++i)d[i][i]=0;
	for(int i=0;i<edge.size();++i)
	{
		int w=edge[i].first,x=edge[i].second.first,y=edge[i].second.second;
		if(belong[x]==belong[y])continue;
		int u=belong[x],v=belong[y];
		d[u][v]=min(d[u][v],dis[x]+dis[y]+w);
		d[v][u]=min(d[v][u],dis[x]+dis[y]+w);
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
//	for(int i=1;i<=n+m;++i)cerr<<dis[i]<<" ";
//	cerr<<"\n";
//	for(int i=1;i<=n+m;++i)cerr<<belong[i]<<" ";
//	cerr<<"\n";
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=n;++j)cerr<<d[i][j]<<" ";
//		cerr<<"\n";
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<g[x].size();++i)
		{
			for(int j=0;j<g[y].size();++j)
			{
				int u=g[x][i].first-m,v=g[y][j].first-m,w1=g[x][i].second,w2=g[y][j].second;
//				cerr<<u<<" "<<v<<" "<<d[u][v]+w1+w2<<"\n";
				ans=min(ans,d[u][v]+w1+w2);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ED-&ST)/1024.0/1024.0<<"mb\n";
	return 0;
}//15:36 100pts,还算顺利，加油，争取350 
