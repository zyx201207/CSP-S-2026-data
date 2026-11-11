#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e6 + 5;
ll x[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c, T;
	cin >> c >> T;
	while(T --){
		ll n, d;
		cin >> n >> d;
		for(ll i = 1;i <= n;i ++) cin >> x[i];
		ll ans = 0;
		if(x[2] - x[1] > d){
			cout << 0 << "\n";
			continue;
		}
		for(ll i = d + 1;i >= 1;i --){
			if((n - i < d && n % 2 == 0) || (n - i <= d && n % 2 != 0)){
				ans += n - i;
			}
			else{
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
