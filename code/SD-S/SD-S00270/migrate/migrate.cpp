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
#define int long long
const int N=2e6+5;
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
int c,T,n,d,a[N],f[N][2],coef[N][2],suf[N];
inline void solve(){
	read(n,d);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int _:{0,1}){
		for(int j=n,i=n;i;--i){
			while(a[j]-a[i]>d) j--;
			suf[i]=j;
		}
		for(int i=n;i;--i){
			f[i][0]=f[i][1]=0;
			if(suf[i]>i) f[i][0]=suf[i]-i+f[suf[i]][suf[i]>i+1];
			int p=max(suf[i-1],i);
			if(suf[i]>p) f[i][1]=suf[i]-p+f[suf[i]][suf[i]>i+1];
		}
		for(int i=1;i<n;++i) coef[i][_]=max(0ll,suf[i]-max(i+1,suf[i-1]))+(suf[i+1]==suf[i]&&suf[i]>suf[i-1])*f[suf[i+1]][suf[i+1]>i+2];
		reverse(a+1,a+n+1);
		for(int i=1;i<=n;++i) a[i]*=-1;
	}
	int ans=0;
	for(int i=1;i<n;++i) ans+=coef[i][0]*coef[n-i][1];
	println(ans);
}
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout) 
signed main(){
	file("migrate");
	read(c,T);
	while(T--) solve();
	return 0;
}
