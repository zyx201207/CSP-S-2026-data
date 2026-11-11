#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],dp[500005],ans=1;
bool check(ll x){
	ll lz=2e9;
	for(ll i=x;i<=n;i++){
		ll cost=a[i]*(x-1)-(dp[i-1]-dp[i-x]);
		lz=min(lz,cost);
	}
	return lz<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)dp[i]=dp[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
