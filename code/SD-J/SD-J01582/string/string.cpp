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
int n , a [ 200010 ] , l = 1 , r , ans;
char c [ 200010 ];
signed main()
{
	freopen ( "string.in" , "r" , stdin );
	freopen ( "string.out" , "w" , stdout );
	n = read ();
	for ( int i = 1 ; i <= n ; i++ )
	{
		a [ i ] = read ();
		c [ i ] = getchar ();
	}
	r = n;
	while ( l < r )
	{
		while ( c [ l ] == c [ r ] && l < r )
		{
			int x = min ( a [ l ] , a [ r ] );
			a [ l ] -= x;
			a [ r ] -= x;
			if ( a [ l ] == 0 )
			{
				l++;
			}
			if ( a [ r ] == 0 )
			{
				r--;
			}
		}
		if ( l >= r )
		{
			break;
		}
		ans += min ( a [ r ] , a [ l ] );
		int x = min ( a [ l ] , a [ r ] );
		a [ l ] -= x;
		a [ r ] -= x;
		if ( a [ l ] == 0 )
		{
			l++;
		}
		if ( a [ r ] == 0 )
		{
			r--;
		}
	}
	printf ( "%lld" , ans );
	return 0;
}
//100
