#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],sum[500010],ans;
bool check(ll mid,ll x){
	if(mid*a[x]-(sum[x]-sum[x-mid])<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll l=0,r=i+1;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(check(mid,i)) l=mid;
			else r=mid;
		}
		ans=max(ans,l);
	}
	printf("%lld",ans);
	return 0;
}
