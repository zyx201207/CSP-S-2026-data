#include<bits/stdc++.h>
#define N 500001
using namespace std;
typedef long long ll;
ll n,m,a[N],s[N];
void input(){
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
}
void solve(){
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,res=i;
		while(l<=r){
			ll mid=(l+r)/2;
			if((i+1-mid)*a[i]-(s[i]-s[mid-1])<=m){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll T=1;
//	scanf("%lld",&T);
	for(ll t=1;t<=T;t++){
		input();
		solve();
	}
	return 0;
}

