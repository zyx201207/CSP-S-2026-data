#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10 ;
int c , n , m , d , q ;
int w [ N ] , k [ N ] , t [ N ] ;
struct Node{
	int x , time ;
}ki [ N ] ;
int ans ;
int dfs ( int x , int y , int sum )
{
	for ( int i = 1 ; i <= k [ x ] ; i ++ )
	{
		for ( int j = 1 ; j <= n ; j ++ )
		{
			if ( j == x )
			{
				continue ;
			}
			for ( int k = 1 ; k <= k [ j ] ; k ++ )
			{
				if ( !t [ ki [ i ] . x ] && ki [ i ] . x == ki [ k ] . x )
				{
					t [ ki [ i ] . x ] = 1 ;
					dfs ( k , )
				}
			}
		}
	}
	ans = min ( ans , sum ) ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf ( "%d%d%d%d%d" , &c , &n , &m , &d , &q ) ;
	for ( int i = 1 ; i <= m ; i ++ )
		scanf ( "%d" , &w [ i ] ) ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		scanf ( "%d" , &k [ i ] ) ;
		for ( int j = 1 ; j <= k [ i ] ; j ++ )
			scanf ( "%d%d" , &ki [ j ] . x , &ki [ j ] . time ) ;
	}
	int x , y , T ;
	while ( q )
	{
		scanf ( "%d%d" , &x , &y ) ;
		T = w [ x ] + w [ y ] ;
		for ( int i = 1 ; i <= m ; i ++ )
		{
			t [ i ] = 0 ;
		}
		ans = INT_MAX;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			for ( int j = 1 ; j <= k [ i ] ; j ++ )
			{
				if ( ki [ j ] . x == x )
				{
					dfs ( i , j , 0 ) ;
				}
			}
		}
		printf ( "%d\n", ans ) ;
		q -- ;
	}
	return 0;
}