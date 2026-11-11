#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,t; cin>>c>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		vector<ll> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		ll x=d/(a[1]-a[0]),y=x*2-1;
		ll ans=a[n-1]-a[0]+1-y+1;
		cout<<ans<<"\n";
	}
	return 0;
}