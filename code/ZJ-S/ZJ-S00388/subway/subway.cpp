#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	long long w;
};
int c,n,m,d,q;
long long a[500005];
vector<edge> g[600005];
long long dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		int cnts,nw=m+i; cin >> cnts;
		for(int j=1;j<=cnts;j++)
		{
			int x; long long t;
			cin >> x >> t;
			g[x].push_back({nw,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=9e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int v=g[i][j].v-m;
			long long w1=g[i][j].w;
			for(int k=j+1;k<g[i].size();k++)
			{
				int v1=g[i][k].v-m;
				long long w2=g[i][k].w;
				dis[v][v1]=dis[v1][v]=min(dis[v][v1],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]==9e18||dis[k][j]==9e18)
					continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	while(q--)
	{
		int x,y; cin >> x >> y;
		long long ans=9e18;
		for(int j=0;j<g[x].size();j++)
		{
			int v=g[x][j].v-m;
			for(int k=0;k<g[y].size();k++)
			{
				int v1=g[y][k].v-m;
				ans=min(ans,dis[v][v1]+g[x][j].w+g[y][k].w);
			}
		}
		cout << ans+a[x]+a[y] << "\n";
	}
	return 0;
}
