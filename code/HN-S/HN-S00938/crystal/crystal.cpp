#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int constexpr N = 5e5 + 5;
int n;
ll m, a[ N ], prefix[ N ];

int find_index() {
	for ( int ans = n; ans; --ans ) {
		if ( ans * a[ ans ] - prefix[ ans ] <= m )
		{ return ans; }
	}
	return 1;
}

int max_segment_len() {
	int l = 1, r = 1, ans = 0;
	while ( l <= n && r <= n ) {
		while ( r <= n && a[ r ] == a[ l ] ) { ++r; }
		ans = max( ans, r - l );
		l = r;
	}
	return ans;
}

int main() {
	freopen( "crystal.in", "r", stdin );
	freopen( "crystal.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	cin >> n >> m;
	for ( int i = 1; i <= n; ++i ) { cin >> a[ i ]; }
	sort( a + 1, a + n + 1 );
	prefix[ 0 ] = 0;
	for ( int i = 1; i <= n; ++i )
	{ prefix[ i ] = prefix[ i - 1 ] + a[ i ]; }
	cout << max( find_index(), max_segment_len() ) << '\n';
	return 0;
}

