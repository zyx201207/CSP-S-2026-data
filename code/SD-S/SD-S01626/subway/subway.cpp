#include <bits/stdc++.h>
#define prs " \n"
#define uinf 0x3f3f3f3f
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,w[M];
int wt[M][N];
int ds[M];
bitset<M> b[N],vis;
//点连了多少线 
vector<int> dc[M];
//线连了多少站台 
vector<int> e[N];
//记录交界点相关信息
//1.交接点本身连接了哪些点？对应的代价？ 
//vector<int> dc;
//2.别的点都连接了哪些交接点？
//vector<int> dc[N];
//所以我们对于一个平常点u,通过访问da[u]得到
//u所能立即达到的交接点的集合，令我们取得的单个元素为v
//我们就可以通过访问 dc[v]来得到这个交接点能达到的其他点
//为保证无"在一个点下线再上同一条线来
//到达一个与其本来就在同一线路的点" 的SB操作
//我们定义同一条线路上的点的距离(贡献w)都为 0
//上述有很多事废话
//但总之目前已过前三个阳历，最后一个阳历TLE了
//我们尝试优化
//目前的思路是完全暴力
//想一想有哪里可以优化的狄梵呢
//线路数量只有500，同一个点最多只有20个线路可以经过，
//这个数据及其邪门 
//我靠神了
//大小限制1GB，我开这么多数组跑大阳历刚刚好1000MB不到
//小巧思这一块
//还有半小时，尝试优化 
//注意到我们只需要看w[lc]和w[rc]，因此可以注意到：
//w对于图上问题无影响
//由于w无影响，所以实质上同一条线路上的点的ds可以视作相等
//那么我们可以以线路为基础进行最短路
//传统意义上的点变为线路
//传统意义上的边变为各个线路的交点
//那么我们就要先求交点
//然后求从lc经过交点和贡献计算最终到rc的贡献
//以此来脱去一层循环
//那么首先我们要把起点坍缩成一条线路？不对，是从一开始就加线路
//卧槽我怎么那么像AI 
void s01ve()
{
	int lc,rc,kc=0;
	cin>>lc>>rc;
	priority_queue<pair<int,pair<int,int>>> pq;
	memset(ds,0x3f,sizeof ds);
	vis.reset();
	ds[lc]=0;
	pq.push({0,{lc,0}});
	while(!pq.empty())
	{
		auto pu=pq.top();
		pq.pop();
		int u=pu.second.first,cc=pu.second.second;
		if(u==rc)
		{
			kc=cc;
			break;
		}
		if(vis[u]) continue;
		vis[u]=1;
		for(int k:dc[u])
			for(int v:e[k])
			{
				if(ds[v]>ds[u]+wt[u][k]+wt[u][cc])
				{
					ds[v]=ds[u]+wt[u][k]+wt[u][cc];
					pq.push({-ds[v],{v,k}});
				}
			}
	}
	cout<<ds[rc]+wt[rc][kc]+w[lc]+w[rc]<<'\n';
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(w,0x3f,sizeof w);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a,t;j<=k;j++)
		{
			cin>>a;
			cin>>t;
			wt[a][i]=t;
			dc[a].push_back(i);
			e[i].push_back(a);
		}
	}
	while(q--)
	{
		s01ve();
	}
	return 0;
}
/*
问题可转化为
给你多个连通块，连通块之间可以由特殊的几个点完全连接：
一个连通块上的任意一个点都可以通过这个点,
以wu+wv(来到这个点和离开这个点) 的贡献消耗 
到达另一个连通块上的任意一个点 (特殊的对于如果起点是这个点，
我们就需要选择走w1,w1,w2,...,wd哪个好)
求一个点到另一个点的最短距离 
*/
