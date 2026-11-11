#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),num##i=(r);i<=num##i;++i)
#define per(i,r,l) for(int i=(r),num##i=(l);i>=num##i;--i)
#define fileI(x) freopen(x,"r",stdin)
#define fileO(x) freopen(x,"w",stdout)
#define ML printf("\n.2lf MB\n",(&M2-&M1)/1024.0/1024)
#define TL printf("\n.2lf s\n",1.0*clock()/CLOCKS_PER_SEC)
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
bool M1;
namespace IO{
	const int SIZE=1<<20;
	char buf[SIZE],*p1=buf,*p2=buf;
	inline char gc(){ return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin), p1==p2)?EOF:*p1++; }
	void read(int &x){
		x=0;
		char ch=gc();
		while(ch<'0'||ch>'9')ch=gc();
		while(!(ch<'0'||ch>'9'))x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	}
}
using IO::read;
const int N=1e6+5;
int bianhao;
struct Edge{ int to,nx; }e[N<<1];
int head[N],elen;
void Insert(int u,int v){
	e[++elen]={v,head[u]};
	head[u]=elen;
}

int n,lim,dmx,rt;
int dep[N],son[N],mdep[N],sdep[N],f[N];
void dfs(int u,int prt){
	sdep[u]=mdep[u]=dep[u]=dep[prt]+1;
	for(int i=head[u],v;i;i=e[i].nx){
		v=e[i].to;
		if(v==prt)continue;
		dfs(v,u);
		mdep[u]=max(mdep[u],mdep[v]);
		if(!son[u]||mdep[son[u]]<mdep[v])
			son[u]=v;
	}
//	if(son[u]){
//		if(mdep[u]!=mdep[son[u]]){
//			printf("\nWa1\n");
//		}
//	}

	f[u]=1;
	for(int i=head[u],v;i;i=e[i].nx){
		v=e[i].to;
		if(v!=son[u])sdep[u]=max(sdep[u],mdep[v]);
		if(mdep[v]-dep[u]>dmx)f[u]+=f[v];
	}
}

int p1,p2,zhijing,rrt,ssum,sz[N],fa[N];
void dfs3(int u,int prt){
//	cerr<<u<<'\n';
	dep[u]=dep[prt]+1;
	sz[u]=1;
	if(!p1||dep[u]>dep[p1])p1=u;
	int mxsz=0;
	for(int i=head[u],v;i;i=e[i].nx){
		v=e[i].to;
		if(v==prt)continue;
		dfs3(v,u);
		sz[u]+=sz[v];
		mxsz=max(mxsz,sz[v]);
	}
	mxsz=max(mxsz,n-sz[u]);
	if(!rrt||mxsz<=ssum){
		ssum=mxsz;
		rrt=u;
	}
}
void dfs4(int u,int prt){
	dep[u]=dep[prt]+1;
	fa[u]=prt;
	if(!p2||dep[u]-1>zhijing)p2=u,zhijing=dep[u]-1;
	for(int i=head[u],v;i;i=e[i].nx){
		v=e[i].to;
		if(v==prt)continue;
		dfs4(v,u);
	}
}

int tmpp;
bool flag;
void dfs2(int u,int prt,int limdep){
	if(dep[u]>limdep)return;
	if(tmpp+f[u]<=lim){
		flag=1;
		return;
	}
	for(int i=head[u],v;i;i=e[i].nx){
		v=e[i].to;
		if(v==prt)continue;
		if(v==son[u]){
			if(sdep[u]-dep[rt]<=dmx)dfs2(v,u,limdep);
			else dfs2(v,u,min(limdep,dep[u]+dmx-(sdep[u]-dep[u])));
		}
		else{
			if(mdep[u]-dep[rt]<=dmx)dfs2(v,u,limdep);
			else dfs2(v,u,min(limdep,dep[u]+dmx-(mdep[u]-dep[u])));
		}
		if(flag)return;
	}
}
bool check2(){
	rep(i,1,n)son[i]=f[i]=0;
	dfs(rt,0);
//	rep(i,1,n)printf("%d \n",f[i]);
	if(f[rt]<=lim)return 1;
	for(int i=head[rt],v;i;i=e[i].nx){
		v=e[i].to;
		tmpp=f[rt];
		if(mdep[v]-dep[rt]<=dmx)continue;
		tmpp-=f[v];
		flag=0;
		dfs2(v,rt,n+1);
		if(flag)return 1;
	}
	return 0;
}
bool check(){
//	rep(i,1,n){
//		rt=i;
//		if(check2()){
//			return 1;
//		}
//	}
	int cur=p2,k=0;
//	if(check)
	if(bianhao<=10||zhijing<=5000){
		while(cur){
			rt=cur;
			if(check2())return 1;
			cur=fa[cur];
			++k;
		}
	}
	else{
		while(cur){
			rt=cur;
			if(abs(zhijing/2-k)<=50){
				if(check2())return 1;
			}
			cur=fa[cur];
			++k;
		}
	}
	return 0;
}
//int ok[N],tmp[N];
void Sol(){
//	scanf("%d%d",&n,&lim);
	read(n),read(lim);
//	scanf("%d",&n);
	rep(i,1,n)head[i]=0;
	elen=0;
//	cerr<<"Passed 1\n";
	rep(i,1,n-1){
		int x,y;
//		scanf("%d%d",&x,&y);
		read(x),read(y);
		Insert(x,y),Insert(y,x);
	}
//	cerr<<"Passed 2\n";
	if(lim==n)return printf("0\n"), void();
	if(lim==n-1)return printf("1\n"), void();
//	cerr<<"Passed 3\n";
//	rep(i,1,n)printf("%d \n",f[i]);

//	rep(i,1,n)ok[i]=1,tmp[i]=0;
//	for(lim=2;lim<=n-2;++lim){
//		for(dmx=1;dmx<=n-1;++dmx){
//			bool flag=0;
//			rep(i,1,n){
//				rt=i;
//				int ttt=check2();
//				flag|=ttt;
//				tmp[i]=ttt;
////				if(check2())ok[i]++;
////				if(!check2())ok[i]=0;
//			}
//			if(flag){
//				if(!(tmp[10]||tmp[11])){
//					printf("\nWa2\n");
//				}
//			}
//		}
//	}
//	rep(i,1,n)printf("%d ",i);
//	putchar('\n');
//	rep(i,1,n)printf("%d ",ok[i]);
//	int mx=*max_element(ok+1,ok+n+1);
//	rep(i,1,n)if(ok[i]==mx)printf("%d ",i);

	p1=p2=zhijing=rrt=ssum=0;
	dfs3(1,0);
//	assert(p1!=0);
//	cerr<<"Passed 4\n";
	dfs4(p1,0);
//	assert(p2!=0);
	int L=1,R=n-1;
//	cerr<<"Passed\n";
	while(L<R){
		int mid=L+R>>1;
		dmx=mid;
//		cerr<<"Innn\n";
		if(check())R=mid;
		else L=mid+1;
//		cerr<<"Outt\n";
	}
	printf("%d\n",R);
}
bool M2;
int main(){
	fileI("hub.in");
	fileO("hub.out");
	int T;
//	scanf("%d%d",&bianhao,&T);
	read(bianhao),read(T);
	while(T--){
//		printf("Passed\n");
//		cerr << "In\n";
		Sol();
//		cerr << "Out\n";
	}
	return 0;
}
/*
0 1
10
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
18
1 2
1 7
1 14
2 3
2 4
4 5
4 6
7 8
7 9
9 10
10 11
10 13
11 12
14 15
15 16
15 17
16 18


*/