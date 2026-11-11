#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n;
ll a[N];
ll m;
ll s[N];
bool check(ll x){
	for(ll i=1;i<=n-x+1;i++){
		ll j=i+x-1;
		ll nd=s[j]-s[i-1];
		nd=(ll)(j-i+1)*a[j]-nd;
		if(nd<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll l=1,r=n;
	ll ans=1;
	while(l<=r){
		ll mid=(l+r>>1);
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//orange