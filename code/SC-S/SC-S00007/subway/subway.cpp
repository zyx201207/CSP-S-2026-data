/*
所以理一下思路：
首先 在一开始算一下 两两路线之间的 f
然后同时记录一下每个车站所连接的路线有哪些，
然后查询就是枚举直接与 x，y 相邻的那些边，然后加上 f 
*/
#include<bits/stdc++.h>
using namespace std;
#define N 502
#define M 500005
#define int long long 

const int inf=1e18;
int c,n,m,d,q,x,y,ans;
int a_,t_;
int val[M],k[N],f[N][N];

struct node{
	int u,w;
};
vector<node> to_z[M]/*,to_l[N]*/;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//n 路线
	//m 站台
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){//厅到口的
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){//路线
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a_>>t_;
			to_z[a_].push_back({i,t_});//这个站台，能到那些路线
//			to_l[i].push_back({a_,t_});//这个路线能到那些站台
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)	f[i][i]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<to_z[i].size();j++){
			int u1=to_z[i][j].u,w1=to_z[i][j].w;//到两条路线
			for(int k=j+1;k<to_z[i].size();k++){
				int u2=to_z[i][k].u,w2=to_z[i][k].w;
				f[u1][u2]=min(f[u1][u2],w1+w2);
				f[u2][u1]=min(f[u2][u1],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=inf;
		for(int i=0;i<to_z[x].size();i++){
			for(int j=0;j<to_z[y].size();j++){
				int u1=to_z[x][i].u,w1=to_z[x][i].w;
				int u2=to_z[y][j].u,w2=to_z[y][j].w;//到两条路线
				ans=min(ans,w1+w2+f[u1][u2]);
			}
		}
		cout<<ans+val[x]+val[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2

8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


bur T2 是啥啊？q 次询问是不是有点难受？
把每条线路看成一个点，然后每个站台向点连边
考虑这个 d 有什么说法，相当于每个站台作为一个点，最多会向外连 20 个边 
哟，是不是其实 因为 n 比较小，而且两个点之间要想连接，必定会经过至少一个路线，
所以是不是计算一下 从每个路线到其他所有点的最短路径，然后查询的时候在遍历一下这些路径就行了？
不知道呢？应该是吧，复杂度的话 查询是 nq 的，
前面的操作，因为边数是 \sum k  跑 n 遍 dij，nklogk 的，我日，好像有点紧
而且这个空间也有点玄那，那怎么办？

应该是不能对于每个 n 枚举 k 的，不然这个就已经 2e8 了，噢噢噢，如果说我会在枚举一个，额，不对
怎么就 1 个小时了啊，我到底干了啥？
哦哦哦，一个点站台的出度的最多为 20，那我是不是直接先求一边线路与线路之间的最小距离，
这样我查询的时候，对于每个点 x，我直接枚举一下他首先去哪个线路 i，再枚举一个最终会到哪个线路 j
那答案就是 dis[i][x]+dis[j][y]+f[i][j] 
这样的话，查询复杂度变成 qnd？那这也不对啊，查询又炸了

哦哦哦，是不是我可以通过这个 f 直接算出开始的 每个路线到每个点的距离，
不行，再想 10 min
前两个东西在一起应该有 80 分

哦哦哦，等一下，你发现 其实 同时连接一个的只有 20 个，意思就是说，连接 x 的有 20 个，y 的有 20 个，
那不直接 单次最多 400 种搭配？

所以理一下思路：
首先 在一开始算一下 两两路线之间的 f
然后同时记录一下每个车站所连接的路线有哪些，
然后查询就是枚举直接与 x，y 相邻的那些边，然后加上 f 

呼，4:30 过了大样例
*/