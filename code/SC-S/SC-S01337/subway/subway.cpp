#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

const int N = 515,M = 5e5+15;
vector<pii> bel[M];
int dis[N][N],w[M],lne[N];
int c,n,m,d,q;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifndef DEBUG
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#else
	freopen("subway7.in","r",stdin);
	freopen("myans.out","w",stdout);
#endif
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>lne[i];
		for(int j = 1,pos,v;j<=lne[i];j++)
		{
			cin>>pos>>v;
			bel[pos].push_back({i,v});
		}
	}
	mem(dis,0x3f);
	for(int i = 1;i<=n;i++)dis[i][i] = 0;
	for(int i = 1;i<=m;i++)
	{
		for(auto p:bel[i])
		{
			for(auto p2:bel[i])
			{
				if(p.first == p2.first)continue;
//				cout<<p.first<<' '<<p2.first<<' '<<p.second+p2.second<<endl;
				dis[p.first][p2.first] = min(dis[p.first][p2.first],p.second+p2.second);
				dis[p2.first][p.first] = min(dis[p2.first][p.first],p.second+p2.second);
			}
		}
	}
	for(int v = 1;v<=n;v++)
	{
		for(int u = 1;u<=n;u++)
		{
			for(int mid = 1;mid<=n;mid++)
			{
				dis[u][v] = min(dis[u][v],dis[u][mid]+dis[mid][v]);
			}
		}
	}

	for(int mid = 1;mid<=n;mid++)
	{
		for(int u = 1;u<=n;u++)
		{
			for(int v = 1;v<=n;v++)
			{
				dis[u][v] = min(dis[u][v],dis[u][mid]+dis[mid][v]);
			}
		}
	}

	int u,v;
	while(q--)
	{
		cin>>u>>v;
		int ans = LLONG_MAX;
		for(auto p:bel[u])
		{
			for(auto p2:bel[v])
			{
//				cout<<dis[p.first][p2.first]<<' '<<p.second<<' '<<p2.second<<' '<<w[u]<<' '<<w[v]<<" ?? "<<endl;
				ans = min(ans,dis[p.first][p2.first]+p.second+p2.second+w[u]+w[v]);
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
/*
14:51 对于每条线路跑并查集，再写一个全源最短路。 
	  对于询问，枚举u,v的起始线路暴力统计 O(md^2+n^3+qd^2) 
15:07 正在比较文件 myans.out 和 SUBWAY7.ANS FC: 找不到差异 250ms大样例 
	  FINISH EXP 100 
*/