# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 2e5 + 7 ;

int n , m , a [ MAXN ] ;
bool used [ MAXN ] , used2 [ MAXN ] ;
bool check ( int x )
{
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		used2 [ i ] = used [ i ] ;
	}
	for ( int i = 1 ; i <= n ; ++ i )
	{
		if ( ( ( a [ i ] >> x ) & 1 ) == 1 && used2 [ i ] )
		{
			++ cnt ;
		}
		else
		{
			used2 [ i ] = 0 ;
		}
	}
	if ( cnt >= m )
	{
		for ( int i = 1 ; i <= n ; ++ i )
		{
			used [ i ] = used2 [ i ] ;
		}
		return 1 ;
	}
	return 0 ;
	
}
void solve ( )
{
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		cin >> a [ i ] ;
		used [ i ] = 1 ;
	}
	ll ans = 0 ;
	for ( int i = 30 ; i >= 0 ; -- i )
	{
		if ( check ( i ) )
		{
			ans += ( 1 << i ) ;
		}
	}
	cout << ans << '\n' ;
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
	int T = 1 ;
//	cin >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}
