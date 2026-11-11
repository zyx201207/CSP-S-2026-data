#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<cmath>
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
constexpr int N=5e5+10;
ll n,m,a[N],sum[N];
inline int que(int x){
	int l=1,r=x-1;
	while(l<r){
		int mid=l+r>>1;
		ll res=sum[mid]-sum[x]-(x-mid)*(a[n]-a[x]);
		if(res<=m) r=mid;
		else l=mid+1;
	}
	return x-l+1;
}
signed main(){
	F(crystal);
	read(n,m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(int i=n-1;i>0;i--)
		sum[i]=sum[i+1]+a[n]-a[i];
	int maxx=0;
	for(int i=1;i<=n;i++)
		maxx=max(maxx,que(i));
	write(maxx);
	return 0;
}
