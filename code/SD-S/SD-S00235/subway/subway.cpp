#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int N = 5e2 + 10  ;
//终于进入T2，正解floyd？？！(做梦 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
int c , n , m , d , q ;//n即为点数（线路） 
int w [ N ] , k [ N ] , klk [ N ] , f [ N ][ N ]  ;
vector <int > id [ N ] ; 
int main ( void )
{
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	cin >> c >> n >> m >> d >> q ;
	int maxx = 0; 
	for ( int i = 1 ; i <= m ; i ++ )
	{
		cin >> w [ i ] ;
		maxx = max ( maxx , w [ i ] ) ;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = 1 ; j <= n ; j ++ )
		{
			if ( i!= j  )
				f [ i ] [ j ] = 1e9 ;
			
		}
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> k [ i ] ;
		for ( int j = 1 ; j <= k [ i ] ; j ++ )
		{
			cin >> klk [ j ] ;
		}
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = 1 ; j <= k [ i ] ; j ++ ){
			for ( int u = 1 ; u <= j ; u ++ )
			{
				f [ klk [ j ] ] [ klk [ u ] ] = w [ i ] ;
				f [ klk [ u ] ] [ klk [ j ] ] = w [ i ] ;
			}
		}
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = 1 ; j <= n ; j ++ )
		{
			cout << f [ i ] [ j ] ;
		}
	}
	for ( int u = 1 ; u <= n ; u ++ )
	{
		
		for ( int i = 1 ; i <= n ; i ++ )
		{
			if ( u == i ) continue ;
			for ( int j = 1 ; j <= i ; j ++ )
			{
				if ( j == i || j == u ) continue ;
				if ( f [ i ] [ u ] + f [ u ] [ j ] < f [ i ] [ j ])
				{
					f [ i ] [ j ] = f [ i ] [ u ] + f [ u ] [ j ] ;
					f [ j ] [ i ] = f [ i ] [ u ] + f [ u ] [ j ] ;
				}
			}
		}
	}
	int ss , tt ;
	while ( q -- )
	{
		cin >> ss >> tt ;
		cout << f [ ss ] [ tt ] <<"\n";
	}
	return 0 ;
}

