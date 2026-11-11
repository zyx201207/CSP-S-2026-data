#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll n,m,a[MAXN],sum[MAXN],ans=INT_MIN;
bool check(ll k){
	for(int i=k;i<=n;i++){
		if(k*a[i]-sum[i]+sum[i-k]<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}