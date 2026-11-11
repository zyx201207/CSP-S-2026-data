#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5+10;
const int N=1010;
//核心思路：两条能换乘的线路，看做两个点，中间连一条边，边权为这两条线路所有换乘站点可能的最小值
//预处理出入口,在新图上跑spfa 
//开始和结束的站厅看作新线:1~n; n+1~2n
int w[M],k[N],mt[N][N];
vector<int> line[M],ltime[N];//第i个站点有哪些线，时间为多少 
vector<int> g[M],gw[M];
int dis[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)//O(m)不超 
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			line[a].push_back(i);
			ltime[a].push_back(t);
			//i->a+n t
			g[i].push_back(a+n);
			g[a+n].push_back(i);
			gw[i].push_back(t);
			gw[a+n].push_back(t);
		}
	}
	memset(mt,0x3f,sizeof(mt));
	for(int i=1;i<=m;i++)//O(m*d*d):1~15不超时 
	{
		for(int u=0;u<line[i].size();u++)
		{
			int a=line[i][u],t1=ltime[i][u];
			for(int v=u+1;v<line[i].size();v++)
			{
				int b=line[i][v],t2=ltime[i][v];
				mt[a][b]=min(mt[a][b],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++)//O(n^2)不超 
	{
		for(int j=i+1;j<=n;j++)
		{
			int W=mt[i][j];
			if(W > 1e15) continue;
			g[i].push_back(j);
			g[j].push_back(i);
			gw[i].push_back(W);
			gw[j].push_back(W);
		}
	}
	while(q--)//O(qm^2)超时 
	{
		int x,y;
		cin>>x>>y;
		//x+n->y+n
		memset(dis,0x3f,sizeof(dis));
		queue<int> q;
		q.push(x+n);
		dis[x+n]=0;
		while(q.size())
		{
			int u=q.front(); q.pop();
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i],w=gw[u][i];
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					q.push(v);
				}
			}
		}
		cout<<dis[y+n]+w[x]+w[y]<<endl;
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
*/
