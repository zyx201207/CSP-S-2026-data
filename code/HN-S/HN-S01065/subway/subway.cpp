#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
long long dis[510][510],ans;
vector<pair<int,int> > e[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x,w;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>w;
			e[x].push_back({i,w});
		} 
		dis[i][i]=0;
	} 
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			for(int k=0;k<e[i].size();k++)
			{
				if(j==k) continue;
				int u=e[i][j].first,v=e[i][k].first;
				long long w=e[i][j].second+e[i][k].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,u,v;
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<e[x].size();i++)
		{
			u=e[x][i].first;
			for(int j=0;j<e[y].size();j++)
			{
				v=e[y][j].first;
				ans=min(ans,e[x][i].second+e[y][j].second+dis[u][v]);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
} 
/*
遇到巨佬了 

你说得对，但是B市的地铁是C国的传送门，小W在政府单位上班吗？ 这么有实力！

差点以为是分层图，原来是虚点吗，CCF神机保佑我。

我* m原来是点数吗？ 哦只有n个虚点是有用的？ floyd吧？

你说得对但是我建邻接矩阵是O(m*d^2)=2e8的>floyd O(n^3)=1.25e8>查询O(q*d^2)=4e7,3.65e8能过？ 不过除了24-25,其他的最大1.3e8应该能过。 CCF神机保佑我。CCF神机保佑我。CCF神机保佑我。
 
第7个大样例开O2 才0.4s 发力了 

1h25min AC
 
rp++
rp++
rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++
rp++ 
rp++ rp++ rp++ rp++
*/ 
