#include<bits/stdc++.h>
using namespace std;
int c , t , n , d ;
const int N = 2e6 + 10 ;
int a [ N ] , T [ 2 ] [ N ] ;
bool road ( int x , int y )
{
	int sum = 1 ;
	for ( int i = x ; i <= y ; i ++ )
	{
		T [ 1 ] [ i ] = 0 ;
		T [ 2 ] [ i ] = 0 ;
	}
	int cmp = 0 ;
	for ( int i = y ; i >= x ; i -- )
	{
		for ( int j = i - 2 ; j >= x ; j -- )
		{
			bool f = 1 ;
			for ( int k = 1 ; k <= cmp ; k ++ )
				if ( j == T [ 1 ] [ k ] )
				{
					f = 0 ;
					break ;
				}
			if ( !f )
			{
				continue ;	
			}
			if ( a [ i ] - a [ j ] <= d )
			{
				if ( T [ 2 ] [ cmp ] == i )
				{
					T [ 1 ] [ cmp ] = j ;
					continue ;
				}
				f = 0 ;
				for ( int k = 1 ; k <= cmp ; k ++ )
				{
					if ( T [ 1 ] [ k ] == 0 && T [ 2 ] [ k ] == 0 )
					{
						break ;
					}
					if ( ( T [ 1 ] [ k ] <= j && T [ 2 ] [ k ] >= j ) || ( T [ 1 ] [ k ] <= i && T [ 2 ] [ k ] >= i ) )
					{
						f = 1 ;
						break ;
					}
				}
				if ( !f )
				{
					T [ 1 ] [ ++cmp ] = j ;
					T [ 2 ] [ cmp ] = i ;
					continue ;
				}
				sum ++ ;
				if ( sum > 2 )
					return 0 ;
				
			}
		}
	}
	if ( sum == 2 )
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf ( "%d%d" , &c , &t ) ;
	while ( t )
	{
		t -- ;
		scanf ( "%d%d" , &n , &d ) ;
		for ( int i = 1 ; i <= n ; i ++ )
			scanf ( "%d" , &a [ i ] ) ;
		int ans = 0 ;
		for ( int i = 1 ; i <= n - 2 ; i ++ )
			for ( int j = i + 2 ; j <= n ; j ++ )
			{
				if ( a [ j ] - a [ i ] <= d )
				{
					continue ;
				}
				if ( road ( i , j ) )
				{
					ans ++ ;
				}
			}
		printf ( "%d\n" , ans ) ;
	}
	return 0;
}