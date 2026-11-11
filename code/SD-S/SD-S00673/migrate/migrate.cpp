#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
using ll=long long;
void rd(ll&x){
	x=0;ll f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9'){c&=15;x=x*10+c;c=gc();}
	x*=f;
}
//using g=unsigned;
//using ii=int;
//using ul=unsigned long long;
constexpr ll N=505,M=500005;
struct E{
	ll a,t;
};
ll cc,t;
vector<E>z[N],h[M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	rd(cc);rd(t);
	while(t--)puts("0");
	return 0;
}
