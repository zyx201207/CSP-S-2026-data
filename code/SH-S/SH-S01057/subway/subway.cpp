#include<bits/stdc++.h>
using namespace std;

int c,d,Q,n,m,a[500005],dep[500005],father[500005],vis[500005],p[500005],w[500005],dis[500005];
int k;
struct edge
{
	int v,t;
};

int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	vector<edge> g[505];
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			if(x==i)
			{
				p[i]=y;continue;
			}
			g[i].push_back({x,p[i]+y});
			g[x].push_back({i,p[i]+y});
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	dis[1]=0;
	dep[1]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<=g[u].size()+1;i++)
		{
			int v=g[u][i].v,w=g[u][i].t;
			if(!vis[v]&&dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				father[v]=u;
				q.push({-dis[v],v});
				dep[v]=dep[u]+1;
			}
		}
	}
	 
	for(int i=1;i<=Q;i++)
	{
		int l,r;
		cin>>l>>r;
		int l1=l,r1=r;
		while(dep[l1]>dep[r1]) l1=father[l1];
		while(dep[l1]<dep[r1]) r1=father[r1];
		while(l1!=r1){r1=father[r1];l1=father[l1];}
		cout<<l1<<" "<<w[l]+w[r]+dis[l]+dis[r]-2*dis[l1]<<"\n";
	}
	return 0;
 } 
 
 /*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/

