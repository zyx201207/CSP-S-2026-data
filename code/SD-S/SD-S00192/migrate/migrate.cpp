# include <bits/stdc++.h>
# define int long long
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 5e3 + 7 ;

int x [ MAXN ] ;
int dis [ MAXN ] , cnt [ MAXN ] ;
bool vis [ MAXN ] ;
vector < int > e [ MAXN ] ;
queue < int > q ;
void init ( )
{
	for ( int i = 0 ; i < MAXN ; ++ i )
	{
		x [ i ] = 0 ;
		e [ i ] . clear ( ) ;
	}
}
void init2 ( )
{
	for ( int i = 0 ; i < MAXN ; ++ i )
	{
		dis [ i ] = INF ;
		vis [ i ] = 0 ; 
	}
	while ( ! q . empty ( ) ) 
	{
		q . pop ( ) ; 
	}
}
void dijkstra ( int s )
{
	q . push ( s ) ;
	dis [ s ] = 0 ;
	cnt [ s ] = 1 ;
	while ( ! q . empty ( ) )
	{
		int u = q . front ( ) ;
		q . pop ( ) ;
		if ( vis [ u ] )
		{
			continue ;
		}
		vis [ u ] = 1 ;
		for ( auto v : e [ u ] )
		{
			if ( dis [ u ] + 1 == dis [ v ] )
			{
				cnt [ v ] += cnt [ u ] ;
			}
			if ( dis [ u ] + 1 < dis [ v ] )
			{
				dis [ v ] = dis [ u ] + 1 ;
				cnt [ v ] = cnt [ u ] ;
				q . push ( v ) ;
			}
		}
	}
}
void solve ( )
{
	init ( ) ;
	int n , d ;
	cin >> n >> d ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		cin >> x [ i ] ;
	}
	for ( int i = 1 ; i <= n ; ++ i )
	{
		for ( int j = i + 1 ; j <= n ; ++ j )
		{
			if ( x [ j ] - x [ i ] <= d )
			{
				e [ i ] . push_back ( j ) ;
				e [ j ] . push_back ( i ) ;
			}
		}
	}
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		init2 ( ) ;
		dijkstra ( i ) ;
		for ( int j = i + 1 ; j <= n ; ++ j )
		{
			if ( cnt [ j ] == 2 )
			{
				++ ans ;
			}
		}
		
	}
	cout << ans << '\n' ;
}

signed main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout ) ;
	int C , T = 1 ;
	cin >> C >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}

