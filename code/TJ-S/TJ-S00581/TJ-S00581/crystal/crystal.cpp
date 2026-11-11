#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll arr[ ( int )5e5 + 5 ];
ll diff[ ( int )5e5 + 5 ];
int n;
ll m;

bool check( int x ) {
	ll dif{ 0 };
	for ( int i{ 1 }; i < x; i ++ ) dif += arr[ x ] - arr[ i ];
	return ( dif <= m );
}

int main() {
	freopen( "crystal.in", "r", stdin );
	freopen( "crystal.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	cin >> n >> m;
	for ( int i{ 1 }; i <= n; i ++ ) {
		cin >> arr[ i ];
	}
	sort( arr + 1, arr + 1 + n );
	int l{ 1 }, r{ n };
	while ( l < r ) {
		int mid{ ( l + r + 1 ) >> 1 };
		if ( check( mid ) ) l = mid;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
