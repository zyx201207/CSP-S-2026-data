/*
	666阅读理解题面来了。
	
	没事时间长，慢慢来。
	
	分析一下题意，
	
	一共有m个点，每个点有一个点权。
	
	然后给定n组边，每组边一定构成一条路径，
	
	然后询问两个点，两个端点的点权，加上从这个点到另一个点的路径上的贡献，最小。
	
	这个似乎不适合放在图上去思考。
	
	给定n个点集，这些点集中的点可以互相到达，且代价为0。
	
	如果一个点要到达不属于这个点所在的点集中的点，可以通过中转点的方式到达目标。
	
	每个点作为中转点需要支付一定代价。
	
	求代价最小。 
	
	线路是单向的吗？
	
	能互相到达的话，说明不是单向的。
	
	对于集合内的点，我们连边权为0的边。
	
	然后对于每个点，我们对集合其他与自己编号相同的点连边权为两个权值和的边。
	
	这样我们就能把图建出来了。
	
	最多1e7条边。
	
	暴力的话跑最短路就可以了。
	
	但是这样显然是过不了的，我们需要考虑优化。
	
	首先建图是否可以优化呢？
	
	我们可以考虑不建0边，而是把每条线路都看作一个点，然后去向其他线路连边。
	
	对于连向相同线路的边， 我们只需要保留权值最小的一条，通过这个操作，我们直接将边的数量压缩到2e5级别
	
	等等，n<=500所以是不是floyd就过了。
	
	wcnb 大样例全过。
	
	记得检查空间之类的 
*/ 
#include<bits/stdc++.h>
using namespace std; 
using ll=long long;
const int N=5e2;
const ll inf=1e17;
int C,n,m,D,q; 
ll w[500010];
ll dist[N][N];
vector<int> f[500010];
vector<ll> val[500010]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x;
		ll z;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>z;
			f[x].push_back(i);
			val[x].push_back(z);	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dist[i][j]=inf;
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<f[i].size();j++)
		{
			for(int k=0;k<j;k++)
			{
				int x=f[i][j],y=f[i][k];
				dist[x][y]=min(dist[x][y],val[i][j]+val[i][k]);
				dist[y][x]=min(dist[y][x],val[i][j]+val[i][k]);
			}			
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); 
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y],minn=inf;
		for(int j=0;j<f[x].size();j++)
		{
			for(int k=0;k<f[y].size();k++)
			{
				minn=min(minn,dist[f[x][j]][f[y][k]]+val[x][j]+val[y][k]);
//				cout<<dist[f[x][j]][f[y][k]]<<' ';
			}
		}
		cout<<ans+minn<<'\n';
	}
	return 0;
}