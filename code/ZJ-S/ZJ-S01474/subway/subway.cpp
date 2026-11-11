#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int c,n,m,d,q,k,a,t,x,y;
long long w[500010],dp[510][510],ans;
vector<pair<int,long long>> p[500010],g[510];
void dijkstra(int s)
{
	long long dis[510];
	bool vis[510];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	priority_queue<pair<long long,int>> pq;
	pq.emplace(0,s);
	while(!pq.empty())
	{
		auto r=pq.top();
		pq.pop();
		int u=r.second;
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto i:g[u])
			if(dis[u]+i.second<dis[i.first])
			{
				dis[i.first]=dis[u]+i.second;
				pq.emplace(dis[i.first],i.first);
			}
	}
	for(int i=1;i<=n;i++)
		dp[s][i]=dis[i];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			p[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<p[i].size();j++)
			for(int k=0;k<p[i].size();k++)
			{
				if(j==k)
					continue;
				g[p[i][j].first].push_back({p[i][k].first,p[i][j].second+p[i][k].second});
			}
	}
	for(int i=1;i<=n;i++)
		dijkstra(i);
	while(q--)
	{
		ans=INF;
		cin>>x>>y;
		for(auto i:p[x])
			for(auto j:p[y])
				ans=min(ans,dp[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}