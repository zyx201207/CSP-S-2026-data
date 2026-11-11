#include<bits/stdc++.h>
#define qvq return 0
using namespace std ;

const long long N = 1e6 + 10 ;

long long n, m, a[N], d[N], f[N], ans ;

long long check( long long x, long long y )
{
	f[x] = 1 ;	d[x] = 0 ;
	for(long long i=x+1, l=x, r=x, tot=1; i<=y; i++)
	{
		while( a[i] - a[l] > m )	tot -= f[l], l++ ;
		if( i == l )	return false ;
		d[i] = d[l] + 1 ;
		while( r < i && d[r+1] <= d[l] )	tot += f[r+1], r++ ;
		f[i] = tot ;
	}
	return f[y] <= 2 ? f[y] : 0 ;
}

signed main()
{
	freopen( "migrate.in", "r", stdin ) ;
	freopen( "migrate.out", "w", stdout ) ;
	
	ios_base::sync_with_stdio( false ) ;
	cin.tie( nullptr ), cout.tie( nullptr ) ;
	
	long long id ;	cin >> id ;
	
	long long qwq ;	cin >> qwq ;
	
	while( qwq-- )
	{
		cin >> n >> m ;
		
		for(long long i=1; i<=n; i++)	cin >> a[i] ;
		
		ans = 0 ;
		
		for(long long i=1; i<=n; i++)
			for(long long j=i+1; j<=n; j++)
			{
				long long t = check( i, j ) ;
				if( !t )	break ;
				ans += t - 1 ;
			}
		
		cout << ans << endl ;
	}
	
	qvq ;
}
//	olD_mOwOn :)