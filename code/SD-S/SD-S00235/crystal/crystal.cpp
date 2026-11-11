#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int N = 5e5 + 10 ; 

int n ;
ll m ;
ll diam [ N ] , cha [ N ] , qian [ N ] ;
queue < int > q ;
int main ( void )
{
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	cin >> n >> m ;
	for ( int i = 1; i <= n ; i ++ )
	{
		cin >> diam [ i ] ;
	}
	sort ( diam + 1 , diam + 1 + n ) ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cha [ i ] = diam [ i ] - diam [ i - 1 ] ;
	}
	int anss = 0 ;
	int maxx = 1 ;
	ll sheng = m;
	int t = 1 ;
	for ( int l = 1 , r = 2 ; l <= r && r <= n ; )
	{
		while ( sheng - cha [ r ] * t >= 0 )
		{
			if ( r > n )
			{
				break ;
			}
			sheng -= cha [ r ] * t ;
			t ++ ;
			maxx = max ( maxx , t ) ;
			r ++ ;
			
		}
		if ( r > n )
		{
			break ;
		}
		sheng = min ( m , sheng + (  diam [ r - 1 ] - diam [ l ] ) )  ;
		t -- ;
		l ++ ;
	}
	cout << maxx ;
	return 0 ;
}

