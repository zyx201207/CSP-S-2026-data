#include<bits/stdc++.h>
#define ll long long
const ll N=5e5+100;
using namespace std;
ll n,m;
ll a[N],b[N];
bool check(ll x){
	for(ll i=1;i+x-1<=n;i++){
		ll top=x*a[i+x-1];
		ll has=b[i+x-1]-b[i-1];
		if(top-has<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	ll l=1,r=n;
	ll best=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			best=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",best);
	return 0;
} 
