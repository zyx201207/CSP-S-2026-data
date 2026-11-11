#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll s[500005];
ll query(ll l,ll r){
	return s[r]-s[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		ll ans1=0;
		while(l<=r){
			ll mid=(l+r)/2;
			ll c=a[i]*(i-mid+1)-query(mid,i);
			if(c<=m){
				r=mid-1;
				ans1=max(ans1,i-mid+1);
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
