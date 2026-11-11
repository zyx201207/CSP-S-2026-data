#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int a[ ( int )2e5 + 5 ];
bool vis[ ( int )2e5 + 5 ];
int n, m;

int dfs( int i, int count, int ans ) {
	if ( count ) {
		int Max{ 0 }, k;
		for ( int j{ i + 1 }; j <= n; j ++ ) {
			if ( vis[ j ] ) continue;
			if ( ( ans & a[ j ] ) > Max ) {
				Max = ( ans & a[ j ] );
				k = j;
			} 
		}
//		cout << a[ k ] << ' ';
		vis[ k ] = true;
		dfs( i, count - 1, Max );
	} else return ans;
}

int main() {
	freopen( "and.in", "r", stdin );
	freopen( "and.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	cin >> n >> m;
	for ( int i{ 1 }; i <= n; i ++ ) cin >> a[ i ];
	if ( n == m ) {
		int ans{ a[ 1 ] };
		for ( int i{ 2 }; i <= n; i ++) ans &= a[ i ];
		cout << ans << endl;
		return 0;
	} 
	int ans{ 0 }; 
	for ( int i{ 1 }; i <= n - m + 1; i ++ ) {
		ans = max( ans, dfs( i, m - 1, a[ i ] ) );
		memset( vis, false, sizeof vis );
	}
	cout << ans << endl;
	return 0;
}
