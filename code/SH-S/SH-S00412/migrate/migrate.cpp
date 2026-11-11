#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll c,t;
	cin>>c>>t;
	for(ll i=0;i<t;i++){
		ll n,d;
		cin>>n>>d;
		vector<ll> x(n+1);
		vector<bool> vis(n);
		for(ll j=0;j<n;j++){
			cin>>x[j];
		}
		ll ans=x[n-1]/d-(1-x[n-1]%d);
		cout<<ans<<"\n";
	}
	
	return 0;
}
