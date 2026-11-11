#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int man=500005;
ll n,m,a[man],sum[man],ans=0;
bool check(ll x){
	for(int i=1;i<=n-x+1;i++){
		ll now=x*a[i+x-1];now-=(ll)(sum[i+x-1]-sum[i-1]);
		if(now<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;sum[0]=0ll;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=0ll,r=n;
	while(l<=r){
		ll mid=(l+r)/2ll;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
//Oct31==Dec25?