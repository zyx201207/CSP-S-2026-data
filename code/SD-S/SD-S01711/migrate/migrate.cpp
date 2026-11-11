#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 _int;
typedef unsigned char uc;
typedef unsigned int ui;
char buf[1000010],obuf[1000010],*p1,*p2,*p3=obuf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf,1,1000000,stdout),*p3++=x)
int read(){
	int x=0;
	bool f=1;
	char c=gc();
	while(c<48||c>57){
		if(c=='-'){
			f=0;
		}
		c=gc();
	}
	while(c>47&&c<58){
		x=(x<<3)+(x<<1)+(c&15);
		c=gc();
	}
	return f?x:-x;
}
ll lread(){
	ll x=0;
	bool f=1;
	char c=gc();
	while(c<48||c>57){
		if(c=='-'){
			f=0;
		}
		c=gc();
	}
	while(c>47&&c<58){
		x=(x<<3)+(x<<1)+(c&15);
		c=gc();
	}
	return f?x:-x;
}
template<typename Tp>
void write(Tp x){
	if(x<0){
		pc('-');
		x=-x;
	}
	static char stk[40];
	int top=0;
	do{
		stk[top++]=x%10|48;
	}while(x/=10);
	while(top--){
		pc(stk[top]);
	}
}
template<typename Tp,typename Tp2>
void chmin(Tp&x,const Tp2&y){
	if(y<x){
		x=y;
	}
}
template<typename Tp,typename Tp2>
void chmax(Tp&x,const Tp2&y){
	if(x<y){
		x=y;
	}
}
namespace AIMAT{
	const int N=2.01e6;
	ll a[N];
	void main(){
		int n=read();
		ll d=lread();
		for(int i=1;i<=n;++i){
			a[i]=lread();
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();
	int testcase=read();
	while(testcase--){
		AIMAT::main();
	}
	fwrite(obuf,1,p3-obuf,stdout);
	return 0;
}
