#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;
int n, a[N], cnt, m, t[N], ans = INT_MIN, tt, cntt;

bool cmp( int x, int y ) {
	return x > y;
}

signed main() {
	freopen( "crystal.in", "r", stdin );
	freopen( "crystal.out", "w", stdout );

	cin >> n >> m;

	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i];

	stable_sort( a + 1, a + n + 1, cmp );

	// 以谁作为基准
	for ( int i = 1 ; i <= n ; i ++ ) {
		cntt = 1;
		tt = m;
		cnt = 0;
		memset( t, 0, sizeof t );
		for ( int j = i + 1 ; j <= n ; j ++ )
			t[ ++ cnt ] = a[i] - a[j];
		for ( int j = 1 ; j <= cnt ; j ++ ) {
			if ( tt - t[j] >= 0 ) {
				tt -= t[j], cntt ++;
			}
		}
		ans = max( ans, cntt );
	}

	cout << ans << "\n";

	return 0;
}