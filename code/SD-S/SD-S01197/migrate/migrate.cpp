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
int t , c , n , a [ 2000010 ] , d;
signed main()
{
	freopen ( "migrate.in" , "r" , stdin );
	freopen ( "migrate.out" , "w" , stdout );
	c = read ();
	t = read ();
	while ( t-- )
	{
		n = read ();
		d = read ();
		for ( int i = 1 ; i <= n ; i++ )
		{
			a [ i ] = read (); 
		}
		if ( c == 11 || c == 12 )
		{
			if ( abs ( a [ 2 ] - a [ 1 ] ) >= d )
			{
				printf ( "0\n" );
				continue;
			}
			int x = MAX , y = MAX;
			for ( int i = 1 ; i <= n ; i++ )
			{
				if ( abs ( a [ i ] - a [ 1 ] ) > d )
				{
					x = i - 1;
					break;
				}
			}
			for ( int i = x ; i <= n ; i++ )
			{
				if ( abs ( a [ i ] - a [ x ] ) > d )
				{
					y = i - 2;
					break;
				}
			}
			printf ( "%lld\n" , max ( 0ll , n - y + 1 ) );
			continue;
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = i + 1 ; j <= n ; j++ )
			{
				bool flag = 1;
				for ( int k = i + 1 ; k <= j ; k++ )
				{
					if ( ( a [ k ] - a [ k - 1 ] ) > d )
					{
						flag = 0;
						break;
					}
				}
			}
		}
	}
	return 0;
}

