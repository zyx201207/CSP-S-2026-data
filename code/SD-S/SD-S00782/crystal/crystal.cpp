#include <bits/stdc++.h>


using namespace std ; 
using ll = long long ; 

const int N = 6e5 ; 
int n ; 
ll m, a[N] ; 
ll h[N] ; 
int main() {
	ios::sync_with_stdio(0) ; 
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	
	cin >> n >> m ; 
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] ; 
	}
	sort(a+1, a+n+1) ; 
	h[1] = 0 ;

	for (ll i = 2; i <= n; i ++) {
		h[i] = h[i-1] + (a[i] - a[i-1]) * (i - 1) ; 
	}
	
	int l = 1, r = 1, ans = -1 ; 
	while (1) {
		if (l > n || r > n) {
			break ; 
		}
		ll cost = h[r] - h[l] - (a[r] - a[l]) * (l - 1); //////////
		if (cost <= m) {	
			if (ans < (r - l + 1)) {
				ans = (r - l + 1) ; 
			}
			r ++ ; 
		} else if (cost > m){
			l ++ ;
		}
	}
	
	cout << ans ; 
	return 0 ; 
}
