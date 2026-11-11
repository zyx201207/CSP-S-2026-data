#include <iostream>
#include <vector>
#include <cstring>
#define big long long
using namespace std;
big _,n,m,d,q;
big tm[500005];
big k[503];
struct Node1{
	big sta,dist;
}; vector <Node1> lines[503];
struct Node2{
	big lines,idx;
}; vector <Node2> stations[500005];
// 对于一个站，它被那些地铁线包含，分别是那条线的第几个站点
big dis[503][503];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	scanf("%lld %lld %lld %lld %lld",&_,&n,&m,&d,&q);
	for(big i = 1;i <= n;i++) dis[i][i] = 0;
	for(big i = 1;i <= m;i++) scanf("%lld",tm+i);
	for(big i = 1;i <= n;i++)
	{
		scanf("%lld",k+i);
		for(big j = 0,a,t;j < k[i];j++)
		{
			scanf("%lld %lld",&a,&t);
			lines[i].push_back({a,t});
			stations[a].push_back({i,j});
		} // 先存下来再说 
	}
	// 注意到步行时间只和换乘次数有关
	// 不换乘就没有步行时间
	// 那么实际上每一条地铁线路就是一个连同块
	// 我们不妨根据一整条地铁线路来考虑
	// 现将每一条地铁线路缩成一个点 
	// 遍历这个站上的所有点，这些点之间会有一些换乘
	// 请注意，换乘站的站台似乎需要另外考虑
	// 因为我们到换乘站并不需要下到站台
	// 那这样怎么办呢
	// 现在我们的思路是
	// 把每一个地铁线路看成一个连同块
	// 然后求出从每一个地铁线路出发，到另外一条地铁线路（站台到站台）需要的步行距离
	// 答案是这个距离加上起点站到该线站台的距离，加上终点站到该线站台的距离
	// 这似乎是对的 
	// 下面开始建图
	// 哈哈，这要是个 Floyd 那就好玩了
	// 呵呵呵呵呵 
	for(big i = 1;i <= m;i++) // 对于每一个地铁站
	{
		if(stations[i].size() == 1) continue; // 不是换乘站
		// 否则进行遍历
		for(auto st1: stations[i])
		{
			big ln1 = st1.lines, idx1 = st1.idx;
			for(auto st2: stations[i])
			{
				big ln2 = st2.lines, idx2 = st2.idx;
				if(ln1 == ln2) continue; // 跳过这个建图
				// 否则开始建图
				// printf("[%lld,%lld] [%lld,%lld]\n",ln1,idx1,ln2,idx2);
				dis[ln1][ln2] = min(dis[ln1][ln2],lines[ln1][idx1].dist+lines[ln2][idx2].dist);
			}
		}
	}
	for(big k = 1;k <= n;k++)
	{
		for(big i = 1;i <= n;i++)
		{
			for(big j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--) // 4e7 可以 
	{
		big st,ed,ans = 1e18; scanf("%lld %lld",&st,&ed);
		for(auto st1: stations[st])
		{
			big ln1 = st1.lines, idx1 = st1.idx;
			for(auto st2: stations[ed])
			{
				big ln2 = st2.lines, idx2 = st2.idx;
				ans = min(ans,tm[st]+lines[ln1][idx1].dist+dis[ln1][ln2]+lines[ln2][idx2].dist+tm[ed]);
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
