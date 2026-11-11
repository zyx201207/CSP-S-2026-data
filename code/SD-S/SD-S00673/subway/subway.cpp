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
constexpr ll N=505,M=500005;
struct E{
	ll a,t;
};
ll cc,n,m,dd,q,w[M],K,x,y,md,o,oo,a[N],s[N],d[N][N];
vector<E>z[N],h[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,63,sizeof d);
	rd(cc);rd(n);rd(m);rd(dd);rd(q);
	for(ll i=1;i<=m;++i){rd(w[i]);}
	for(ll i=1;i<=n;++i){
		rd(K);
		z[i].resize(K);
		for(E&j:z[i]){
			rd(j.a);rd(j.t);//z line : station,time
			h[j.a].push_back({i,j.t});//h station . line,time
		}
	}
	for(ll i=1;i<=n;++i)d[i][i]=0;
	for(ll i=1;i<=m;++i){//dd<=20
		for(E&j:h[i]){
		for(E&k:h[i]){
			if(j.a==k.a)continue;
			d[j.a][k.a]=d[k.a][j.a]=min(d[j.a][k.a],j.t+k.t);//d=min mid
		}}//change mid
	}
	for(ll k=1;k<=n;++k)
	for(ll i=1;i<=n;++i)
	for(ll j=1;j<=n;++j){
//		if(k==i||i==j||j==k)continue;
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
	for(ll i=1;i<=q;++i){
		rd(x);rd(y);o=0x3f3f3f3f3f3f3f3fll;
		if(x==y){
			puts("0");
			continue;
		}
		for(E&j:h[x]){//dd<=20
		for(E&k:h[y]){
			o=min(o,d[j.a][k.a]+j.t+k.t);//in_line+out_line+mid
		}}
		printf("%lld\n",w[x]+w[y]+o);//in_station+out_station+mid
	}
	return 0;
}
