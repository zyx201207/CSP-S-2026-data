#include<bits/stdc++.h>
#define X 10000005
#define N 500005
#define D 20
using namespace std;
//T2分层图最短路32~40???RE???MLE???TLE???
/*
本题代码做如下限制：
1.地铁口：第一个场所
2.站厅：第二个场所
3.站台：按读入顺序依次填充场所编号
*/
struct Edge
{
	int v,w;
};
int id(int i,int p)//i:站点编号 p:该站点的第p个场所
{
	return i*(D+2)+p;//场所最多数量：d个线路的站台外加上一个站厅一个地铁口一共是22个 
}
vector<Edge>edge[X];
int c,n,m,d,q,v,k,al,tl,a,t,x,y,nowp[N];//nowp:当前地铁站p有几个场所(计数) 

int dis[N];
bool vis[N];
struct Path
{
	int u,d;
	bool operator<(const Path&b)const
	{
		return b.d<d;
	}
};
void dijkstra(int st)
{
	priority_queue<Path>pq;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	pq.push({st,0});
	while(!pq.empty())
	{
		int u=pq.top().u,d=pq.top().d;
		pq.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=true;
		for(Edge e:edge[u])
		{
			int v=e.v,w=e.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)//站厅<->地铁口 
	{
		cin>>v;
		edge[id(i,1)].push_back({id(i,2),v});
		edge[id(i,2)].push_back({id(i,1),v});
		nowp[i]=2; 
	}
	for(int i=1;i<=n;i++)//站厅<->站台&&地铁线 
	{
		cin>>k>>al>>tl;
		edge[id(al,++nowp[al])].push_back({id(al,2),tl});
		edge[id(al,2)].push_back({id(al,nowp[al]),tl});
		for(int j=2;j<=k;j++)
		{
			cin>>a>>t;
			edge[id(a,++nowp[a])].push_back({id(a,2),t});
			edge[id(a,2)].push_back({id(a,nowp[a]),t});
			edge[id(al,nowp[al])].push_back({id(a,nowp[a]),0});
			edge[id(a,nowp[a])].push_back({id(al,nowp[al]),0});
		}
	}
	while(q--)
	{
		cin>>x>>y;
		dijkstra(id(x,1));
		cout<<dis[id(y,1)]<<'\n';
	}
	return 0;
}
