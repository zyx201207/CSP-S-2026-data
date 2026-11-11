/*
<已思考 1380s>
乘坐地铁是不要时间的
每个地铁站最多被20个路线经过，
可以对每个地铁站都记录其被哪些线路经过，
n^2随便做了，直接记录两个地铁站之间的代价
2.56

询问很多，
考虑算出从一条路线到另一条路线的最小代价，因为一个路线上的点走到另一个点不要时间
 
 3.17
这样写时间够，样例7跑了1.03，但是为什么我的比答案都要小接近一位，，
 
 3.18，神经数组开小了 
 
 ?神秘关流之后最大点跑了0.51 
应该没问题，
绿~青？ 
*/
/*
小 R 为什么不坐公交？ 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5,D=505;
int n,m,d,q;
int w[N],k[N];
struct nd{
	int line,t;
};
int dis[D][D];
vector<nd> vt[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			vt[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i] = 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto k1 : vt[i])
		{
			int l1=k1.line,t1=k1.t;
			for(auto k2 : vt[i])
			{
				int l2=k2.line,t2=k2.t;
				if(l1 == l2)	continue;
				dis[l1][l2] = min(dis[l1][l2],t1+t2);
			}
		}
	}
	for(int z=1;z<=n;z++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i == j)	continue;
				dis[i][j]=min(dis[i][j],dis[i][z]+dis[z][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<' '<<i<<' '<<j<<endl;
//		}
//	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(auto k1 : vt[l])
		{
			for(auto k2 : vt[r])
			{
				ans = min(ans,dis[k1.line][k2.line]+k1.t+k2.t);
			}
		}
		cout<<ans+w[l]+w[r]<<endl;
	}
	return 0;
 } 
