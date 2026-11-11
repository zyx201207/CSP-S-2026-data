#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct edge
{
	int v;
	long long w;
};
struct node
{
	int u;
	long long dis;
	bool operator <(const node&b)const{return dis>b.dis;}
};
vector<edge>g[505],l[500005];
long long dis[505][505],w[500005],e[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d %d",&a,&t);
			l[a].push_back({i,t});
		}
	}
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<l[i].size();j++)
		{
			for(int k=j+1;k<l[i].size();k++)e[l[i][j].v][l[i][k].v]=min(e[l[i][j].v][l[i][k].v],l[i][j].w+l[i][k].w);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(e[i][j]<=INT_MAX)
			{
				g[i].push_back({j,e[i][j]});
				g[j].push_back({i,e[i][j]});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		priority_queue<node>q;
		q.push({i,0});
		dis[i][i]=0;
		while(!q.empty())
		{
			int u=q.top().u;
			long long len=q.top().dis;
			q.pop();
			if(dis[i][u]!=len)continue;
			for(edge j:g[u])
			{
				int v=j.v;
				long long w=j.w;
				if(dis[i][v]>dis[i][u]+w)
				{
					dis[i][v]=dis[i][u]+w;
					q.push({v,dis[i][v]});
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<l[x].size();j++)for(int k=0;k<l[y].size();k++)ans=min(ans,w[x]+w[y]+dis[l[x][j].v][l[y][k].v]+l[x][j].w+l[y][k].w);
		cout<<ans<<endl;
	}
	return 0;
}
//RP++
