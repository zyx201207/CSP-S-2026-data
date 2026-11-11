#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,m;
ll a[N];
ll qpow(ll x,ll y){
	ll res=1ll;
	while(y){
		if(y&1) res*=x;
		x*=x;
		y/=2;
	}
	return res;
}
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	ll ans=qpow(2,31)-1;
	for(ll i=1;i<=m;++i)
		ans=ans&a[i];
	printf("%lld",ans);
	return 0;
}

