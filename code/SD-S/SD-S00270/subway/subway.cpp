#include<bits/stdc++.h>
#define gt getchar
#define pt putchar
#define fst first
#define scd second
#define eb emplace_back
#define all(s) s.begin(),s.end()
#define SZ(s) ((int)s.size())
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int N=5e5+5;
const int M=505;
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
int c,n,m,d,q,w[N];
vector<pii> ed[N];
vector<int> vc[N];
ll f[M][M];
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout) 
signed main(){
	file("subway");
	read(c,n,m,d,q);
	for(int i=1;i<=m;++i) read(w[i]);
	for(int k,i=1;i<=n;++i){
		read(k);
		vc[i].resize(k);
		for(int x,j=0;j<k;++j){
			read(vc[i][j],x);
			ed[vc[i][j]].eb(i,x);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int u:vc[i]){
			ll mn=1e18;
			for(auto x:ed[u]) if(x.fst==i) chkmin(mn,x.scd);
			for(auto x:ed[u]) chkmin(f[i][x.fst],mn+x.scd);
		}
	}
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) chkmin(f[i][j],f[i][k]+f[k][j]);
	for(int x,y;q;--q){
		read(x,y);
		ll ans=1e18;
		for(auto A:ed[x]) for(auto B:ed[y]) chkmin(ans,f[A.fst][B.fst]+A.scd+B.scd);
		println(ans+w[x]+w[y]);
	}
	return 0;
}
