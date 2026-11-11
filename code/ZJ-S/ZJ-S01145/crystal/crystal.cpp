#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,a[N],sum[N];
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
	ll ans0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,ans;
		while(l<=r){
			ll mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				ans=i-mid+1;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans0=max(ans0,ans);
	}
	cout<<ans0;
	return 0;
}
