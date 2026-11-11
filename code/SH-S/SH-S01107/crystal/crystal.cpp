#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll l=0,r=i+1;
		while(l+1!=r){
			ll mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<"\n";
//    freopen("crystal4.ans","r",stdin);
//    ll ac;
//    cin>>ac;
//    cout<<ac;
	return 0;
}
