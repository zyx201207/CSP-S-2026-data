#include<bits/stdc++.h>
#define qvq return 0
using namespace std ;

const int N = 1e6 + 10 ;

long long n, m, ans, a[N] ;

signed main()
{
	freopen( "crystal.in", "r", stdin ) ;
	freopen( "crystal.out", "w", stdout ) ;
	
	ios_base::sync_with_stdio( false ) ;
	cin.tie( nullptr ), cout.tie( nullptr ) ;
	
	cin >> n >> m ;
	
	for(int i=1; i<=n; i++)	cin >> a[i] ;
	
	sort( a + 1, a + 1 + n ) ;
	
	for(long long i=1, l=1, tot=0; i<=n; i++)
	{
		tot += ( i - l ) * ( a[i] - a[i-1] ) ;
		while( tot > m )	tot -= a[i] - a[l], l++ ;
		ans = max( ans, i - l + 1 ) ;
	}
	
	cout << ans << endl ;
	
	qvq ;
}
//	olD_mOwOn :)