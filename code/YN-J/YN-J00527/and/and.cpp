#include <bits/stdc++.h>
using namespace std ;
#define ll long long

ll n, m ;
ll ans = -1 ;
vector<ll> a ;

void dfs( ll cnt, ll sum ) {
	if ( cnt == m + 1 ) {
		ans = max ( ans, sum ) ;
		return ;
	}

	for ( auto c : a ) {
		if ( cnt == 1 && c == sum ) {
			continue ;
		} else {
			ll k = sum & c ;
			dfs( cnt + 1, k ) ;
		}
	}
}

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen("and.in", "r", stdin) ;
	freopen("and.out", "w", stdout) ;
	cin >> n >> m ;

	for ( int i = 1 ; i <= n ; i ++ ) {

		ll x ;
		cin >> x ;
		a.push_back(x) ;
	}

	for ( auto z : a ) {
		dfs( 1, z ) ;
	}

	cout << ans ;
	return 0 ;
}