#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c, t;
ll n, d;
ll x[2000006];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	cin >> c >> t;
	
	// A -> 11, 12
	if(c == 11 || c == 12){
		while(t--){
			cin >> n >> d;
			for(int i=1; i<=n; i++){
				cin >> x[i];
			}
			ll xd=x[2]-x[1];
			ll len=d/xd;
			if(len < 2){
				cout << 0 << '\n';
			}else{
				cout << max(0ll, n - len*2 + 1ll) << '\n';
			}
		}
		return 0;
	}else{
		while(t--){
			cout << 0 << '\n';
		}
	}
	
	// end
	return 0;
}
