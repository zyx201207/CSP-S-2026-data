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
int n , a [ 500010 ] , ans = 1 , sum [ 500010 ] , l = 1 , r , m;
bool check ( int x )
{
	int res = MAX;
	for ( int i = x ; i <= n ; i++ )
	{
		res = min ( res , a [ i ] * ( x - 1 ) - ( sum [ i - 1 ] - sum [ i - x ] ) );
	}
	return res <= m;
}
signed main()
{
	freopen ( "crystal.in" , "r" , stdin );
	freopen ( "crystal.out" , "w" , stdout );
	n = read ();
	m = read ();
	for ( int i = 1 ; i <= n ; i++ )
	{
		a [ i ] = read ();
	}
	sort ( a + 1 , a + 1 + n );
	for ( int i = 1 ; i <= n ; i++ )
	{
		sum [ i ] = sum [ i - 1 ] + a [ i ];
	}
	r = n;
	while ( l <= r )
	{
		int mid = ( l + r ) / 2;
		if ( check ( mid ) )
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf ( "%lld" , ans );
	return 0;
}

