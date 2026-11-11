#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
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
 我有两百了 稳住 稳住 只要把 t3 t4 暴力打一打今年 7 勾稳了
 开 t3 考虑什么时候一段区间会有 恰好两条 路径
 那么显然是一段形如 : A A A A A ... A B B B A A ... A A 的路径
 其中 间隔为 1 的两 A A 需要满足不能直接到达 B 就反之 而且注意 只能是 B B B
 我谔谔 好像不太对 题面之说 最短路径 恰好为两个
 算了 不需要考正解 直接打暴力分 能否去 WC 随缘吧
 来 用第二题没用上的最短路 5000 总能跑过吧 ? 我还优化建图了说
 哇塞 优化建图导致答案错了 /ll
 哦 5000 要炸 
*/

line void _init();

const int N=5005,M=1e5+5,INF=0x3f3f3f3f;
int n,x[N],d;

struct edge{
	int to,net;
	int val;
}e[M];

int head[N],hcnt;

line void add(int u,int v,int w){
	e[++hcnt]={v,head[u],w};
	return head[u]=hcnt,void();
}

typedef pair<int,int> node;
priority_queue<node,vector<node>,greater<node> > q;
int dist[N];
bool vis[N];
int st;//,ed;
int wy[N];

line void dijkstra(){
    for(int i=1;i<=n;++i) dist[i]=INF,vis[i]=false,wy[i]=0;
    dist[st]=0,wy[st]=1;
    q.push({0,st});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=e[i].net){
            int v=e[i].to;
            
//            cout<<"u = "<<u<<" -> v = "<<v<<"\n";
            if(dist[v]>dist[u]+e[i].val){
                dist[v]=dist[u]+e[i].val;
                q.push({dist[v],v});
                wy[v]=wy[u];
            }
            else if(dist[v]==dist[u]+e[i].val){
                wy[v]+=wy[u];
            }
        }
    }
    return ;
}

line void sol(){
    _init();
    n=read(),d=read();
    for(int i=1;i<=n;++i){
        x[i]=read();
        
//        cout<<"x["<<i<<"] = "<<x[i]<<"\n";
    }
    // for(int i=2;i<=n;++i){
	// 	add(i,i-1,0);
    // }
    for(int i=1;i<=n;++i){
        int j=i+1;
        while(x[j]-x[i]<=d and j<=n) ++j;
		// add(i,j-1,1);
        for(int k=i+1;k<=j-1;++k){
            add(i,k,1);
        }
    }
    
//    cout<<"Check : n = "<<n<<" d = "<<d<<"\n";
//    cout<<"		Coming here\n";
    
    lint ans=0;
    for(int i=1;i<=n;++i){
        st=i;
        dijkstra();
        for(int j=i+1;j<=n;++j) if(wy[j]==2){
            ++ans;
        }
        
        // cout<<"Check : st = "<<i<<" and the ways : ";
        // for(int j=i+1;j<=n;++j){
        // 	cout<<wy[j]<<" ";
		// }
		// cout<<"\n";
    }
    // cout<<"     ans = ";
    wte(ans),endl;
    return ;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
output:
0
1
*/

line void _init(){
    for(int i=1;i<=n;++i){
        head[i]=0;
    }
    return hcnt=0,void();
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=read(),T=read();
    while(T--) sol();
    return 0;
}