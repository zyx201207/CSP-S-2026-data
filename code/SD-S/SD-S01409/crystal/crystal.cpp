#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,best=-1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m){
				best=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		if(best!=-1)ans=max(ans,i-best+1);
	}
	printf("%lld\n",ans);
	return 0;
} 
