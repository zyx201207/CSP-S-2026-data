#include<bits/stdc++.h>
using namespace std;
int n,m,d,q;
const int maxn=2010;
long long a[40010];
long long dis[maxn][maxn];
long long Dis[40010];
vector<pair<long long,int>>g[40010];
int idx;
inline void dijkstra(int s)
{
	dis[s][s]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		int u=pq.top().second;
		long long d=pq.top().first;
		pq.pop();
		if(d>dis[s][u])
			continue;
		for (auto V:g[u])
		{
			int v=V.second;
			long long w=V.first;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				pq.push({dis[s][v],v});
			}
		}
	}
}
inline void Dijkstra(int s)
{
	for (int i=1;i<=idx;i++)
		Dis[i]=1e18;
	Dis[s]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		int u=pq.top().second;
		long long d=pq.top().first;
		pq.pop();
		if(d>Dis[u])
			continue;
		for (auto V:g[u])
		{
			int v=V.second;
			long long w=V.first;
			if(Dis[u]+w<Dis[v])
			{
				Dis[v]=Dis[u]+w;
				pq.push({Dis[v],v});
			}
		}
	}
}
int k;
int u,v;
long long w;
inline void solve1()
{
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++)
		dijkstra(i);
	while(q--)
	{
		cin>>u>>v;
		cout<<dis[u][v]+a[u]+a[v]<<'\n';
	}
}
inline void solve2()
{
	while(q--)
	{
		cin>>u>>v;
		Dijkstra(u);
		cout<<Dis[v]+a[u]+a[v]<<'\n';
	}
}
int tstid;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>tstid>>m>>n>>d>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	idx=n;
	while(m--)
	{
		cin>>k;
		for (int i=1;i<=k;i++)
		{
			cin>>u>>w;
			idx++;
			g[u].push_back({w,idx});
			g[idx].push_back({w,u});
			if(i==1)
				continue;
			g[idx-1].push_back({0,idx});
			g[idx].push_back({0,idx-1});
		}
	}
	if(tstid<=11)
		solve1();
	else
		solve2();
}
