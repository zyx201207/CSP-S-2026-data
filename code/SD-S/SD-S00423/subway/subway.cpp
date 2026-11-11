#include <bits/stdc++.h>
using namespace std;
namespace MySpace{
	#define lowbit(x) ((x)&(-(x)))
	inline void read(){}
	template<typename T,typename... R>
	inline void read(T& x,R&... oth){
		x=0;T f=1;
		char c=getchar();
		while (c<'0' || c>'9'){
			if (c=='-') f=-1;
			c=getchar();
		}
		while (c>='0' && c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
		x=x*f;
		read(oth...);
		return;
	}
	template<typename T>
	T qpow(T a,T n,T p){
		T res=1;
		for (;n;n>>=1){
			if (n&1) res=(long long)(res*a)%p;
			a=(long long)(a*a)%p;
		}
		return res;
	}
	template<typename T>
	T gcd(T a,T b){return b<=0?a:gcd(b,a%b);}
}
using namespace MySpace;
//const int LuoTianYi=0x66ccff;
/*
14:41
T2是否过于猎奇了...这啥啊，裸的Floyd吗，如何绷住
首先我们可以确定w纯粹没用 
我们考虑一下如何转移
我们需要知道当前是哪个线路啊，不然怎么做
我们不妨钦定对于一条线路的一个部分不换乘，那么这样可以出一条边
然后那就必须换乘，那这样就是裸的全源最短路了
shift，怎么n是线路数，读错题了
那我们不妨按照线路连边，跑dij的时候记录当前走的哪个线路，由于dij，它必定是对的
而对于换乘，我们直接选择拆点，那甚至不需要记录当前走的线路了
这样的话，应该是md个点，\Sigma k=S条边
注意到到某个地方换乘然后再做一站再换回来可能更优
直接dij跑全源最短路是O(mdSlogS+qd^2)的，大概是44pts 
现在的突破口就是如何利用地铁线路很少这个性质，把n送进复杂度里
我们从特殊性质B入手，特殊性质B就是把拆点去掉后的正解 
我们对于每一条线路，预处理出其上的最短路，这个是S的
哦不对，每一条线路上的最短路是0
我们注意到如果地铁无向的话，一个线路上你走到哪个点没有本质区别 
如果地铁有向，那么注意到我们需要把边所有连向后半部分，点的数量没有减少
但是如果用线段树优化建图，其实可以做到低复杂度了
我去怎么已经15:22了，我要看看T3 T4换换脑子 
我们假设是无向的，不然我也不会了 
现在17:16，我感觉我要死了，这个T2无向是肯定不对的
力竭了，利用样例证明了是有向的

写暴力吧
注意到到某个地方换乘然后再做一站再换回来 
*/ 
#define int long long
const int maxn=1e4+5;
const int maxm=505;
int n,m,d,QQ;
int w[maxn];
int t[maxn];
vector<int> est[maxn];
int getid(int u,int i){
	return (u-1)*d+i;
}
struct edge{int v,w;};
vector<edge> e[maxn];
int dis[maxn][maxn];
struct node{
	int v,w;
	friend bool operator<(node a,node b){
		return a.w>b.w; 
	} 
};
priority_queue<node> q;
bitset<maxn> vis;
void dij(int s){
	for (;!q.empty();q.pop());
	vis=0;dis[s][s]=0;
	q.push({s,0});
	while (!q.empty()){
		int u=q.top().v;q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (auto i:e[u]){
			int v=i.v,w=i.w;
			if (dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
	return; 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(n,n,m,d,QQ);
	for (int i=1;i<=m;i++) read(w[i]);
	for (int i=1;i<=n;i++){
		int k;read(k);
		for (int j=1;j<=k;j++){
			int a;read(a);
			read(t[getid(a,i)]);
			est[a].push_back(getid(a,i));
		}
	}
	for (int i=1;i<=m;i++){
		for (auto j:est[i]){
			for (auto k:est[i]){
				e[j].push_back({k,t[j]+t[k]});
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for (int i=1;i<=m;i++)
		for (auto j:est[i])
			dij(j);
	while (QQ--){
		int u,v;read(u,v);
		int ans=0;
		for (auto i:est[u])
			for (auto j:est[v])
				ans=min(dis[i][j]+t[i]+t[j],ans);
		ans+=w[u]+w[v];
		printf("%lld\n",ans);
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






