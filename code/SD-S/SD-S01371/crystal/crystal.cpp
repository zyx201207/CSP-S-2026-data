#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],f[N],ans;
bool check(ll l,ll r){
	ll t=f[r]-f[l]-(l-1)*(a[r]-a[l]);
	return t<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
