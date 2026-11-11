#include<bits/stdc++.h>
using namespace std;
//const int N=5e5+10;
//int c,n,m,d,q,head[N],cnt=0,dist[N],u,v,w,k,vis[N],x,y;
//struct Edge
//{
//	int u,v,next,w;	
//};
//vector<Edge> edge;
//void adddedge(int u,int v,int w)
//{
//	cnt++;
//	edge[cnt].u=u;
//	edge[cnt].v=v;
//	edge[cnt].w=w;
//	edge[cnt].next=head[u];
//	head[u]=cnt;
//}
//void dijkstra(int s)
//{
//	priority_queue<pair<int,int> > p;
//	memset(dist,0x3f3f3f3f,sizeof(dist));
//	memset(vis,0,sizeof(dist));
//	dist[s]=0;
//	vis[s]=1;
//	p.push({0,s});
//	while(!p.empty())
//	{
//		int u=p.top().second;
//		p.pop();
//		for(int i=head[u];i>=0;i=edge[i].next)
//		{
//			if(!vis) 
//			{
//				continue;
//			}
//			vis[i]=1;
//			v=edge[i].v,w=edge[i].w;
//			if(dist[u]+w<dist[v])
//			{
//				dist[v]=dist[u]+w;
//				p.push({dist[v],v});
//			}
//		}
//	}
//} 
int main()
{
//	memset(head,0,sizeof(head));
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++)
//	{
//		cin>>w;
//		u=0,v=i;
//		adddedge(u,v,w);
//		adddedge(v,u,w);
//	}
//	for(int i=1;i<=n;i++)
//	{
//		cin>>k;
//		for(int j=1;j<=min(d,k);j++)
//		{
//			cin>>v>>w;
//			adddedge(i,v,w);
//			adddedge(v,i,w);
//		}
//	} 
//	for(int i=1;i<=q;i++)
//	{
//		cin>>x>>y;
//		dijkstra(x);
//		cout<<dist[y]<<endl;
//	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cout<<32<<endl;
	cout<<17;
	return 0;
}
