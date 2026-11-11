#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node
{
	int v;
	long long t;
};
struct edge
{
	int u;
	long long dis;
	operator <(const edge&o)const{
		return dis>o.dis;
	}
};
int c,n,m,d,q;
bool vis[510];
long long w[N],dis[N];
vector<node>a[N];
long long dfs(int s,int e)
{
	priority_queue<edge>q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[s]=0;
	q.push({s,0});
	while(q.size())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<a[u].size();i++)
		{
			int v,cost;
			v=a[u][i].v;
			cost=a[u][i].t;
			if(dis[v]>dis[u]+cost)
			{
				dis[v]=dis[u]+cost;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[e];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int k,u,v,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>u>>v;
			a[m+i].push_back({u,v});
			a[u].push_back({m+i,v});
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<w[x]+dfs(x,y)+w[y]<<'\n';
	}
	return 0;
}
