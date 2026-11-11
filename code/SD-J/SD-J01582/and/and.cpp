#include<bits/stdc++.h>
#define int long long
#define MAX 0x3f3f3f3f3f3f3f3f
#define MIN -0x3f3f3f3f3f3f3f3f
using namespace std;
int read ()
{
	int f = 1 , res = 0;
	char c = getchar ();;
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
int n , m , a [ 200010 ] , ans , sum , cur [ 50 ] , s [ 50 ] , t [ 10 ] , sum1 [ 50 ] , sum2 [ 200010 ] [ 50 ];
bool flag , vis , ok;
bool check ( int x )
{
	int res = 0;
	while ( x != 0 )
	{
		if ( x % 2 == 1 )
		{
			res++;
		}
		x /= 2;
	}
	if ( res == m )
	{
		return 1;
	}
	return 0;
}
signed main()
{
	freopen ( "and.in" , "r" , stdin );
	freopen ( "add.out" , "w" , stdout );
	n = read ();
	m = read ();
	s [ 0 ] = 1;
	for ( int i = 1 ; i <= 31 ; i++ )
	{
		s [ i ] = s [ i - 1 ] * 2;
	}
	if ( s [ lower_bound ( s , s + 32 , n ) - s ] != n )
	{
		vis = 1;
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		a [ i ] = read ();
		if ( s [ lower_bound ( s , s + 32 , a [ i ] + 1 ) - s ] != a [ i ] + 1 )
		{
			flag = 1;
		}
		if ( a [ i ] != i - 1 )
		{
			vis = 1;
		}
		if ( a [ i ] > 4 )
		{
			ok = 1;
		}
	}
	if ( m == n - 1 )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			sum = sum & a [ i ];
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			int x = a [ i ] , cnt = 0;
			memset ( sum1 , 0 , sizeof ( sum1 ) );
			while ( x != 0 )
			{
				sum1 [ ++cnt ] = x % 2;
				x /= 2;
			}
			for ( int j = 1 , k = 30 ; j <= cnt ; j++ , k-- )
			{
				sum2 [ i ] [ k ] = sum1 [ j ];
			}
		}
		for ( int j = 1 ; j <= 30 ; j++ )
		{
			int cur2 = 0;
			for ( int i = 1 ; i <= n ; i++ )
			{
				if ( sum2 [ i ] [ j ] == 0 )
				{
					cur2++;
				}
			}
			if ( cur2 == 1 )
			{
				printf ( "%lld" , sum + ( 1 << ( 30 - j ) ) );
				return 0;
			}
		}
		printf ( "%lld" , sum );
		return 0;
	}
	if ( ok == 0 )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			t [ a [ i ] ]++;
		}
		if ( t [ 4 ] >= m )
		{
			printf ( "4" );
			return 0;
		}
		if ( t [ 3 ] >= m )
		{
			printf ( "3" );
			return 0;
		}
		if ( t [ 3 ] + t [ 2 ] >= m )
		{
			printf ( "2" );
			return 0;
		}
		if ( t [ 3 ] + t [ 1 ] >= m )
		{
			printf ( "1" );
			return 0;
		}
		printf ( "0" );
		return 0;
	}
	if ( vis == 0 )
	{
		ans = n - 1;
		for ( int i = 0 ; i <= 30 ; i++ )
		{
			if ( m <= s [ i ] )
			{
				printf ( "%lld" , ans );
				return 0;
			}
			else
			{
				ans -= s [ i ];
			}
		}
		return 0; 
	}
	if ( flag == 0 )
	{
		sort ( a + 1 , a + 1 + n );
		printf ( "%lld" , a [ n - m + 1 ] );
		return 0;
	}
	if ( n <= 20 )
	{
		for ( int i = 0 ; i < ( 1 << n ) ; i++ )
		{
			if ( check ( i ) == 0 )
			{
				continue;
			}
			int x = i , sum = 2147483647;
			for ( int i = 1 ; i <= n ; i++ )
			{
				if ( x % 2 == 1 )
				{
					sum = ( sum & a [ i ] );
				}
				x /= 2;
			}
			ans = max ( ans , sum );
		}
		printf ( "%lld" , ans );
		return 0;
	}
	if ( m == 1 )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			ans = max ( ans , a [ i ] );
		}
		printf ( "%lld" , ans );
		return 0;
	}
	if ( m == 2 )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 1 ; j <= n ; j++ )
			{
				if ( i != j )
				{
					ans = max ( ans , a [ i ] & a [ j ] );
				}
			}
		}
		printf ( "%lld" , ans );
		return 0;
	}
	if ( m == n )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			ans = ( ans & a [ i ] );
		}
		printf ( "%lld" , ans );
		return 0;
	}
	return 0;
}
//85
