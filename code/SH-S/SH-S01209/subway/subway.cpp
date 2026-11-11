//c测试点编号 
//m个地铁站    w[i]:i号站的站厅到地铁口的时间
//n条地铁线路  i号线路经过k[i]个站
//这些站的站厅的编号为 a[i][1]...a[i][k[i]]
//在a[i][j]站厅，到第i条线路的站厅需要t[i][j]时间 
//每个地铁站最多有d条线  网络连通 
//总步行时间为进出站和换乘的步行时间之和

#include <bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,m,d,q,w[500005],k[505];
vector<int> sta[500005];//sta[i]:i号站厅有哪些线 
int T[500005][25];//T[i][j]:从i号站厅到该站升序第j条线站台的时间 
int g[505][505];//g[i][j]:i线到j线在一个站内换乘的时间
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++) sta[i].push_back(1e9);
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			sta[a].push_back(i);
			T[a][sta[a].size()-1]=t;
		}
	}
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
			g[i][j]=1e18;
	for(int i=1;i<=500;i++)
		g[i][i]=0;
	for(int S=1;S<=m;S++)
	{
		int numL=sta[S].size()-1;
		for(int i=1;i<=numL;i++)
		{
			for(int j=i+1;j<=numL;j++)
			{
				int Li=sta[S][i],Lj=sta[S][j];
				g[Li][Lj]=min(g[Li][Lj],T[S][i]+T[S][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(g[i][j]!=1e18) g[j][i]=g[i][j];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][k]+g[k][j]<g[i][j])
				{
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<g[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int minn=2e18;
		for(int i=1;i<sta[x].size();i++)
		{
			for(int j=1;j<sta[y].size();j++)
			{
				minn=min(minn,g[sta[x][i]][sta[y][j]]+T[x][i]+T[y][j]);
			}
		}
		cout<<w[x]+w[y]+minn<<endl;
	}
	return 0;
}
