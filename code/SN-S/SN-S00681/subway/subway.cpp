#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500005],dist[500005];
bool vis[500005];
vector<pair<int,int> > e[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dij(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	q.push({dist[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=1;i<=e[u].size();i++)
		{
			int v=e[u][i].first,w=e[u][i].second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			e[i].push_back({v,w});
			e[v].push_back({i,w});
		}
	}
	while(p--)
	{
		int a,b;
		cin>>a>>b;
		dij(a);
		cout<<dist[b]+w[a]+w[b]<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2



