#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
void file(){
	 freopen("subway.in","r",stdin);
	 freopen("subway.out","w",stdout);
}
/*
Oct 31 == Dec 25?
如果你现在所做的一切都是一场没有收获的尝试，
你还会去做吗？
我不知道。 

高三。
被拉过来给学校再弄个省一
挺好的 权当放松了
 
我迟迟不想写下这道题的正解代码 
虽然隔了一年 但是早就看出答案的我 心生惰意。

高三好累
好累
好累

不想写
不想写
不想写。

但又如何呢，没有游戏玩，也没有作业做
只能在代码里发发牢骚

2026. 10. 31 
于七宝中学 
*/
const ll INF=1e15;
const ld ERR=0.000000000001;
const ll N=509;
const ll M=500009;
const ll K=29;
ll c,n,m,mxLines,q,d[N][N],w[M];
ll lines[M][K],t[M][K],k[N];
vector<ll> traceback[N];
/*
d[u][v] u号线的"井下状态"到v号线的"井下状态"所需的步行时间
lines[s][id] s号站的线路信息
t[s][id] s号站的换乘时间信息
k[l] l号线的线路总站点数（输入用）  
*/
void input(){
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&mxLines,&q);
	rep(i,1,m)scanf("%lld",&w[i]);
}
ll hd[M*2],nE=0;
struct Edge{
	ll to,w,nxt;
}e[M*2];
ll nV;
void addedge(ll u,ll v,ll w){
//	cout<<u<<" "<<v<<" "<<w<<endl;
	e[++nE]=(Edge){v,w,hd[u]};
	hd[u]=nE;
}
ll dst[M*2],vst[M*2];
struct Node{
	ll id,d;
	bool operator<(const Node&a)const{
		return d>a.d;
	}
};
void Dijkstra(ll st){
	rep(i,1,nV)dst[i]=INF,vst[i]=0;
	dst[st]=0;
	priority_queue<Node> q; 
	q.push((Node){st,0});
	while(!q.empty()){
		ll u=q.top().id; q.pop();
		if(vst[u])continue;
		vst[u]=1;
		for(ll i=hd[u];i;i=e[i].nxt){
			ll v=e[i].to,w=e[i].w;
			if(dst[v]>dst[u]+w){
				dst[v]=dst[u]+w;
				if(vst[v])continue;
				q.push((Node){v,dst[v]});
			}
		}
	}
}
void solveBF(){
	nV=m;
	rep(i,1,n){
		scanf("%lld",&k[i]);
		ll preV=-1;
		rep(j,1,k[i]){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			nV++;
			addedge(a,nV,t);
			addedge(nV,a,t);
			if(preV!=-1){
				addedge(preV,nV,0);
				addedge(nV,preV,0);
			}
			preV=nV;
		}
	}
	rep(i,1,q){
		ll x,y; scanf("%lld%lld",&x,&y);
		Dijkstra(x);
		ll ans=w[x]+w[y]+dst[y];
		printf("%lld\n",ans);
	}
} 
void solve(){
	rep(i,1,n){
		scanf("%lld",&k[i]);
		rep(j,1,k[i]){
			ll a; scanf("%lld",&a);
			lines[a][++lines[a][0]]=i;
			scanf("%lld",&t[a][lines[a][0]]);
		}
	}
	rep(i,1,n)
		rep(j,1,n)d[i][j]=INF;
	rep(i,1,n)d[i][i]=0;
	rep(iStation,1,m){
		ll nLines=lines[iStation][0];
		rep(i,1,nLines) 
			rep(j,i+1,nLines){
				ll u=lines[iStation][i],v=lines[iStation][j];
				d[u][v]=min(d[u][v],t[iStation][i]+t[iStation][j]);
				d[v][u]=d[u][v];	
			}
	}
	rep(k,1,n)
		rep(u,1,n)
			rep(v,1,n)d[u][v]=min(d[u][v],d[u][k]+d[k][v]);

	rep(iQ,1,q){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=INF;
		ll nLinesX=lines[x][0];
		ll nLinesY=lines[y][0];
//		cout<<nLinesX<<" "<<nLinesY<<endl;
		rep(i,1,nLinesX)
			rep(j,1,nLinesY)ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+d[lines[x][i]][lines[y][j]]);
		printf("%lld\n",ans);
	} 
}
int main(){
	file();
	input();
	if(n<=200&&q<=200)
		solveBF();
	else
		solve();
	return 0;
}

