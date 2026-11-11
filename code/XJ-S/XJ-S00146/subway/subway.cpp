#include<bits/stdc++.h>
using namespace std;
const int M=500005;
using pii=pair<int,int>;
int c,n,m,d,q;
long long w[M];
vector<pii> g[M];
int dist[M];
priority_queue<pii,vector<pii>,greater<pii>> q;
bool vis[M];
void dijkstra(int s)
{
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[s]=0;
	q.push({0,s});
	while(q.size())
	{
		int t=q.top().second;
		if(vis[t]) continue;
		vis[t]=1;
		for(auto [j,w]:g[t])
		{
			if(dist[t]+w<dist[j])
			{
				dist[j]=dist[t]+w;
				q.push({dist[j],j});
			}
		}
	}
}
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			g[a].push_back({i,t});
			g[i].push_back({a,t});
		}
	}
	for(int p=1;p<=q;p++)
	{
		int x,y,total=0;
		cin>>x>>y;
		dijkstra(x);
		total=w[x]+w[y]+dist[y];
		cout<<total<<endl;
	}
}
