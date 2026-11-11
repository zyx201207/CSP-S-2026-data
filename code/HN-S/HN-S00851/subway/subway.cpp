#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5,M=5e5+5,INF=1e18;
struct node{
	int id,w;
	bool operator<(const node &other)const
	{
		return w>other.w;
	}
}; 
struct edge{
	int x,y,id;
}e[M];
int c,n,m,d,q,tot;
int w[M],dis[N],ans[M];
bool vis[N];
vector<node> nbr[N]; 
void dijkstra(int s)
{
	for(int i=1;i<=tot;i++)
	{
		dis[i]=INF;
		vis[i]=false;
	}
	priority_queue<node> pq;
	dis[s]=0;
	pq.push(node{s,dis[s]});
	while(pq.empty()==false)
	{
		int cur=pq.top().id;
		pq.pop();
		if(vis[cur]==true)
		{
			continue;
		}
		vis[cur]=true;
		for(int i=0;i<nbr[cur].size();i++)
		{
			int nxt=nbr[cur][i].id;
			int w=nbr[cur][i].w;
			if(dis[nxt]>dis[cur]+w)
			{
				dis[nxt]=dis[cur]+w;
				pq.push(node{nxt,dis[nxt]});
			}
		}
	}
	return ;
}
bool cmp(edge x,edge y)
{
	if(x.x!=y.x)
	{
		return x.x<y.x;
	}
	return x.y<y.y;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	tot=m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			tot++;
			int id,w;
			cin>>id>>w;
			nbr[id].push_back(node{tot,w});
			nbr[tot].push_back(node{id,w});
			if(j>1)
			{
				nbr[tot].push_back(node{tot-1,0});
				nbr[tot-1].push_back(node{tot,0});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>e[i].x>>e[i].y;
		e[i].id=i;
		ans[i]=0;
	}
	sort(e+1,e+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		if(e[i].x!=e[i-1].x)
		{
			dijkstra(e[i].x);
		}
		ans[e[i].id]=dis[e[i].y]+w[e[i].x]+w[e[i].y];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<"\n";
	} 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

44·Ö±©Á¦  
*/
