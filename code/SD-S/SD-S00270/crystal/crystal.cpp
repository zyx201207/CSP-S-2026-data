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
const int N=5e5+5;
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
int n,m,a[N];
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout) 
signed main(){
	file("crystal");
	read(n,m);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+n+1);
	int ans=0,sum=0,it=1;
	for(int i=1;i<=n;++i){
		sum+=(i-it)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[it++];
		chkmax(ans,i-it+1);
	}
	println(ans);
	return 0;
}
