#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
#define M 510
int a[N],d[M][M];
vector <pair<int,int>> g[N];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cc,n,m,dd,tt;
	cin>>cc>>n>>m>>dd>>tt;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=1e15;
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int t=g[i].size();
		for(int j=0;j<=t-1;j++)
		{
			for(int k=j+1;k<=t-1;k++)
			{
				int u=g[i][j].first,v=g[i][k].first,w=g[i][j].second+g[i][k].second;
				d[u][v]=min(d[u][v],w);
				d[v][u]=min(d[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(tt--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e15;
		int su=g[x].size(),sv=g[y].size(); 
		for(int i=0;i<=su-1;i++)
		{
			for(int j=0;j<=sv-1;j++)
			{
				int u=g[x][i].first,v=g[y][j].first,w=g[x][i].second+g[y][j].second;
				ans=min(ans,d[u][v]+w);
			}
		}
		ans+=(a[x]+a[y]);
		cout<<ans<<'\n';
	}
	return 0;
}

