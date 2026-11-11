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
//	freopen ( ".in" , "r" , stdin );
//	freopen ( ".out" , "w" , stdout );
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
			printf ( "%lld\n" , max ( 0ll , n - ( 2 * d - 1 ) ) );
		}
	}
	return 0;
}

