#include<bits/stdc++.h>
#define gt getchar
#define pt putchar
#define fst first
#define scd second
#define all(s) s.begin(),s.end()
#define SZ(s) ((int)s.size())
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int N=1e6+5; 
using namespace std;
typedef pair<int,int> pii;
template<class T,class I> inline bool chkmax(T &a,I b){return a<b?a=b,1:0;}
template<class T,class I> inline bool chkmin(T &a,I b){return a>b?a=b,1:0;}
inline bool __(char ch){return ch>=48&&ch<=57;}
template<class T> inline void read(T &x){
	x=0;char ch=gt();bool sgn=0;
	while(!__(ch)) sgn|=(ch=='-'),ch=gt(); 
	while(__(ch)) x=(x<<1)+(x<<3)+(ch&15),ch=gt();
	if(sgn) x=-x;
} 
template<class T,class ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
template<class T> inline void print(T x){
	static char stk[70];int top=0;
	if(x<0) pt('-');
	do{stk[++top]=(x>=0?x%10+48:-(x%10)+48),x/=10;}while(x);
	while(top) pt(stk[top--]);
}
template<class T> inline void printsp(T x){
	print(x);
	putchar(' ');
}
template<class T> inline void println(T x){
	print(x);
	putchar('\n');
}
int c,T,n,k;
struct Edge{
	int to,nxt;
}e[N<<1];
int head[N],cnt;
inline void add_edge(int f,int t){
	e[++cnt].to=t;
	e[cnt].nxt=head[f];
	head[f]=cnt;
}
inline void add_double(int f,int t){
	add_edge(f,t);
	add_edge(t,f); 
}
int h[N],son[N],mx[N];
void dfs(int u,int fa){
	h[u]=son[u]=mx[u]=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		if(h[v]+1>h[u]) mx[u]=h[u],h[u]=h[v]+1,son[u]=v;
		else chkmax(mx[u],h[v]+1);
	} 
}
int lim;
int brute(int u,int fa){
	int ans=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa&&h[v]>=lim) ans+=brute(v,u);
	}
	return ans;
}
int calc(int u,int fa,int w){
	if(max(mx[u],w)+1>lim) return brute(u,fa);
	if(!son[u]) return 0;
	return calc(son[u],u,max(mx[u],w)+1);
}
inline bool check(int mid){
	lim=mid;
	for(int r=1;r<=n;++r){
		dfs(r,0);
		if(calc(r,0,-1e9)<=k) return 1;
		int X=son[r];
		pii mx(-1e9,-1e9);
		for(int i=head[r];i;i=e[i].nxt) chkmax(mx,pii(h[e[i].to],e[i].to));
		if(mx.fst<0) continue;
		int Y=mx.scd,w=-1e9;
		for(int i=head[r];i;i=e[i].nxt) if(e[i].to!=X&&e[i].to!=Y) chkmax(w,h[e[i].to]+1);
		if(w<=mid&&calc(X,r,w)+calc(Y,r,w)<=k) return 1;
	}
	for(int u=1;u<=n;++u){
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			dfs(u,v),dfs(v,u);
			if(calc(u,v,-1e9)+calc(v,u,-1e9)<=k) return 1;
		}
	}
	return 0;
}
inline void solve(){
	read(n,k);
	for(int i=1;i<=n;++i) head[i]=0;
	cnt=0;
	for(int u,v,i=1;i<n;++i){
		read(u,v);
		add_double(u,v);
	}
	int l=0,r=n;
	while(l<r){
		int mid=l+((r-l)>>1);
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	println(l);
}
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout) 
signed main(){
	file("hub");
	read(c,T);
	while(T--) solve();
	return 0;
}
