#include<bits/stdc++.h>
#define int long long
#define MAX 0x3f3f3f3f3f3f3f3f
#define MIN -0x3f3f3f3f3f3f3f3f
int read ()
{
	int f = 1 , res = 0;
	char c = getchar ();
	while ( c < '0' || c > '9' )
	{
		if ( c == '-' )
		{
			f = -1;
		}
		c = getchar ();
	}
	while ( c >= '0' && c <= '9' )
	{
		res = ( res << 3 ) + ( res << 1 ) + c - '0';
		c = getchar ();
	}
	return res * f;
}
using namespace std;
int c , n , t , a [ 2000010 ] , f [ 2000010 ] , sum [ 2000010 ] , ans , d;
signed main()
{
	freopen ( "migrate3.in" , "r" , stdin );
//	freopen ( "migrate.out" , "w" , stdout );
	c = read ();
	t = read ();
	while ( t-- )
	{
		n = read ();
		d = read ();
		for ( int i = 1 ; i <= n ; i++ )
		{
			a [ i ] = read ();
			f [ i ] = 1;
		}
		memset ( sum , 0x3f , sizeof ( sum ) );
		sum [ 1 ] = 0;
		ans = 0;
		for ( int i = 1 ; i <= n ; i++ )
		{
			if ( abs ( a [ i ] - a [ i - 1 ] ) > d )
			{
				sum [ i ] = 0;
			}
		}
		for ( int i = 2 ; i <= n ; i++ )
		{
			for ( int j = i - 1 ; j >= 1 ; j-- )
			{
				if ( abs ( a [ i ] - a [ j ] ) > d )
				{
					break;
				}
				if ( sum [ j ] + 1 < sum [ i ] )
				{
					f [ i ] = f [ j ];
					sum [ i ] = sum [ j ] + 1;
				}
				else if ( sum [ j ] + 1 == sum [ i ] )
				{
					f [ i ] += f [ j ];
				}
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			if ( f [ i ] == 2 )
			{
				ans++;
			}
//			cout << f [ i ] << " " << sum [ i ] << endl;
		}
		printf ( "%lld\n" , ans );
	}
	return 0;
}
//8 3
//0 1 2 4 8 10 11 13
