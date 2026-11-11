#include<bits/stdc++.h>
using namespace std;
const int MAXN=508;
const int MAXM=2e4+8;
const long long INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
long long cost[MAXM],t[MAXN][MAXM],dis[MAXN],w[MAXN][MAXN];
bool vis[MAXN];
vector <int> sbs[MAXM];
priority_queue < pair<long long,int> > pq;
long long dijkstra(int st,int ed)
{
	if(st==ed) return 0;
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis));
	vis[st]=true,dis[st]=0;
	pq.push({-dis[st],st});
	while(!pq.empty())
	{
		auto u=pq.top().second;
		pq.pop();
		for(int v=1;v<=n;v++)
			if(u!=v&&w[u][v]!=INF)
				if(dis[v]>dis[u]+w[u][v])
				{
					dis[v]=dis[u]+w[u][v];
					if(!vis[v]) vis[v]=true,pq.push({-dis[v],v});
				}
	}
	return dis[ed];
}
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>cost[i];
	for(int i=1,len;i<=n;i++)
	{
		cin>>len;
		for(int j=1,x;j<=len;j++)
			cin>>x,sbs[x].push_back(i),cin>>t[i][x];
	}
	memset(w,INF,sizeof(w));
	for(int i=1;i<=m;i++)
		if(!sbs[i].empty())
			for(auto u:sbs[i])
				for(auto v:sbs[i])
					if(u!=v) w[u][v]=w[v][u]=min(w[u][v],t[u][i]+t[v][i]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(auto st:sbs[x])
			for(auto ed:sbs[y])
				ans=min(ans,dijkstra(st,ed)+cost[x]+t[st][x]+cost[y]+t[ed][y]);
		cout<<ans<<"\n";
	}
	return 0;
}
