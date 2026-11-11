#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#define F(s) freopen(#s ".in","r",stdin);\
	freopen(#s ".out","w",stdout)
using namespace std;
namespace FastIO{
	#ifdef __linux__
	#define gc getchar_unlocked
	#define pc putchar_unlocked
	#else
	#define gc _getchar_nolock
	#define pc _putchar_nolock
	#endif
	inline bool blank(char x){
		return !(x^32)||!(x^10)||!(x^13)||!(x^9);
	}
	template<typename Tp>
	inline void read(Tp& x){
		x=0;
		bool f=true;
		char ch=gc();
		for(;!isdigit(ch);ch=gc())
			if(ch=='-') f=false;
		for(;isdigit(ch);ch=gc())
			x=(x<<1)+(x<<3)+(ch^48);
		x=(f?x:~x+1);
	}
	inline void read(char& x){
		for(x=gc();blank(x)&&(x^-1);x=gc());
	}
	inline void read(char* x){
		char ch=gc();
		for(;blank(ch)&&(ch^-1);ch=gc());
		for(;!blank(ch)&&(ch^-1);ch=gc())
			*x++=ch;
		*x=0;
	}
	inline void read(string& x){
		x="";
		char ch=gc();
		for(;blank(ch)&&(ch^-1);ch=gc());
		for(;!blank(ch)&&(ch^-1);ch=gc())
			x+=ch;
	}
	template<typename T,typename... Tp>
	inline void read(T& x,Tp&... y){read(x),read(y...);}
	template<typename Tp>
	inline void write(Tp x){
		if(!x) return pc(48),void();
		if(x<0) pc('-'),x=~x+1;
		int len=0; char tmp[64];
		for(;x;x/=10) tmp[++len]=x%10^48;
		while(len) pc(tmp[len--]);
	}
	inline void write(const char x){pc(x);}
	inline void write(const bool x){pc(x?49:48);}
	inline void write(char* x){fputs(x,stdout);}
	inline void write(const char* x){fputs(x,stdout);}
	inline void write(const string& x){fputs(x.c_str(),stdout);}
	template<typename T,typename... Tp>
	inline void write(T x,Tp... y){write(x),write(y...);}
}
using namespace FastIO;
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=5.5e5+10;
struct Edge{ll v,w;};
vector<Edge> e[N];
ll c,n,m,w[N];
struct Heap{
	ll d;
	int id;
	bool operator <(Heap b)const{
		return d>b.d;
	}
};
priority_queue<Heap> q;
bitset<N> vis;
ll d[N];
inline void dij(int s){
	memset(d,0x3f,(n+m+1)*sizeof(ll));
	while(!q.empty()) q.pop();
	vis=d[s]=0,q.push({0,s});
	while(!q.empty()){
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(Edge to:e[u]){
			int v=to.v,w=to.w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
int dep[N],fa[N][20];
inline void bfs(int s){
	queue<int> q;
	d[s]=0,dep[s]=1,vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(Edge to:e[u]){
			int v=to.v,w=to.w;
			if(!vis[v]){
				d[v]=d[u]+w;
				dep[v]=dep[u]+1;
				fa[v][0]=u;
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
inline void func(){
	for(int i=1;i<19;i++)
		for(int j=1;j<=n+m;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=18;i;i--)
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=18;i;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
signed main(){
	F(subway);
	int q;
	read(c,n,m,q,q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1,x;i<=n;i++){
		read(x); int u=i+m;
		for(int j=1,v,w;j<=x;j++)
			read(v,w),
			e[u].emplace_back(Edge{v,w}),
			e[v].emplace_back(Edge{u,w});
	}
	if(12<=c&&c<=19){
		bfs(1);
		func();
		int x,y;
		while(q--){
			read(x,y);
			write(w[x]+w[y]+d[x]+d[y]-(d[LCA(x,y)]<<1),'\n');
		}
		return 0;
	}
	int x,y;
	while(q--){
		read(x,y); dij(x);
		write(w[x]+w[y]+d[y],'\n');
	}
	return 0;
}
