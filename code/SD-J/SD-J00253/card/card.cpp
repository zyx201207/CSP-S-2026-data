# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 1e5 + 7 , MAXM = 3e5 + 7 ;
int n , m , a [ MAXN ] , b [ MAXN ] ;
bool vis [ MAXM ] ;
int lst [ MAXM ] , ans [ MAXM ] ;
bool check ( )
{
	for ( int i = 1 ; i <= n ; ++ i )
	{
		if ( a [ i ] != b [ i ] )
		{
			return 0 ;
		}
	}
	return 1 ;
}
void solve ( )
{
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		cin >> a [ i ] ;
		b [ i ] = a [ i ] ;
	}
	sort ( b + 1 , b + 1 + n ) ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		lst [ a [ i ] ] = i ;
	}
	if ( check ( ) )
	{
		for ( int i = 1 ; i <= m ; ++ i )
		{
			cout << lst [ i ] << ' ' ;
		}
	}
	else
	{
		for ( int i = n ; i >= 1 ; -- i )
		{
			for ( int j = 1 ; j <= m ; ++ j )
			{
				vis [ j ] = 0 ;
			}
			for ( int j = i ; j <= n ; j = lst [ a [ j ] ] + 1 )
			{
				vis [ a [ j ] ] = 1 ;
			}
			for ( int j = 1 ; j <= m ; ++ j )
			{
				ans [ j ] += vis [ j ] ;
			}
		}
		for ( int i = 1 ; i <= m ; ++ i )
		{
			cout << ans [ i ] << ' ' ;
		}		
	}
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "card.in" , "r" , stdin ) ;
	freopen ( "card.out" , "w" , stdout ) ;
	int T = 1 ;
//	cin >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}
