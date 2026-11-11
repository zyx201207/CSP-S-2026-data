#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline int lg2(int x){ return 31^__builtin_ctz(x); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }
const int M=2e6+5;
int n,N,k;
struct Edge{
	int to,nxt;
}e[M*2];
int hd[M],tot;
int u[M],v[M];
int dfn[M],seq[M],tim,f[21][M],jp[21][M],dep[M],out[M];
int mx[M],son[M];

void add(int u,int v){
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
inline Node& add(Node &A,int z){
	if(!z)return A;
	return A=max({A, Node(A.x,z), Node(A.y,z)});
}
inline Node operator+ (const Node &A,const Node &B){
	return max({A,B,Node(A.x,B.x),Node(A.x,B.y),Node(A.y,B.x),Node(A.y,B.y)});
}
inline Node& operator+= (Node &A,const Node &B){ return A=A+B; }
Node ins[M],ous[M];
int vins[M],vous[M];
int lins[M],lous[M];

void pre_ins(int x,int fa){
	ins[x]=(x<=n?Node(x,x):Node());
	for(int i=hd[x];i;i=e[i].nxt)if(fa!=e[i].to){
		int y=e[i].to;
		pre_ins(y,x);
		ins[x]+=ins[y];
	}
}
int kth_fa(int x,int k){
	while(k){
		int t=__builtin_ctz(k);
		x=jp[t][x],k^=(1<<x);
	}
	return x;
}
bool vis[M];
int lim,now;
void solve(int x,int fa){
	mx[x]=0;
	for(int i=hd[x];i;i=e[i].nxt)if(fa!=e[i].to&&!vis[fa]){
		int y=e[i].to;
		solve(y,x);
		chkmax(mx[x],mx[y]+1);
	}
	now+=(mx[x]>=2*lim);
}
int check(int M){
	lim=M,now=0;
	for(int i=n+1;i<=N;i++){
		vis[i]=1;
		solve(vins[i],0);
		solve(vous[i],0);
		vis[i]=0;
	}	
	return now;
}
void procedure(){
	n=read(),k=read();
	N=2*n-1;
	for(int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		cout<<"add "<<u[i]<<" "<<v[i]<<endl;
		add(u[i],n+i),add(n+i,v[i]);
	}
	dfs(1,0);
	for(int i=1;i<=N;i++) cout<<dfn[i]<<" "; cout<<endl;
	for(int i=1;(1<<i)<=N;i++)
		for(int j=1;j<=N-(1<<i)+1;j++)
			f[i][j]=get(f[i-1][j],f[i-1][j+(1<<i-1)]);

	qz[0]=hz[N+1]=Node();
	for(int i=1;i<=N;i++) add(qz[i]=qz[i-1],seq[i]<=n?seq[i]:0);
	for(int i=N;i>=1;i--) add(hz[i]=hz[i+1],seq[i]<=n?seq[i]:0);

	pre_ins(1,0);
	for(int i=1;i<=N;i++)ous[i]=qz[dfn[i]-1]+hz[out[i]+1];

	cout<<"dfs"<<endl;
	for(int i=n+1;i<=N;i++){
		{
			auto [x,y,d]=ins[i];
			lins[i]=d;
			if(dep[x]>dep[y]) swap(x,y);
			vins[i]=kth_fa(x,d/2);
		}
		{
			auto [x,y,d]=ous[i];
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
	printf("%d\n",ans);
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