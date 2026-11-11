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
int n , m , ans [ 300010 ] , a [ 500010 ] , sum [ 300010 ] , r;
bool vis [ 300010 ] , ok;
signed main()
{
	freopen ( "card.in" , "r" , stdin );
	freopen ( "card.out" , "w" , stdout );
	n = read ();
	m = read ();
	for ( int i = 1 ; i <= n ; i++ )
	{
		a [ i ] = read ();
		if ( a [ i ] < a [ i - 1 ] )
		{
			ok = 1;
		}
	}
	if ( ok == 0 )
	{
		int sum = 1;
		for ( int i = 1 ; i <= n ; i++ )
		{
			if ( sum < a [ i ] )
			{
				printf ( "%lld " , i - 1 );
				sum++;
			}
		}
		printf ( "%lld" , n );
		return 0;
	}
	if ( m <= 2 )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			if ( a [ i ] == a [ n ] )
			{
				ans [ a [ i ] ]++;
			}
			else
			{
				ans [ 1 ]++;
				ans [ 2 ]++;
			}
		}
		printf ( "%lld %lld" , ans [ 1 ] , ans [ 2 ] );
		return 0;
	}
	memset ( sum , 0x3f , sizeof ( sum ) ); 
	for ( int i = n ; i >= 1 ; i-- )
	{
		if ( sum [ a [ i ] ] == MAX )
		{
			sum [ a [ i ] ] = i;
		}
	}
	for ( int t = 1 ; t <= n ; t++ )
	{
		int i = t;
		while ( i <= n )
		{
			bool okk = 0;
			i = max ( i , sum [ a [ i ] ] );
			ans [ a [ i ] ]++;
			i++;
		}
	}
	for ( int i = 1 ; i <= m ; i++ )
	{
		printf ( "%lld " , ans [ i ] );
	}
	return 0;
}
//68~100
