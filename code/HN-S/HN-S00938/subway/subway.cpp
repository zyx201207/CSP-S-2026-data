#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

int constexpr N = 500 + 5, M = 5e5 + 5, K = M, Q = 1e5 + 5;
int c, n, m, d, q,
	w[ M ], k[ N ], a[ N ][ K ], t[ N ][ K ],
	x[ Q ], y[ Q ];
// t_i_j: 地铁站 a_i_j 的站厅到线路 i 的站台用时
vector<int> roadg[ M ];
int main() {
	freopen( "subway.in", "r", stdin );
	freopen( "subway.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m; ++i ) { cin >> w[ i ]; }
	for ( int i = 1; i <= n; ++i ) {
		cin >> k[ i ];
		for ( int j = 1; j <= k[ i ]; ++j )
		{ cin >> a[ i ][ j ] >> t[ i ][ j ]; }
	}
	for ( int r = 1; r <= q; ++r )
	{ cin >> x[ r ] >> y[ r ]; }

	for ( int road = 1; road <= m; ++road ) {
		for ( int i = 2; i < k[ road ]; ++i ) {
			int u = a[ road ][ i - 1 ], v = a[ road ][ i ];
			roadg[ u ].push_back( v );
			roadg[ v ].push_back( u );
		}
	}

	for ( int r = 1; r <= q; ++r ) {
		ll ans = w[ x[ r ] ] + w[ y[ r ] ];
		
		cout << ans << '\n';
	}
	return 0;
}

