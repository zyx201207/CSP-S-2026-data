#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500002],s[500002],ans=1;
bool check ( long long l , long long r ) {
	long long ret = ( r - l + 1 ) * a[r] - ( s[r] - s[l-1] ) ;
	return ret <= m ;
}
int main () {
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	cin >> n >> m;
	for ( long long i=1 ; i<=n ; i++ ) cin >> a[i] ;
	sort ( a+1 , a+n+1 ) ;
	for ( long long i=1 ; i<=n ; i++ ) s[i] = a[i] + s[i-1] ;
	for ( long long i=1,j=1 ; i<=n ; i++ ) {
		j = max ( i , j ) ;
		while ( j <= n and check ( i , j ) ) j++;
		ans = max ( ans , j - i ) ;
	}
	cout << ans;
	return 0;
}
