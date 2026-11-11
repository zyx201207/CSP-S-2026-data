#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[505][1005];
int t[505][1005];
struct stu
{
	int v;
	long long w;
};
vector<stu>g[500005];
priority_queue<stu>op;
bool operator<(stu a,stu b)
{
	return a.w>b.w;
}
long long dis[500005];
long long ans[1005][1005];
bool vis[500005];
int c,n,m,d,q;
void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	op.push({s,0});
	dis[s]=0;
	while(!op.empty())
	{
		int u=op.top().v;
		op.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(auto e:g[u])
		{
			int v=e.v;
			int w=e.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				op.push({v,dis[v]});
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		ans[s][i]=dis[i];
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	if(c<=11)
	{
		for(int i=1;i<=n;++i)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;++j)
			{
				cin>>a[i][j]>>t[i][j];
				g[a[i][j]].push_back({a[i][j]+i*m,t[i][j]});
				g[a[i][j]+i*m].push_back({a[i][j],t[i][j]});
			}
			for(int j=2;j<=k;++j)
			{
				g[a[i][j]+i*m].push_back({a[i][j-1]+i*m,0});
				g[a[i][j-1]+i*m].push_back({a[i][j]+i*m,0});
			}
		}
		for(int i=1;i<=m;++i)
		{
			dijkstra(i); 
		}
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<ans[u][v]+w[u]+w[v]<<'\n';
		}
	}
	return 0;
}
