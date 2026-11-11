#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+510;
int c,n,m,d,T;
long long dis[N][N],a[M],e[N][N];
bool vis[N][N];
struct edge{
	int v;
	long long w;
	bool friend operator <(edge x,edge y){return x.w>y.w;}
};
vector<edge> g[M],vc[N];
priority_queue<edge> q;
void bfs(int st)
{
	//cout<<st<<"\n";
	q.push({st,0});
	dis[st][st]=0;
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		//cout<<u<<"\n";
		if(vis[st][u]) continue;
		vis[st][u]=1;
		for(edge x:vc[u])
		{
			int v=x.v;
			long long w=x.w;
			if(!vis[st][v]&&dis[st][v]>dis[st][u]+w)
			{
				dis[st][v]=dis[st][u]+w;
				q.push({v,dis[st][v]});
			}
		}
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k,x;
		long long t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>t;
			g[i].push_back({n+x,t});
			g[n+x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	memset(e,0x3f,sizeof(e));
	for(int u=1+n;u<=m+n;u++)
	{
		for(edge i:g[u])
		{
			for(edge j:g[u])
			{
				if(i.v==j.v) continue;
				e[i.v][j.v]=e[j.v][i.v]=min(e[i.v][j.v],i.w+j.w);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&e[i][j]<=1e18)
			{
				vc[i].push_back({j,e[i][j]});
				vc[j].push_back({i,e[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	while(T--)
	{
		int u,v;
		long long ans=1e18;
		cin>>u>>v;
		for(edge i:g[u+n])
		{
			for(edge j:g[v+n])
			{
				//cout<<u<<" "<<i.v<<" "<<j.v<<" "<<v<<"\n";
				ans=min(ans,dis[i.v][j.v]+i.w+j.w+a[u]+a[v]);
			}
		}
		cout<<ans<<"\n";
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
