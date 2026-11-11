#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define ll long long
#define pb push_back
#define fi first
#define sc second
#define mk make_pair
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}
template<typename T>inline void write(T x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x >= 10){
		write(x/10);
	}
	putchar(x % 10 + '0');
}
const int N = 5e5 + 10,M = 510;
int C = 0,n = 0,m = 0,d = 0,Q = 0;
ll w[N];
int K[N]; 
struct node{
	int num;
	ll dis;
	node(int a = 0,ll b = 0){
		num = a;
		dis = b;
	}
	bool operator < (const node a)const{
		return dis > a.dis;
	}
};

vector<node> s[N]; // 对于第 i 个站厅能到达的线路点。 
vector<node> vec[M];  // 对车站建的一张图。 
ll dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(C);read(n);read(m);read(d);read(Q);
	rep(i,1,m){
		read(w[i]) ;// i 这个地铁站出战和入站的用时。 
	}
	rep(i,1,n){
		read(K[i]);
		for(int j = 1;j<=K[i];++j){ // 第 i 个线路能到达的点们，和对应的边权。 
			int x = 0,y = 0;
			read(x);read(y);
			s[x].pb(node(i,y)); // 站点 x 到达第 i 个线路的边权是 y 
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i<=n;++i){
		dis[i][i] = 0;
	}
	rep(i,1,m){// 枚举每个站点。 
		int len = s[i].size();
		for(int j = 0;j<len;++j){ //第 j 个车站 
			int u = s[i][j].num;
			ll d1 = s[i][j].dis;
			for(int k = j + 1;k < len;++k){
				int v = s[i][k].num;
				ll d2 = s[i][k].dis;
				dis[u][v] = min(dis[u][v],d1 + d2);
				dis[v][u] = dis[u][v];
			}	
		}
	}	
	
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			for(int k = 1;k<=n;++k){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]); 
			}
		}
	}
	rep(i,1,Q){
		int u = 0,v = 0;
		read(u);read(v);
		ll ans = INF;
		for(int j = 0;j<(int)s[u].size();++j){
			int x = s[u][j].num;
			ll d1 = s[u][j].dis;
//			cout <<"x: "<<x<<endl;
			for(int k = 0;k<(int)s[v].size();++k){
				int y = s[v][k].num;
				ll d2 = s[v][k].dis;
//				cout <<"y: "<<y<<endl;
				ans = min(ans,dis[x][y] + d1 + d2);
			}
		}
		ans = ans + w[u] + w[v];
		write(ans);
		putchar('\n');
	}
	
	return 0;
}
/*
已用 20 min 

先写 nm logm。 

考虑转化一下对象，把第 i 个线路看成一个点，所有在第 i 个线路上的点都向这个点连边。

直接对每个点做不好做，我们考虑 n = 500，计算两两线路之间的最短路。

所以要让这个图上只有线路点才行，你考虑一个站厅实际上没啥用，我们可以 O(400) 的对一个站厅的所有边权。

也就是枚举一个站点作为入口，另一个作为出口，然后连边。

这样建出来新的一张图，对这个图跑 Floyd，复杂度很对啊。

然后我们要记录第 i 个站厅能到达的 20 个线路。

对于一个查询 (x,y)，枚举 O(400) 的路线选择情况。

其实不是 O(400)，这个可以离线成 O(20) + O(20)。

对于建图，具体地，对每个站厅维护到达的站点，O(20)。

用一个 vector 可以完成记录。 

55 min
此时是 1.5H 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
现在是 4:36 过去了 2H 06 min 大样例全过。 左边人电脑炸了，祝好。 

现在这个做法是 n * m*d^2 log m*d^2 的，过不了啊，现在是对每个线路点跑一边 dij。dij 的复杂度是 m log m 的吧？

考虑我们用邻接矩阵记录边怎么样，这样会变成 n^2 个边。

然后考虑这样跑 dij 理论上还不如跑 Floyd，但是为啥我大样例用 dij 跑这么快。 

距离考试结束还有 1H 30 min ，我刚写完 floyd 做法，感觉 1.25 e 8 也不是很能过啊，不管了我相信我的理论复杂度吧 

关键是理论上来说，每个点，最多会有 20 个站点，那么这些站点两两之间会形成 m * 400 个边，这个数量级。 
*/
