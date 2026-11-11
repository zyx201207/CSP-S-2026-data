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
string s1 , c1 , s2 , c2;
signed main()
{
	freopen ( "travel.in" , "r" , stdin );
	freopen ( "travel.out" , "w" , stdout );
	cin >> s1 >> c1 >> s2 >> c2;
	if ( s1 == s2 )
	{
		printf ( "1" );
	}
	else
	{
		printf ( "0000" );
		return 0;
	}
	if ( c1 [ 0 ] == c2 [ 0 ] && c1 [ 1 ] == c2 [ 1 ] )
	{
		printf ( "1" );
	}
	else
	{
		printf ( "000" );
		return 0;
	}
	if ( ( c1 [ 2 ] == 'D' && c2 [ 2 ] == 'F' ) || ( c1 [ 2 ] == 'F' && c2 [ 2 ] == 'D' ) )
	{
		printf ( "1" );
	}
	else if ( ( c1 [ 2 ] == 'A' && ( c2 [ 2 ] == 'B' || c2 [ 2 ] == 'C' ) ) || ( c1 [ 2 ] == 'B' && ( c2 [ 2 ] == 'A' || c2 [ 2 ] == 'C' ) ) || ( c1 [ 2 ] == 'C' && ( c2 [ 2 ] == 'A' || c2 [ 2 ] == 'B' ) ) )
	{
		printf ( "1" );
	}
	else
	{
		printf ( "00" );
		return 0;
	}
	if ( ( c1 [ 2 ] == 'A' && c2 [ 2 ] == 'B' ) || ( c1 [ 2 ] == 'B' && ( c2 [ 2 ] == 'A' || c2 [ 2 ] == 'C' ) ) || ( c1 [ 2 ] == 'C' && c2 [ 2 ] == 'B' ) || ( c1 [ 2 ] == 'D' && c2 [ 2 ] == 'F' ) || ( c1 [ 2 ] == 'F' && c2 [ 2 ] == 'D' ) )
	{
		printf ( "1" );
	}
	else
	{
		printf ( "0" );
	}
	return 0;
}
//100
