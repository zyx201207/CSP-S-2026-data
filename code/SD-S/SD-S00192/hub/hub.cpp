# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 1e3 + 7 ;

vector < int > e [ MAXN ] ;
vector < int > node ;
bool used [ MAXN ] ;
int scc [ MAXN ] ;
int dis [ MAXN ] [ MAXN ] ;
void init ( )
{
	node . clear ( ) ;
	for ( int i = 0 ; i < MAXN ; ++ i )
	{
		e [ i ] . clear ( ) ;
		used [ i ] = 0 ;
		scc [ i ] = 0 ;
		for ( int j = 0 ; j < MAXN ; ++ j )
		{
			if ( i == j ) dis [ i ] [ j ] = 0 ;
			else dis [ i ] [ j ] = INF ;
		}
	}
}
void init2 ( )
{
	node . clear ( ) ;
	for ( int i = 0 ; i < MAXN ; ++ i )
	{
		used [ i ] = 0 ;
		scc [ i ] = 0 ;
	}
}
void dfs ( int u , int fa , int k )
{
	if ( used [ u ] )
	{
		scc [ u ] = k ;
	}
	else
	{
		return ;
	}
	for ( auto v : e [ u ] )
	{
		if ( v == fa )
		{
			continue ;
		}
		dfs ( v , u , k ) ;
	}
}
bool check ( )
{
	int k = 0 ;
	for ( auto i : node )
	{
		if ( ! scc [ i ] )
		{
			dfs ( i , 0 , ++ k ) ;
		}
	}
	return ( k <= 2 ) ;
}
void solve ( )
{
	init ( ) ;
	int n , k ;
	cin >> n >> k ;
	for ( int i = 1 ; i < n ; ++ i )
	{
		int u , v ;
		cin >> u >> v ;
		e [ u ] . push_back ( v ) ;
		e [ v ] . push_back ( u ) ;
		dis [ u ] [ v ] = dis [ v ] [ u ] = 1 ;
	}
	for ( int k_ = 1 ; k_ <= n ; ++ k_ )
	{
		for ( int i = 1 ; i <= n ; ++ i )
		{
			for ( int j = 1 ; j <= n ; ++ j )
			{
				dis [ i ] [ j ] = min ( dis [ i ] [ j ] , dis [ i ] [ k_ ] + dis [ k_ ] [ j ] ) ;
			}
		}
	}
	int ans = INF ;
	for ( int i = 0 ; i < ( 1ll << n ) ; ++ i )
	{
		init2 ( ) ;
		if ( __builtin_popcount ( i ) == k )
		{
			for ( int j = 0 ; j < n ; ++ j )
			{
				if ( ( ( i >> j ) & 1 ) == 1 )
				{
					used [ j + 1 ] = 1 ;
					node . push_back ( j + 1 ) ;
				}
			}
			if ( check ( ) )
			{
				int maxn = - INF ;
				for ( int j = 1 ; j <= n ; ++ j )
				{
					int minn = INF ;
					for ( auto u : node )
					{
						minn = min ( minn , dis [ j ] [ u ] ) ;
					}
					maxn = max ( maxn , minn ) ;
				}
				ans = min ( ans , maxn ) ;
			}
		}
	}
	cout << ans << '\n' ;
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "hub.in" , "r" , stdin ) ;
	freopen ( "hub.out" , "w" , stdout ) ;
	int C , T = 1 ;
	cin >> C >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}

