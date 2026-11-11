#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=5e2+10,M=5e5+10,inf=1e18;
int c,n,m,d,q;
int w[M],k[N],dis[N][N]; 
vector<pair<int,int>>g[M];//经过这个点的线路 
void init()
{
	for(int u=1;u<=n;u++)
	{
		for(int v=1;v<=n;v++)
		{
			dis[u][v]=dis[v][u]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
}
void floyed()
{
	for(int k_=1;k_<=n;k_++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k_]+dis[k_][j]);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int u,t;
			cin>>u>>t;
			g[u].push_back({i,t});
		} 
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:g[i])
		{
			int u=x.first,w_1=x.second;
			for(auto y:g[i])
			{
				int v=y.first,w_2=y.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w_1+w_2);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<i<<' '<<j<<' '<<dis[i][j]<<endl;
//		}
//	}
	floyed();
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(auto s1:g[u])
		{
			for(auto s2:g[v])
			{
				//cout<<s1.first<<' '<<s2.first<<endl;
				ans=min(ans,dis[s1.first][s2.first]+w[u]+w[v]+s1.second+s2.second);
			}
		}
		cout<<ans<<endl;
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
