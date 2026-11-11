#include<bits/stdc++.h>
#define ll int64_t
#define endl '\n'
using namespace std;
ll n,m,a[500000+10],sum[500000+10];
bool check(ll x){
	for(ll i=1;i+x-1<=n;i++){
		ll md=i+x-1;
		if(x*a[md]-sum[i+x-1]+sum[i-1]<=m) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}