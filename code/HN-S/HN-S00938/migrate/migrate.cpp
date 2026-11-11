#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int constexpr N = 2e6 + 5;
ll x[ N ];

int main() {
	freopen( "migrate.in", "r", stdin );
	freopen( "migrate.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	int c, t; cin >> c >> t;
	while ( t-- ) {
		int n, d; cin >> n >> d;
		for ( int i = 1; i <= n; ++i ) { cin >> x[ i ]; }
		ll ans = 0;
		for ( int u = 1; u <= n; ++u ) {
			for ( int v = u + 2; v <= n; ++v ) {
				vector<int> path1;
				path1.push_back( u );
				int l = u, r = l;
				while ( l <= v && r <= v ) {
					while ( r <= v && abs( x[ r ] - x[ l ] ) <= d )
					{ ++r; }
					path1.push_back( r - 1 );
					l = r;
				}
				
				vector<int> path2;
				path2.push_back( v );
				l = v, r = l;
				while ( l >= u && r >= u ) {
					while ( r >= u && abs( x[ r ] - x[ l ] ) <= d )
					{ --r; }
					path2.push_back( r + 1 );
					l = r; 
				}
				reverse( path2.begin(), path2.end() );
				if ( path1 == path2 ) { ++ans; }
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

