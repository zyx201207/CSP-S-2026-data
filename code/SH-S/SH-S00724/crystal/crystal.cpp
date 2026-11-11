#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500010],s[500010],k;
bool check(ll lb,ll rb){
	ll xx=s[rb]-s[lb-1],v=a[rb]*(rb-lb+1);
	if(v-xx<=k)	return true;
	else	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<=n;++i){
		ll l=1,r=i;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,i))	r=mid-1;
			else	l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
