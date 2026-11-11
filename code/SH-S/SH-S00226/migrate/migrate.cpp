#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000002],f[302][302],cnt[302][302],ans;
void solve1 () {
	cin >> n >> d;
	for ( long long i=1 ; i<=n ; i++ ) {
		for ( long long j=1 ; j<=n ; j++ ) f[i][j] = 1e18+7 , cnt[i][j] = 0 ;
	}
	for ( long long i=1 ; i<=n ; i++ ) cin >> a[i] ;
	for ( long long i=n ; i>=1 ; i-- ) {
		for ( long long k=i+1 ; k<=n and a[k] - a[i] <= d ; k++ ) {
			f[i][k] = 1 , cnt[i][k] = 1 ;
			for ( long long j=k+1 ; j<=n ; j++ ) {
				if ( f[i][j] > f[i][k] + f[k][j] ) f[i][j] = f[i][k] + f[k][j] , cnt[i][j] = cnt[k][j] ;
				else if ( f[i][j] == f[i][k] + f[k][j] ) cnt[i][j] += cnt[k][j] ;
			}
		}
	}
	ans = 0 ;
	for ( long long i=1 ; i<=n ; i++ ) for ( long long j=1 ; j<=n ; j++ ) if ( cnt[i][j] == 2 ) ans++ ;
	cout << ans << endl;
	return ;
}
void solve2 () {
	cin >> n >> d;
	for ( long long i=1 ; i<=n ; i++ ) cin >> a[i];
	if ( n == 1 ) {
		cout << 0 << endl;
		return ;
	}
	long long c1 = a[2] - a[1] ;
	long long t1 = d / c1 ;
	if ( t1 == 0 or t1 == 1 ) {
		cout << 0 << endl;
		return ;
	}
	t1 = t1 * 2 - 1 ;
	ans = 0 ;
	for ( long long i=1 ; i<=n ; i++ ) if ( i + t1 <= n ) ans++ ;
	cout << ans << endl;
}
int main () {
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout ) ;
	cin >> c >> t;
	while ( t-- ) {
		if ( c <= 6 ) solve1 () ;
		else if ( c == 11 or c == 12 ) solve2 () ;
	}
	return 0;
}
