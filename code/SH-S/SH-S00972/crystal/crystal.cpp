#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N];
ll sum[N];
bool chk(ll mid,ll i) {
	ll su=sum[i]-sum[mid-1];
	ll mb=(i-mid+1)*a[i];
	if (su+m>=mb) {
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (ll i=1;i<=n;++i) {
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=1;
	for (ll i=1;i<=n;++i) { //合并到a[i] 
	 	ll lb=1,rb=i;
	 	//把a[mid]~a[i]的水晶合成 
	 	while (lb<=rb) {
	 		ll mid=(lb+rb)/2;
			if (chk(mid,i)) {
	 			ans=max(ans,i-mid+1);
	 			rb=mid-1;
	 		} else {
	 			lb=mid+1;
	 		}
	 	}
	}
	cout<<ans;
	return 0;
}

