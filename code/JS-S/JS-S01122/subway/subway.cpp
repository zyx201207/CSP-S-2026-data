#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,q;
int siz[555];
int w[555555];
vector<int>a[555];
vector<int>t[555];
int dis[555][555];
vector<pair<int,int>>to[555555];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>siz[i];
		// a[i].resize(k[i]+3);
		// t[i].resize(k[i]+3);
		for (int j=1;j<=siz[i];j++)
		{
			int x,y;
			cin>>x>>y;
			to[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<to[i].size();j++)
		{
			for (int k=j+1;k<to[i].size();k++)
			{
				int u=to[i][j].first,v=to[i][k].first;
				dis[u][v]=min(dis[u][v],to[i][j].second+to[i][k].second);
				dis[v][u]=min(dis[v][u],to[i][j].second+to[i][k].second);
			}
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for (int i=0;i<to[u].size();i++)
		{
			for (int j=0;j<to[v].size();j++)
			{
				int x=to[u][i].first,y=to[v][j].first;
				ans=min(ans,dis[x][y]+to[u][i].second+to[v][j].second);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}