#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 10 ;
int a [ N ] ;
int n , m ;
int cmp = 0 ;
int main()
{
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	scanf ( "%d%d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i ++ )
		scanf ( "%d" , &a [ i ] ) ;
	sort ( a + 1 , a + 1 + n ) ;
	long long ans = 1 ;
	for ( int i = 2 ; i <= n ; i ++ )
	{
		long long sum = m , c = 1 ;
		for ( int j = i - 1 ; j >= 1 ; j -- )
		{
			if ( a [ i ] - a [ j ] <= sum )
			{
				sum -= a [ i ] - a [ j ] ;
				c ++ ;
				continue ;
			}
			break ;
		}
		ans = max ( ans , c ) ;
	}
	printf ( "%lld" , ans ) ;
	return 0 ;
}
