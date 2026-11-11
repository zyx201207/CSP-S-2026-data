#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N=5e5+15,M=505,inf=1e14+114;

int w[N];
vector<pii>a[M];//每个线路的所有站点，时间
vector<pii>s[N];//每个站点所有的路线，时间 
int c,n,m,d,q;
int dis[M][M];//最短路 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
	}
	
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		
		for(int j=1;j<=k;j++)
		{
			int A,t;
			scanf("%lld%lld",&A,&t);
			a[i].push_back({A,t});
			s[A].push_back({i,t});
			
		}
		
	}
	for(int i=1;i<=n;i++)//虚点
	{
		for(auto tmp:a[i])
		{
			int v=tmp.first,t1=tmp.second;//v是地铁站
			for(auto tmp2:s[v])
			{
				int to=tmp2.first,t2=tmp2.second;//to是另一个虚点
				if(to==i) continue;
				dis[i][to]=min(dis[i][to],t1+t2);
			} 
			
		}
	} 
	
	for(int k=1;k<=n;k++)//floyed
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&j!=k&&i!=k)
				{
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				}
			}
		}
	}
	
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=inf;
		for(auto tmp:s[x])
		{
			for(auto tmp2:s[y])
			{
				int u=tmp.first,v=tmp2.first,tu=tmp.second,tv=tmp2.second;
				ans=min(ans,dis[u][v]+tu+tv);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	
	return 0;	
}
/*
case1:
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

case2:
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3





这题是什么最短路？

弗洛伊德能过吗？500^3+询问100000*400，还有初始化的zako？
zakozako
zako zako
我是小南娘，叽叽叽叽急急急。

肯定是对铁路建虚电，虚点最多500，所以考虑转到虚点上最短路，怎么转？

哦，先枚举每个虚点的所有边，这个是500000级别，

再枚举每个当前地铁站的20条出边，复杂度就有保证了！！ 
*/