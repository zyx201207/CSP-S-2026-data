#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m, a[200007], d[200007], s[200007];
bool check ( const int &len ) {
	for ( int i = 1; i <= n - len + 1; i++ ) {
		int j = i + len - 1;
		ll sum = s[j] - s[i-1] - d[j] * len;
		if ( sum <= m ) return true;
	}
	return false;
}
int main () {
	freopen ( "crystal.in", "r", stdin );
	freopen ( "crystal.out", "w", stdout );
	scanf ( "%d %lld", &n, &m );
	for ( int i = 1; i <= n; i++ ) scanf ( "%lld", &a[i] );
	sort ( a + 1, a + n + 1 );
	for ( int i = 1; i < n; i++ ) d[i] = a[n] - a[i];
	for ( int i = 1; i <= n; i++ ) s[i] = s[i-1] + d[i];
	int l = 1, r = n + 1;
	while ( l < r ) {
		int mid = l + ( ( r - l ) >> 1 );
		if ( check ( mid ) ) l = mid + 1;
		else r = mid;
	}
	printf ( "%d", l - 1 );
	return 0;
} 
