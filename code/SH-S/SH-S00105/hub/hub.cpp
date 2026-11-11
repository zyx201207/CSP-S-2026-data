#include<cstdio>
#include<vector>
#include<array>
using namespace std;
template<class T>
inline void chkmax(T &x,T y){
	(x<y)&&(x=y,true);	return;
}
template<class T>
inline void chkmin(T &x,T y){
	(x>y)&&(x=y,true);	return;
}
const int SIZI=(1<<16)-1;
char bufi[SIZI];	char *Si=bufi,*Ti=bufi;
#define load() (Ti=bufi+fread(Si=bufi,1,SIZI,stdin))
#define gc() (((Si==Ti)&&(load(),Si==Ti))?EOF:(*Si++))
inline int read(){
	int x=0,f=1;	char ch=gc();
	for(;(ch<'0')||(ch>'9');ch=gc())
		(ch=='-')&&(f=-1);
	for(;(ch>='0')&&(ch<='9');ch=gc())
		x=x*10+ch-'0';
	return x*f;
}
const int SIZO=(1<<16)-1;
char bufo[SIZO];	int bufoidx;
#define flush() (fwrite(bufo,1,bufoidx,stdout),bufoidx=0)
#define pc(c) ((bufoidx==SIZO)&&flush(),bufo[bufoidx++]=c)
inline void write(int x){
	(x<0)&&(pc('-'),x=-x);
	static int stk[10];	int top=0;
	do{
		stk[top++]=x%10;	x/=10;
	}
	while(x);
	for(;top;pc('0'+stk[--top]));
	pc('\n');	return;
}
struct AutoFlusher{
	~AutoFlusher(){
		flush();	return;
	}
}AutoFlush;
const int INF=1e9;
int n,k,lim;
vector<vector<int>> e;
vector<int> sz,dep,mxdep;
vector<vector<array<bool,2>>> f;
vector<vector<array<int,2>>> g;
vector<array<bool,2>> nf;
vector<array<int,2>> ng;
inline void dfs0(int u,int fa){
	(~fa)&&(dep[u]=dep[fa]+1);
	mxdep[u]=dep[u];
	for(int v:e[u]){
		if(v==fa)
			continue;
		dfs0(v,u);
		sz[u]+=sz[v];
		chkmax(mxdep[u],mxdep[v]);
	}
	sz[u]++;
	return;
}
inline void dfs(int u,int fa){
	int su=1,mxdu=dep[u];
	f[u].resize(2);
	f[u][0][0]=false;	f[u][0][1]=false;
	f[u][1][0]=true;	f[u][1][1]=false;
	g[u].resize(2);
	g[u][0][0]=INF;	g[u][0][1]=INF;
	g[u][1][0]=INF;	g[u][1][1]=INF;
	for(int v:e[u]){
		if(v==fa)
			continue;
		dfs(v,u);
		int sv=sz[v];
		nf.clear();	nf.resize(min(su+sv,k)+1);
		ng.clear();	ng.resize(min(su+sv,k)+1,array<int,2>{INF,INF});
		for(int j=1;j<=min(sv,k);j++)	for(int a=0;a<2;a++)
			f[v][j][a]&&(1+mxdu-dep[u]<=lim)&&(ng[j][a]=1);
		for(int i=0;i<=min(su,k);i++)	for(int a=0;a<2;a++){
			(mxdep[v]-dep[u]<=lim)&&(nf[i][a]|=f[u][i][a]);
			(g[u][i][a]+mxdep[v]-dep[u]<=lim)?(chkmin(ng[i][a],g[u][i][a]),1):(g[u][i][a]=INF);
			for(int j=1;(j<=sv)&&(i+j<=k);j++)	for(int b=0;a+b<2;b++){
				nf[i+j][a+b]|=(f[u][i][a]&f[v][j][b]);
				(!(a||b))&&(nf[i+j][a+b+1]|=(f[u][i][a]&((g[v][j][b]+1)/2<=lim)));
				(!(a||b))&&f[v][j][b]&&(g[u][i][a]<=lim)&&(ng[i+j][a+b+1]=1);
				(!(a||b))&&(chkmin(ng[i+j][a+b+1],min(g[u][i][a],g[v][j][b]+1)),true);
			}
		}
		f[u].swap(nf);	g[u].swap(ng);
		su+=sv;	chkmax(mxdu,mxdep[v]);
	}
	/*if(su!=1){
		for(int i=0;i<=min(su,k);i++)	for(int a=0;a<2;a++)
			if(f[u][i][a])
				printf("f[%d][%d][%d]=%d\n",u,i,a,f[u][i][a]);
		for(int i=0;i<=min(su,k);i++)	for(int a=0;a<2;a++)
			if(g[u][i][a]!=INF)
				printf("g[%d][%d][%d]=%d\n",u,i,a,g[u][i][a]);
	}*/
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();
	for(int _=read();_;_--){
		n=read();	k=read();
		vector<vector<int>>(n).swap(e);
		for(int i=0,u,v;i<n-1;i++){
			u=read()-1;	v=read()-1;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		vector<int>(n).swap(sz);
		vector<int>(n).swap(dep);
		vector<int>(n).swap(mxdep);
		vector<vector<array<bool,2>>>(n).swap(f);
		vector<vector<array<int,2>>>(n).swap(g);
		dfs0(0,-1);
		int l=0,r=n;
		while(l<r){
			lim=(l+r)>>1;
			// printf("lim=%d\n",lim);
			dfs(0,-1);
			if(f[0][k][0]||f[0][k][1]||(g[0][k][0]<=lim)||(g[0][k][1]<=lim))
				r=lim;
			else
				l=lim+1;
		}
		write(r);
	}
	return 0;
}
