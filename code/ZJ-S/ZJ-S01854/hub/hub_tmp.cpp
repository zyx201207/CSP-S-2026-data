#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }
const int M=2e6+5;
int n,N,k;
struct Edge{
	int to,nxt;
}e[M*2];
int hd[M],tot;

int dfn[M],seq[M],tim,f[21][M],jp[21][M],dep[M],out[M];
int mx[M],son[M];

void add(int u,int v,int i){
	e[++tot].to=v;
	e[tot].nxt=hd[u];
	hd[u]=tot;
}
void dfs(int x,int fa){
	dfn[x]=++tim,seq[tim]=x;f[0][dfn[x]]=fa,jp[0][x]=fa;
	for(int i=1;i<=20;i++)
		jp[x][i]=jp[jp[x-1][i]][i];
	mx[x]=0;
	for(int i=hd[x];i;i=e[i].nxt)if(fa!=e[i].to){
		int y=e[i].to;
		dep[y]=dep[x]+1,dfs(y,x);
	}
	out[x]=tim;
}
int get(int x,int y){ return dfn[x]<dfn[y]?x:y; }
int LCA(int x,int y){
	if(x==y)return x;
	if((x=dfn[x])>(y=dfn[y]))swap(x,y);
	int p=lg2(y-x++);
	return get(f[p][x],f[p][y-(1<<p)+1]);
}
int dist(int x,int y){
	if(!x||!y)return -1;
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

struct Node{
	int x,y,d;
	Node(){ x=y=0,d=-1; }
	Node(int X,int Y){ x=X,y=Y,d=dist(X,Y); }
}qz[M],hz[M];
inline bool operator< (const Node &A,const Node &B){ return A.d<B.d; }
inline void add(Node &A,int z){
	if(!z)return;
	return max({A, Node(A.x,z), Node(A.y,z)});
}
inline Node operator+ (const Node &A,const Node &B){
	return max({A,B,Node(A.x,B.x),Node(A.x,B.y),Node(A.y,B.x),Node(A.y,B.y)});
}
Node ins[N],ous[N];
int vins[N],vous[N];
int lins[N],lous[N];

void pre_ins(int x,int fa){
	ins[x]=(x<=n?Node(x,x):Node());
	for(int i=hd[x];i;i=e[i].nxt)if(fa!=e[i].to){
		int y=e[i].to;
		dfs(y,x);
		ins[x]+=ins[y];
	}
}
void kth_fa(int x,int k){
	while(k){
		int t=__builtin_ctz(k);
		x=jp[t][x],k^=(1<<x);
	}
	return x;
}

bool check(int M){
	
}
void procedure(){
	n=read(),k=read();
	N=2*n-1;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,n+i),add(n+i,v);
	}
	dfs(1,0);
	for(int i=1;(1<<i)<=N;i++)
		for(int j=1;j<=N-(1<<i)+1;j++)
			f[i][j]=get(f[i-1][j],f[i-1][j+(1<<i-1)]);

	qz[0]=hz[N+1]=0;
	for(int i=1;i<=N;i++) add(qz[i]=qz[i-1],seq[i]<=n?seq[i]:0);
	for(int i=N;i>=1;i--) add(hz[i]=hz[i+1],seq[i]<=n?seq[i]:0);

	pre_ins(i);
	for(int i=1;i<=N;i++)ous[i]=qz[dfn[i]-1]+hz[out[i]+1];

	for(int i=n+1;i<=N;i++){
		{
			auto [x,y,d]=ins[i];
			lins[i]=d;
			if(dep[x]>dep[y]) swap(x,y);
			vins[i]=kth_fa(x,d/2);
		}
		{
			auto [x,y,d]=vous[i];
			lous[i]=d;
			if(dep[x]>dep[y]) swap(x,y);
			vous[i]=kth_fa(x,d/2);
		}
	}

	int L=1,R=n-1,ans=n-1;
	while(L<=R){
		int M=(L+R)>>1;
		if(check(M)<=k){
			ans=M;
			L=M-1;
		}else
			R=M+1;
	}
}
void clear(){
	for(int i=1;i<=N;i++)hd[i]=mx[i]=0; tot=tim=0;
}
int main(){
	assert(freopen("hub.in","r",stdin));
	assert(freopen("hub.out","w",stdout));
	int c=read(),T=read();
	while(T--) procedure(),clear();
}