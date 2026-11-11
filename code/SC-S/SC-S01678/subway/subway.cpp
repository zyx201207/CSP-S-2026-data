#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=510;
int n,m,d,T,w[N];
vector<pair<int,int>>G[N];

int dis[M][M];

void init()
{
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,t;cin>>u>>t;
			G[u].push_back({i,t});
		}
	}
	
	memset(dis,0x3f,sizeof dis);
	
	for(int i=1;i<=n;i++)dis[i][i]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int x=0;x<(int)G[i].size();x++)
		{
			for(int y=x+1;y<(int)G[i].size();y++)
			{
				int u=G[i][x].first;
				int v=G[i][y].first;
				dis[u][v]=dis[v][u]=min(dis[u][v],G[i][x].second+G[i][y].second);
			}		
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);
			}
		}
	}
}

void solve()
{
	int x,y;cin>>x>>y;
	int ans=1e18;
	for(auto u:G[x])
	{
		for(auto v:G[y])
		{
//			assert(dis[u.first][v.first]==dis[v.first][u.first]);
			ans=min(ans,dis[u.first][v.first]+u.second+v.second);
		}
	}
	cout<<ans+w[x]+w[y]<<"\n";
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C;cin>>C;
	cin>>n>>m>>d>>T;
	init();
	while(T--)solve();
	return 0;
}
