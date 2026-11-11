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
int sum [ 5010 ] , c , t , n , d , f [ 5010 ] [ 5010 ] , cnt [ 5010 ] [ 5010 ];
signed main()
{
//	freopen ( ".in" , "r" , stdin );
//	freopen ( ".out" , "w" , stdout );
	cin >> c >> t;
	while ( t-- )
	{
		cin >> n >> d;
		for ( int i = 1 ; i <= n ; i++ )
		{
			cin >> a [ i ];
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = i + 1 ; j <= n ; j++ )
			{
				cnt [ i ] [ j ] = a [ j ] - a [ i ];
			}
		}
		memset ( f , 0 , sizeof ( f ) );
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 1 ; j <= n ; j++ )
			{
				int t = ( a [ j ] - a [ i ] ) / d; 
				if ( t == 1 && ( a [ j ] - a [ i ] ) % d == 0 )
				{
					f [ i ] [ j ] = 1;
				}
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			
		}
	}
	return 0;
}

