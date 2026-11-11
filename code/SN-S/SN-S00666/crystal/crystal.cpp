#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],sum[N],ans;
bool check(ll x,ll y){
	ll cnt=a[y]*(y-x+1)-(sum[y]-sum[x-1]);
	if(cnt<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,k=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				k=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	
	return 0;
}
