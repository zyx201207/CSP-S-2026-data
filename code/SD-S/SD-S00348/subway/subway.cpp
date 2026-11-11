#include <bits/stdc++.h>
#define int long long
int c,n,m,d,q;
const int MAXM=5e5+5,MAXN=605,MAXD=22,MAXQ=1e5+5;
const int INF_small=1e15,INF=1e18;
int w[MAXM];
std::vector<std::pair<int,int> > a[MAXN];
int g[MAXN][MAXN]; 
int dist[MAXN][MAXN];

std::vector<std::pair<int,int> > b[MAXM];//记录一下每个点可以到哪些车站 
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin>>c>>n>>m>>d>>q;
//	scanf("%lld%lld%lld%lld%lld",&&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		std::cin>>w[i];
//		scanf("%lld",&w[i]); 
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)g[i][j]=INF;
	}
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;
		std::cin>>k;
//		scanf("%lld",&k); 
		for(int j=1;j<=k;j++){
			int v,w;
			std::cin>>v>>w;
//			scanf("%lld%lld",&v,&w);
			a[i].push_back({v,w});
			b[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=j+1;k<b[i].size();k++){
				g[b[i][j].first][b[i][k].first]=g[b[i][k].first][b[i][j].first]=std::min(g[b[i][j].first][b[i][k].first],b[i][j].second+b[i][k].second);
			} 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			std::cout<<dist[i][j]<<'\n'; 
//		}
//	}
	for(int i=1;i<=q;i++){
		int u,v;
		std::cin>>u>>v;
		int res=1e18;
		for(auto x:b[u]){
			for(auto y:b[v]){
				res=std::min(res,dist[x.first][y.first]+x.second+y.second);
			}
		}
		std::cout<<res+w[u]+w[v]<<'\n';
	}
//	while(1); 
	return 0;
}
//记得开-O2 -Wall -Wextra!
//放松心态
//原神，启动！
//地铁是什么 没坐过 subway是赛百味吗？ 
//可以把线路看成点
//这样我们有一个点数n+m 边数d*m的二分图
//询问l,r 即为求l,r的最短路+进站时间
//对每个站点去做最短路 复杂度是n*(d*m log d*m)
//显然还是不行
//在query的时候可以枚举站点肯定是对的
//我们在算经过1号站点到i的最短路的时候
//必须经过的 
//还有2h 才100+44+0+0 怎么办
 
//分很少 考虑优化
// 换乘是很麻烦的 我希望规避掉它
//如果我们可以求出a[i][j]表示从站点i换乘到站点j的距离就好了
//再建一个图求最短路
//答案可以被表示为 forall u的换乘站点 min dist[i][u][v] 这里dist[i][u][v]=forall j<=n j!=i dist[i][u] + dist[i][v] 而dist[i][v]= a[i][j] + dist [j][i] 
//复杂度：O(n^3+一个比较小的东西*m+q*d^2)
//下面就是求a[i][j]的问题了 
//上面什么乱七八糟的胡说的 我是rz
//不会红提 
//17:08 pass 1,2,3,4,5,6 TLE&WA on 7
//17:12 开小了 TLE on 7 （输入问题 换scanf 记得lld！！！！！！） 
//同步流放哪里来着 另外 这个样例不怎么满啊
//500*500*500+600000*20*20
//问题不是特别大  实在不行写个快读 
 
