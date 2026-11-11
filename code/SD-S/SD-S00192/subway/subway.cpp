# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 5e2 + 7 , MAXM = 5e5 ;

struct Node
{
	int to , val ;
	bool friend operator < ( Node x , Node y )
	{
		return x . val > y . val ;
	}
} ;
int w [ MAXM ] ;
int dis [ MAXM + MAXN ] ;
bool vis [ MAXM + MAXN ] ;
priority_queue < Node > que ; 
vector < Node > e [ MAXM + MAXN ] ;
void init ( )
{
	for ( int i = 0 ; i < MAXM + MAXN ; ++ i )
	{
		dis [ i ] = INF ;
		vis [ i ] = 0 ;
	}
	while ( ! que . empty ( ) )
	{
		que . pop ( ) ;
	}
}
void dijkstra ( int s )
{
	que . push ( { s , 0 } ) ;
	dis [ s ] = 0 ;
	while ( ! que . empty ( ) )
	{
		Node u = que . top ( ) ;
		que . pop ( ) ;
		if ( vis [ u . to ] )
		{
			continue ;
		}
		vis [ u . to ] = 1 ;
		for ( auto v : e [ u . to ] )
		{
			if ( dis [ u . to ] + v . val < dis [ v . to ] )
			{
				dis [ v . to ] = dis [ u . to ] + v . val ;
				que . push ( { v . to , dis [ v . to ] } ) ;
			}
		}
	}
	
}
void solve ( )
{
	int c , n , m , d , q ;
	cin >> c >> n >> m >> d >> q ;
	for ( int i = 1 ; i <= m ; ++ i )
	{
		cin >> w [ i ] ;
	}
	for ( int i = 1 , k ; i <= n ; ++ i )
	{
		cin >> k ;
		for ( int j = 1 , a , t ; j <= k ; ++ j )
		{
			cin >> a >> t ;
			e [ a ] . push_back ( { i + m , t } ) ;
			e [ i + m ] . push_back ( { a , t } ) ;
		}
	}
	while ( q -- )
	{
		init ( ) ;
		int x , y ;
		cin >> x >> y ;
		ll ans = w [ x ] + w [ y ] ;
		dijkstra ( x ) ;
		cout << ans + dis [ y ] << '\n' ;
	}
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	int T = 1 ;
//	cin >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}

