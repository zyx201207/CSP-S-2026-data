#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline
#define int long long

namespace OIfast{
	#define endl putchar('\n')

	line lint read(){
		lint x=0;int f=1;char c=getchar();
		while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
		return x*f;
	}

	line void wte(lint x){
		static int sta[40],top=0;
		if(x<0) putchar('-'),x=-x;
		do{sta[++top]=x%10;x/=10;}while(x);
		while(top) putchar(sta[top--]+48);
		return putchar(' '),void();
	}
}using namespace OIfast;

/*
 像是神秘图论建模最短路问题
 发现 q 次询问是假的 n (即站台数很少) 挂一个 vector 就行
 不对 ? 那这个问题是不是甜甜的 ?
 没有负边权 地铁口到站厅直接不管最后处理 
 不对 n m 看反了
 站点向线路建边 边权为 t_{i,j} 同一个线路就像是一个连通块 ?
 这样换线有没有问题 ? 貌似没有 那这样边数是 O(nm) 的 跑一次 dijkstra 是 O(mlognm+m)
 这也太慢 哦哦哦 不对 它规定了对于一个地铁站 最多有 d 个 "儿子" d \le 20 !
 那这样边数就是 O(dm) 的 复杂度是不是可以过了 一次 O(mlogdm+m) m 好烦 学生优化到现在只有 32pts /ll 
 问题可以再次刻画为 st 和 ed 走到同一个线路的最短距离 那对于线路和线路之间 连边它们有公共站点的最小 T[u][i] + T[v][i]
 这样边数是 O(n^2) 的 对于每次询问 跑 d 次 dijkstra 最后是 O(qd nlogn^2)
 这样还是好大 感觉不能跑 d 次 对 不能跑 而且还是好卡 但多半跑不满 ok 想办法把这个优化掉就有 200pts 了
 哦 是不是我每次新建 2d 条边就行了 那现在 O(qnlogn^2) 开写

 **注意加上两个点到地铁口的距离**

 欸有个问题 怎么算两两距离 哦 O(dm) 向每一个站点尝试贡献 每个站点只要最小的两个
 欸 ? 我需要冷静一下 是 O(d^2m) 上述有问题
 亲爱的~为什么~你跑不动~
 我猜测是建边删除的问题 我将严肃使用 vector
 还真是 但为啥这个 4 6 7 跑这么慢 7 s
 全都是 q 大的炸了 先放吧 滚回来了 /ll 想想还能怎样优化
 欸 我为什么非要跑最短路呢 ? 500 为啥不跑 Floyd ?
*/

const int N=5e5+5,M=3e5+5;
const lint INF=1e18+5;
int c,n,m,d,Q,W[N],A[N][25],T[N][25],D[N];

lint dist[505][505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read(),n=read(),m=read(),d=read(),Q=read();
    for(int i=1;i<=m;++i){
        W[i]=read();
    }
    for(int i=1;i<=n;++i){
        int k=read();
        while(k--){
            int u=read();
            lint w=read();
            ++D[u];
            A[u][D[u]]=i;
            T[u][D[u]]=w;
        }
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
        dist[i][j]=INF;
    }
    for(int i=1;i<=m;++i){
        for(int f=1;f<=D[i];++f) for(int g=f+1;g<=D[i];++g){
            int u=A[i][f],v=A[i][g];
            lint w=T[i][f]+T[i][g];
            dist[u][v]=min(dist[u][v],w);
            dist[v][u]=min(dist[v][u],w);
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i) if(i^k){
            for(int j=1;j<=n;++j) if(j^k and i^j){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(Q--){
        int u=read(),v=read();
        lint ans=INF;
        for(int i=1;i<=D[u];++i) for(int j=1;j<=D[v];++j){
            ans=min(ans,W[u]+W[v]+dist[A[u][i]][A[v][j]]+T[u][i]+T[v][j]);
            if(A[u][i]^A[v][j]) continue;
            ans=min(ans,W[u]+W[v]+T[u][i]+T[v][j]);
        }
//        cout<<"     ans = ";
        wte(ans),endl;
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
output:
35
16
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
output:
32
17
*/