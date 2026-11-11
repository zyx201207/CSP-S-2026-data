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
int c , n , m , k [ 500010 ] , d , q , w [ 500010 ] , t [ 1010 ] [ 1010 ] , sum [ 50 ] [ 500010 ] , ans = MAX , cur [ 500010 ] , ans1 [ 510 ] [ 510 ] , sum1 [ 510 ] [ 20010 ];
bool vis [ 500010 ] , vis1 [ 510 ] [ 20010 ];
signed main()
{
	freopen ( "subway.in" , "r" , stdin );
	freopen ( "subway.out" , "w" , stdout );
	c = read ();
	n = read ();
	m = read ();
	d = read ();
	q = read ();
	for ( int i = 1 ; i <= m ; i++ )
	{
		w [ i ] = read ();
	}
//	if ( n == 2 )
//	{
//		for ( int i = 1 ; i <= n ; i++ )
//		{
//			cin >> k [ i ];
//			for ( int j = 1 ; j <= k [ i ] ; j++ )
//			{
//				int u = read () , t = read ();
//				sum [ i ] [ u ] = t;
//				cur [ j ] = u;
//				if ( i == 1 )
//				{
//					vis [ u ] = 1;
//				}
//				if ( i == 2 )
//				{
//					if ( vis [ u ] == 1 )
//					{
//						ans = min ( ans , sum [ 1 ] [ u ] + t );
//					}
//				}
//			}
//		}
//		while ( q-- )
//		{
//			int x , y;
//			x = read ();
//			y = read ();
//			if ( x == y )
//			{
//				printf ( "0\n" );
//			}
//			if ( vis [ x ] == vis [ y ] )
//			{
//				if ( vis [ x ] == 1 )
//				{
//					printf ( "%lld\n" , w [ x ] + w [ y ] + sum [ 1 ] [ x ] + sum [ 1 ] [ y ] );
//				}
//				else
//				{
//					printf ( "%lld\n" , w [ x ] + w [ y ] + sum [ 2 ] [ x ] + sum [ 2 ] [ y ] );
//				}
//			}
//			else
//			{
//				if ( vis [ x ] == 1 )
//				{
//					printf ( "%lld\n" , ans + w [ x ] + w [ y ] + sum [ 1 ] [ x ] + sum [ 2 ] [ y ] );
//				}
//				else
//				{
//					printf ( "%lld\n" , ans + w [ x ] + w [ y ] + sum [ 2 ] [ x ] + sum [ 1 ] [ y ] );
//				}
//			}
//		}
//	}
	if ( n == 2 )
	{
		memset ( ans1 , 0x3f , sizeof ( ans1 ) );
		memset ( vis1 , 0 , sizeof ( vis1 ) );
		for ( int i = 1 ; i <= n ; i++ )
		{
			cin >> k [ i ];
			for ( int j = 1 ; j <= k [ i ] ; j++ )
			{
				int u = read () , t = read ();
				sum1 [ i ] [ u ] = t;
				vis1 [ i ] [ u ] = 1;
				for ( int k = 1 ; k < i ; k++ )
				{
					if ( vis1 [ k ] [ u ] == 1 )
					{
						ans1 [ k ] [ i ] = min ( ans1 [ k ] [ i ] , sum1 [ k ] [ u ] + t );
						ans1 [ i ] [ k ] = min ( ans1 [ i ] [ k ] , sum1 [ k ] [ u ] + t );
//						cout << sum1 [ k ] [ u ] << " " << t << endl;
					}
				}
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 1 ; j <= n ; j++ )
			{
				for ( int k = 1 ; k <= n ; k++ )
				{
					ans1 [ i ] [ j ] = min ( ans1 [ i ] [ j ] , ans1 [ i ] [ k ] + ans1 [ k ] [ j ] );
				}
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			ans1 [ i ] [ i ] = 0; 
		}
		while ( q-- )
		{
			int x , y;
			x = read ();
			y = read ();
			if ( x == y )
			{
				printf ( "0\n" );
				continue;
			}
			bool flagg = 1;
			for ( int i = 1 ; i <= n ; i++ )
			{
				if ( vis1 [ i ] [ x ] == 1 && vis1 [ i ] [ y ] == 1 )
				{
					printf ( "%lld\n" , w [ x ] + w [ y ] + sum1 [ i ] [ x ] + sum1 [ i ] [ y ] );
					flagg = 0;
					break;
				}
			}
			if ( flagg == 1 )
			{
				continue;
			}
			int l , r;
			for ( int i = 1 ; i <= n ; i++ )
			{
				if ( vis1 [ i ] [ x ] == 1 )
				{
					l = i;
				}
				if ( vis1 [ i ] [ y ] == 1 )
				{
					r = i;
				}
			}
			printf ( "%lld\n" , ans1 [ l ] [ r ] + w [ x ] + w [ y ] + sum1 [ l ] [ x ] + sum1 [ r ] [ y ] );
		}
//		while ( q-- )
//		{
//			int x , y;
//			x = read ();
//			y = read ();
//			if ( x == y )
//			{
//				printf ( "0\n" );
//			}
//			if ( vis [ x ] == vis [ y ] )
//			{
//				if ( vis [ x ] == 1 )
//				{
//					printf ( "%lld\n" , w [ x ] + w [ y ] + sum [ 1 ] [ x ] + sum [ 1 ] [ y ] );
//				}
//				else
//				{
//					printf ( "%lld\n" , w [ x ] + w [ y ] + sum [ 2 ] [ x ] + sum [ 2 ] [ y ] );
//				}
//			}
//			else
//			{
//				if ( vis [ x ] == 1 )
//				{
//					printf ( "%lld\n" , ans + w [ x ] + w [ y ] + sum [ 1 ] [ x ] + sum [ 2 ] [ y ] );
//				}
//				else
//				{
//					printf ( "%lld\n" , ans + w [ x ] + w [ y ] + sum [ 2 ] [ x ] + sum [ 1 ] [ y ] );
//				}
//			}
//		}
	}
	return 0;
}

