#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		ll m = n/2;
		if(m % 2 == 0){
			ll ans = max(0LL,m/2-k/2+1);
			if(ans >= 1)cout << ans/2+1 << endl;
			else{
				if(k == n)cout << ans/2+1 << endl;
				else cout << 1 << endl;
			}
		}
		else{
			ll ans = max(0LL,m/2-(k-1)/2+1);
			if(ans >= 1)cout << ans/2+1 << endl;
			else{
				if(k == n)cout << ans/2+1 << endl;
				else cout << 1 << endl;
			}
		}		
	}

	return 0;
}

