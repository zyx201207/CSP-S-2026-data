#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
template<typename T>inline void read(T &x){
	bool f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=(f?-x:x);return;
} 
//template<typename T,typename ...Args>inline void read(T &x,Args &...x_){
//	read(x),read(x_...);
//}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');return;
}
const int N=6e5+10;
int n,m,d,Q,k,w[N],dep[N],fa[N];
struct node{int u,v,nex,num;}e[N<<1];
int head[N],tot;
inline void adds(int u,int v,int num){
	e[++tot]=(node){u,v,head[u],num};
	head[u]=tot;return;
} 
struct Subway{int u,v,num;}edge[N];
bool cmp(Subway x,Subway y){return x.num<y.num;}
inline int finds(int x){
	if(fa[x]==x) return x;
	return fa[x]=finds(fa[x]);
}
inline void unions(int x,int y){
	x=finds(x),y=finds(y);
	if(x==y) return;
	fa[x]=y;return; 
}
long long dis[N][21];
int st[N][21];
inline void Dfs(int u,int lasts){
	st[u][0]=lasts;dep[u]=dep[lasts]+1;
	register int i,v;
	for(i=head[u];i;i=e[i].nex){
		v=e[i].v;
		if(v==lasts) continue;
		dis[v][0]=e[i].num;
		Dfs(v,u);
	}
	return;
}
inline void inits(){
	register int i,j;
	for(j=1;j<=20;j=-~j){
		for(i=1;i<=n+m;i=-~i){
			st[i][j]=st[st[i][j-1]][j-1];
			dis[i][j]=dis[i][j-1]+dis[st[i][j-1]][j-1];
		}
	}
}
inline long long LCA(int x,int y){
	register long long ans=0;
	if(dep[x]<dep[y]) swap(x,y);
	register int i,j;
	for(j=20;j>=0;j=~-j){
		if(dep[st[x][j]]>=dep[y]) ans+=dis[x][j],x=st[x][j];
	}
	for(j=20;j>=0;j=~-j){
		if(st[x][j]!=st[y][j]){
			ans+=dis[x][j]+dis[y][j];
			x=st[x][j],y=st[y][j];
		}
	}
	if(x!=y)ans+=dis[x][0]+dis[y][0];
	//printf("%d %d\n",x,y);
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	register int i,j,c,cnt=0;
	read(c),read(n),read(m),read(d),read(Q);
	for(i=1;i<=m;i=-~i) read(w[i]);
	for(i=1;i<=n;i=-~i){
		read(k);
		for(j=1;j<=k;j=-~j){
			register int a,t;
			read(a);read(t);
			edge[++cnt]=(Subway){m+i,a,t};
		}
	}
	for(i=1;i<=n+m;i=-~i) fa[i]=i;
	sort(edge+1,edge+cnt+1,cmp);cnt=0;i=1;
	while(cnt<n+m-1){
		if(finds(edge[i].u)!=finds(edge[i].v)){
			unions(edge[i].u,edge[i].v);
			adds(edge[i].u,edge[i].v,edge[i].num);
			adds(edge[i].v,edge[i].u,edge[i].num);
			cnt=-~cnt;
	//		printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].num);
		}
		i=-~i;
	}
	Dfs(1,0);
	inits();
 	//printf("%d %d %d\n",st[2][1],st[7][1],dis[5][2]);
	while(Q--){
		register int x,y;
		read(x);read(y);
		write(LCA(x,y)+w[x]+w[y]),putchar('\n');
	} 
	return 0;
}
