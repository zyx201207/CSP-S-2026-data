#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507,M=5e5+7,Q=1e5+7,inf=1e18,Mp=5e5;
int c,n,m,d,q;
struct query{
	int u,v,id;
}qu[Q];
int ans[Q];
int w[N];//from exit to the hall
int to[M];//this line has how many stations
vector<pair<int,int>>g[M+N];//the graph
int dis[M+N];
bool vis[M+N];
void dijkstra(int s)
{
	for(int i=1;i<=m;i++)dis[i]=inf,vis[i]=0;
	for(int i=M;i<M+N;i++)dis[i]=inf,vis[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});
	dis[s]=0,vis[s]=0;
	while(!pq.empty())
	{
		auto [d,v]=pq.top();pq.pop();
		if(vis[v])continue;
		vis[v]=1;
		for(auto [nxt,dst]:g[v])
		{
			if(dis[nxt]>dis[v]+dst)
			{
				dis[nxt]=dis[v]+dst;
				pq.push({dis[nxt],nxt});
			}
		}
	}
}
bool cmp(query x,query y)
{
	return x.u<y.u;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)//input
	{
		cin>>to[i];
		for(int j=1;j<=to[i];j++)
		{
			int st,tm;
			cin>>st>>tm;
			g[M+i].push_back({st,tm});
			g[st].push_back({M+i,tm});
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qu[i].u>>qu[i].v;
		qu[i].id=i;
		if(qu[i].u>qu[i].v)swap(qu[i].u,qu[i].v);
	}
	sort(qu+1,qu+1+q,cmp);
	int st=0;
	for(int i=1;i<=q;i++)
	{
		if(st!=qu[i].u)
		{
			st=qu[i].u;
			dijkstra(st);
		}
		ans[qu[i].id]=dis[qu[i].v]+w[qu[i].v]+w[qu[i].u];
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}