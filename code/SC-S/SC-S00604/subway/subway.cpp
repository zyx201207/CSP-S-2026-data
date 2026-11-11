#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 5e2 + 5;
const int M = 1000;
const int INF = 0x3f3f3f3f;
int n,m,d,q;
int C;//测试点编号 
int walk[M];//从地铁口走到站厅的时间消耗
long long dis[N][N];
long long edge[N][N];//邻接矩阵存稠密图
int nodeedge[M][M];
int disto[N][M];//站点m进出n的代价 
struct Pair{
	int u,v;
	Pair(int a,int b):u(a),v(b){}
};
vector <int> line[N];//每条线路有哪些站点 
vector <Pair> trip;
vector <int> node[M];//第i个站点所经过的线路 
//存储线路之间两两之间的距离，若有多条线路，选择最小值
//每个站点存储可以到达的线路，pair（线路编号，进出站花费）
//所以说可以这样建模：将站点设置为点，线路设置为边，用并查集来存储同一条线路里面的站点，
//记录来时的线路编号，如果和将要去的点的父亲一样，没有开销，否则开销为进出这两条线路的花费 
//初始时，将long long答案加上两个站点进出站口的时间, 
//参考Dijkstra的思路，将当前站台可以去的站点放入优先队列
//-----------------
//发现另一个问题：很明显，因为线路数更少，所以选取线路当点跑一个floyd会更好
//现在考虑如何将线路设置成点
//如果将线路当成点，那么站台就是边，把一个站台影分身成多个站台，分别连接到其他的线路
//这样，我们要求的就是要走的两个站点所在的线路之间的最短路径，一定要考虑特殊情况：两个站点在同一个线路上 
//如果时这样的话，就会出现这样一个问题：如何表示边的权值？
//还是考虑是否要换线路，那就要记录当前线路
//等等，出现了一种情况，可能会出现一些无用的站点？？？
//哦，两个站点存在直连边，这条边的权值就是（取最小的那一条）分别进出两个站的花费
//现在考虑如何判断两条线路是否直接相连
//要不先用思路一，在进行转换？
//看看我之前已经写了些什么石山 
int main()
{
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	cin >> C >> n >> m >> d >> q;//测试点编号，线路数量，站点数量，每个站点的线路上线，诗人的游览路线数量 
	for(int i = 1;i<=m;i++)
	{
		cin >> walk[i];//每个站口进出的时间 
	}
	for(int i = 1;i<=n;i++)
	{
		int k,x,w;//第k条线路包含了一些什么 
		cin >> k;
		for(int i = 1;i<=k;i++)
		{
			cin >> x >> w;//第k条线路经过站点x，进出花费是w 
			node[x].push_back(k);//将线路k记录在站点x的小本本上面 
			disto[k][x] = w;//线路k进出x的花费 
			line[k].push_back(x); 
		}
	}
	for(int i = 0;i<q;i++)
	{
		int u,v;//q个旅游路线的起点和终点 
		cin >> u >> v;
		Pair ins(u,v);
		trip.push_back(ins); 
	}
	//----------------------------以上已经完成了所有输入，开搞
	//第一步，建立线路与线路之间的边，一定要取最小值
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			edge[i][j] = INF; 
	for(int i = 1;i<=n;i++)
		edge[i][i] = 0;
	//千万注意，edge是 线路之间的最短路长度 
	for(int k = 1;k<=m;k++)
	{
		int siz = node[k].size();
		for(int i = 0;i<siz;i++)
		{
			for(int j = i+1;j<siz;j++)
			{
				int u = node[k][i],v = node[k][j];//已经把两条线路的编号取出来了
				//如何快速访问进出这个站点的代价?ok
				edge[u][v] = min(edge[u][v],(long long)(disto[u][k]+disto[v][k]));//两条线路共享一条边（站点k 
			}
		}
	}
	//爽起，Floyd 
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			for(int k = i;k<=n;k++)
			{
				edge[i][j] = min(edge[i][j],edge[i][k] + edge[k][j]);
				edge[j][i] = edge[i][j];
			}
		}
	}
	//现在特殊处理同一条线路上的点
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			nodeedge[i][j] = INF;
		}
	}
	for(int k = 1;k<=n;k++)
	{
		int siz = line[k].size();
		for(int i = 0;i<siz;i++)
		{
			for(int j = i+1;j<siz;j++)
			{
				int u = node[k][i],v = node[k][j];
				nodeedge[i][j] = u+v;
			}
		}
	}
	int siz = trip.size();
	for(int cur = 0;cur<siz;cur++)
	{
		int u = trip[cur].u,v = trip[cur].v;
		if(nodeedge[u][v])
		{
			cout << nodeedge[u][v] + walk[u]+walk[v];
			continue;
		} 
		long long ans = INF;
		for(int k = 1;k<=m;k++)
		{
			int siz = node[k].size();
			for(int i = 0;i<siz;i++)
			{
				for(int j = i+1;j<siz;j++)
				{
					int u1 = node[k][i],v1 = node[k][j];//已经把两条线路的编号取出来了
					ans = min(ans,edge[u1][v1]);
				}
			}
		}
		cout << ans << endl;
	}
}