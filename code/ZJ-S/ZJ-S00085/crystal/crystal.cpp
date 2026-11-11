#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],suma[N];
bool check(ll num){
	for(ll i=num;i<=n;i++){
		if(a[i]*num-(suma[i]-suma[i-num])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		suma[i]=suma[i-1]+a[i];
	}
	ll l=1,r=n,ans=1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
