#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

bool vis[ ( int )3e5 + 5 ];
int ans[ ( int )3e5 + 5 ];
int a[ ( int )3e5 + 5 ];

int main() {
	freopen( "card.in", "r", stdin );
	freopen( "card.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	int n, m;
	cin >> n >> m;
	vector<int> arr( n + 1 );
	for ( int i{ 1 }; i <= n; i ++ ) cin >> arr[ i ];
	int p;
	for ( int i{ 1 }; i <= n; i ++ ) {
		p = 0;
		for ( int j{ i }; j <= n; j ++ ) {
			while ( p and vis[ arr[ j ] ] ) {
				p --;
				vis[ a[ p ] ] = false;
			}
			vis[ arr[ j ] ] = true;
			a[ p ++ ] = arr[ j ];
		}
		memset( vis, false, sizeof vis );
		for ( int j{ 0 }; j < p; j ++ ) ans[ a[ j ] ] ++;
	}
	for ( int i{ 1 }; i <= m; i ++ ) cout << ans[ i ] << ' '; 
	return 0;
}
