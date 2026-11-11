#include <bits/stdc++.h>
#define M 500005
#define N 505
using namespace std;
int d[M];
long long dis[N][N];
vector <int> mp[N];
struct node
{
	int u,w;
};
vector <node> st[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,q;
	cin>>c>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,w;
			cin>>u>>w;
			mp[i].push_back(u);
			st[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		for(int o=0;o<mp[i].size();o++)
		{
			int u=mp[i][o],res=0;
			for(int oo=0;oo<st[u].size();oo++)
				if(st[u][oo].u==i)
					res=st[u][oo].w;
			for(int oo=0;oo<st[u].size();oo++)
			{
				int v=st[u][oo].u,w=st[u][oo].w;
				dis[i][v]=min(dis[i][v],1ll*w+res);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int u,v;
		long long ans=1e18;
		cin>>u>>v;
		for(int i=0;i<st[u].size();i++)
		{
			for(int j=0;j<st[v].size();j++)
			{
				int l=st[u][i].u,r=st[v][j].u;
				ans=min(ans,dis[l][r]+st[u][i].w+st[v][j].w);
			}
		}
		cout<<d[u]+d[v]+ans<<"\n";
	}
}