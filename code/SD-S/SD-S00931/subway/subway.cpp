#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q,w[500005],k[500005];
vector<pii > G[600005];
struct node
{
	int x,w;
	node(int X=0,int W=0)
	{
		x=X;
		w=W;
	}
	bool operator < (const node &k) const
	{
		return w>k.w;
	}
};
bool vis[500005];
priority_queue<node> qu; 
int dis[1005][1005];
int dis2[500005];
void dijkstra(int dis[],int strt)
{
	memset(vis,0,sizeof(vis));
	dis[strt]=0;
	qu.push(node(strt,0));
	while(!qu.empty())
	{
		node nd=qu.top();
		qu.pop();
		int u=nd.x,d=nd.w;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(pii i:G[u])
		{
			int v=i.first,w=i.second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				qu.push(node(v,dis[v]));
			}
		}
	}
}
void BFS(int dis[],int strt)
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(strt);
	dis[strt]=0;
	vis[strt]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(pii i:G[u])
		{
			int v=i.first;
			dis[v]=min(dis[v],dis[u]+1);
			if(!vis[v])
			{
				q.push(v);
				vis[v]=1;
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	bool use01bfs=0,tbfs=1; 
	if(c>=12&&c<=15)
	{
		use01bfs=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			if(use01bfs)
			{
				tbfs=t;
				G[m+i].push_back(make_pair(a,1));
				G[a].push_back(make_pair(m+i,1));
			}
			else
			{
				G[m+i].push_back(make_pair(a,t));
				G[a].push_back(make_pair(m+i,t));
			}
			
		}
	}
	if(use01bfs)
	{
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;i++)
		{
			BFS(dis[i],i);
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]*tbfs+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	/*
	for(int i=1;i<=m+n;i++)
	{
		cout<<i<<" ";
		for(pii j:G[i])
		{
			cout<<"["<<j.first<<","<<j.second<<"]"<<" "; 
		}
		cout<<"\n";
	}
	*/
	if(q<=200)
	{
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			memset(dis2,0x3f,sizeof(dis2));
			dijkstra(dis2,x);
			/*
			for(int i=1;i<=m;i++)
			{
				cout<<dis2[i]<<" ";
			}
			cout<<"\n";
			*/
			cout<<w[x]+dis2[y]+w[y]<<"\n";
		}
	}
	else if(q>=2000&&m<=2000)
	{
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;i++)
		{
			dijkstra(dis[i],i);
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<"\n";
		}
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

*/
