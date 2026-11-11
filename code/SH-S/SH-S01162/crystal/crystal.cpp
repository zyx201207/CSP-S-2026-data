#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const bool AC=true;
const ll INF=1e18;

void solve(){
	ll n,m;
	cin>>n>>m;
	ll sum[n+5],d[n+5];
	for (ll i=1;i<=n;i++){
		cin>>sum[i];
	}
	sort(sum+1,sum+n+1);
	for (ll i=2;i<=n;i++){
		d[i-1]=sum[i]-sum[i-1];
	}
	ll ans=0;
	for (ll i=1;i<n;i++){
		ll m1=m;
		for (ll j=i;j<n;j++){
			m1-=(j-i+1)*d[j];
			if (m1<0){
				ans=max(ans,j-i+1);
				//cout<<ans<<'\n';
				break;
			}
		}if (m1>0){
				ans=max(ans,n-i+1);

			}
		if (ans>=n-i){
			cout<<ans;
			return ;
		}
	}cout<<ans;
	return ;
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
