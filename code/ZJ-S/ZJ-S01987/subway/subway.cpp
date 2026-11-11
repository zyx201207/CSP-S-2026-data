#include<bits/stdc++.h>
#define int long long
//#define ll long long
#define CK_TM cerr<<(double)1.0*abs(&ENDM-&STARTM)/(1024*1024)<<"MB"<<'\n'
bool STARTM;
namespace EVA{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1;
	}
	inline void write(int x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar((x%10)^48);
	}
	inline void spaceput(int x){
		write(x);putchar(' ');
	}
	inline void output(int x){
		write(x);putchar('\n');
	}
}
using namespace EVA;
using namespace std;
const int inf=1e18+6;
const int N=5e2+5;
const int Vmax=2e7+5;
const int M=5e5+5;
const int CT=2e4+5;
const int VVV=1e3+5;
int Case,n,m,d,qask,tot=1;
struct edge{
	int col,to,val,next;
}e[Vmax];
struct node{
	int idx,w;
	inline friend bool operator < (node A,node B){
		return A.w>B.w;
	}
};
int w[M],a[N][CT],k[N];
int dis[M],head[M],t[N][CT];
int ans[VVV][VVV];//i to j min
//int fa[3][M],siz[3][M];
int spja[3][M],spjt[3][M],cst[3][M];
bitset<M> vis;
bitset<M> HZJ,LKH;
vector<int> jad;
priority_queue<node> q;
inline void addedge(int u,int v,int w,int c){
	tot++;e[tot].col=c,e[tot].to=v,e[tot].val=w,e[tot].next=head[u];
	head[u]=tot;
}
inline void dijkstra(int s){
	while(!q.empty()) q.pop();
	for(int i=1;i<=m;i++) dis[i]=inf;
	vis.reset();
	dis[s]=0;q.push({s,0});
	while(!q.empty()){
		int u=q.top().idx;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to,w=e[i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	for(int i=1;i<=m;i++) ans[s][i]=dis[i];
}
inline void spj_0A(){
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++) a[i][j]=read(),t[i][j]=read();
	}
	for(int i=1;i<=n;i++){
		for(int x=1;x<=k[i];x++){
			for(int y=x+1;y<=k[i];y++){
				addedge(a[i][x],a[i][y],t[i][x]+t[i][y],i);
				addedge(a[i][y],a[i][x],t[i][x]+t[i][y],i);
			}
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i); 
	while(qask--){
		int x,y;x=read(),y=read();
		output(ans[x][y]+w[x]+w[y]);
	}
}
inline void spj_n2(){
	int RRR=inf;
	for(int i=1;i<=m;i++) cst[0][i]=cst[1][i]=cst[2][i]=inf;
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++) spja[i][j]=read(),spjt[i][j]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++) cst[i][spja[i][j]]=spjt[i][j];
	}
	for(int j=1;j<=k[1];j++) HZJ[spja[1][j]]=1;
	for(int j=1;j<=k[2];j++) LKH[spja[2][j]]=1;
	for(int i=1;i<=m;i++){
		if(HZJ[i]&&LKH[i]) RRR=min(RRR,cst[1][i]+cst[2][i]);
	}
	while(qask--){
		int x,y;x=read(),y=read();
		output(min(cst[1][x]+cst[1][y],min(cst[2][x]+cst[2][y],min(cst[1][x]+cst[2][y],cst[2][x]+cst[1][y])+RRR)));
	}
//	if(n==2){
//		for(int i=1;i<=m;i++) fa[2][i]=fa[1][i]=i,siz[1][i]=siz[2][i]=1;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<k[i];j++){
//				int x=spja[i][j],y=spja[i][j+1];
//				int A=find(i,x),B=find(y,D);
//			}
//		}
//		
//	}
}
//inline void spj_d2(){
//	cout<<0<<'\n';	
//}
bool ENDM;
signed main(){
//	system("fc subway4.ans subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Case=read(),n=read(),m=read(),d=read(),qask=read();
	for(int i=1;i<=m;i++) w[i]=read();
	if(Case<=19) spj_0A();
//	else if(Case>=12&&Case<=19) spj_B();
//	if(Case<=19) spj_0A();
	else if(Case>=20&&Case<=21) spj_n2();
//	else if(Case>=22&&Case<=23) spj_d2();
//	CK_TM;
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
