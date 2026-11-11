#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m, mx = -1, nm, ans = -1;
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	a[0] = 0;
	nm = a[1];
	for(int i = 2; i <= n; i++){
		nm &= a[i];
	}
	if(m == 1){
		cout << mx;
		return 0;
	}
	if(m == n){
		cout << nm;
		return 0;
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = i + 1; j <= n; j++){
			if(m == 2){
				ans = max(ans, a[i] & a[j]);
			}
			for(ll k = j + 1; k <= n; k++){
				if(m == 3){
					ans = max(ans, a[i] & a[j] & a[k]);
				}
				for(ll l = k + 1; l <= n; l++){
					if(m == 4){
						ans = max(ans, a[i] & a[j] & a[k] & a[l]);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
