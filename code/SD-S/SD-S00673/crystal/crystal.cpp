#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
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
constexpr ll N=500005;
ll n,m,l,r,md,o,oo,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	rd(n);rd(m);
	for(ll i=1;i<=n;++i){rd(a[i]);}
//	printf("%lld",a[1]);
	stable_sort(a+1,a+n+1,[](ll i,ll j){return i>j;});
	for(ll i=1;i<=n;++i){s[i]=a[i]+s[i-1];}
	for(ll i=1;i<=n;++i){
		l=i;r=n;
		while(l<=r){
			md=(l+r)/2;
			if(a[i]*(md-i+1)-(s[md]-s[i-1])<=m){
				o=md-i+1;
				l=md+1;
			}else r=md-1;
		}if(o>oo)oo=o;
//		fprintf(stderr,"%lld %lld\n",a[i]*(md-i+1),(s[md]-s[i-1]));
	}printf("%lld",oo);
	return 0;
}
