#include <bits/stdc++.h>
using namespace std ;
#define ll long long

ll n, m, ac, mid, acid ;
ll maxx = INT_MIN, minn = INT_MAX ;
ll cnt = 1 ;
vector<ll> a ;
vector<ll> d ;

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	cin >> n >> m ;
	a.resize(n + 1, 0) ;
	d.resize(n + 1, 0) ;

	for ( int i = 1 ; i <= n ; i ++ ) {

		cin >> a[i] ;
		maxx = max ( a[i], maxx ) ;
		minn = min ( a[i], minn ) ;
	}

	double a1 = ( maxx * 1.0 + minn * 1.0 ) / 2 ;
	ll a2 = (maxx + minn) / 2 ;
//	cout << a1 << " " << a2 << "\n" ;

	if ( a1 - a2 >= 0.5 ) {
		mid = a2 + 1 ;
	} else {
		mid = a2 ;
	}

//	cout << mid << "\n" ;
	sort( a.begin() + 1, a.end() ) ;
	ll k, zk = INT_MAX ;

	for ( int i = 1 ; i <= n ; i ++ ) {

		k = abs( a[i] - mid ) ;

		if ( k < zk ) {
			zk = k ;
			ac = a[i] ;
			acid = i ;
		} else {
			break ;
		}
	}

//	cout << ac << " " << acid << "\n" ;
	ll l = acid - 1, r = acid + 1 ;

	while ( m > 0 ) {
		ll rless = abs( a[r] - ac ) ;
		ll lless = abs( ac - a[l] ) ;

		if ( lless <= rless ) {
			if ( a[l] + m >= ac ) {
				m = m - (ac - a[l]) ;
				a[l] = ac ;
				cnt ++ ;

				if ( l - 1 >= 1 ) {
					l -- ;
				}
			} else {
				m -= a[l] ;
			}
		} else {
			if ( a[r] + m >= ac ) {
				m -= abs( ac - a[r] ) ;
				a[r] = ac ;
				cnt ++ ;

				if ( r + 1 <= n ) {
					r ++ ;
				}
			} else {
				m -= a[r] ;
			}
		}

	}

	cout << cnt ;
	return 0 ;
}