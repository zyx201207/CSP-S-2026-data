#include <bits/stdc++.h>
using namespace std;
constexpr int N=500005;
using ll=long long;
ll n,m;
ll a[N],c[N];
ll ans=0;
inline bool check(ll x){
	for(int l=1,r=l+x-1;r<=n;++l,++r){
		if((c[r]-c[l-1]+m>=a[r]*x)&&(c[r]-c[l-1]<=a[r]*x)){
			return true;
		}
	}
//	cout<<"["<<l<<","<<r<<"]"<<":"<<(c[r]-c[l-1]+m)<<' '<<a[r]*(r-l+1)<<'\n';
	return false;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	c[0]=0;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		c[i]=c[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	
	
	cout<<ans<<'\n';
//	cout<<n;
	return 0;
}
