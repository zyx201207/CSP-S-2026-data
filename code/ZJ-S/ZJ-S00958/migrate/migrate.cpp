#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		
			ll ans=0;
			int b=d/(x[2]-x[1]);
			for(int i=1;i<=n;++i){
				ans+=n-i-(n-i)/b;
			}
			cout<<ans;
			break;
	}
	return 0;
}