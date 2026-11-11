#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<chrono>
#include<cstdio>
#include<random>
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
constexpr int N=5e5+10;
mt19937 rnd(chrono::steady_clock::
	now().time_since_epoch().count());
uniform_int_distribution<int> dist(0,2147483647);
signed main(){
	F(hub);
	int c,t; read(c,t);
	while(t--) write(dist(rnd),'\n');
	return 0;
}
