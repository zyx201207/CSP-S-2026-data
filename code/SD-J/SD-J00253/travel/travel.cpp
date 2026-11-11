# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 1e5 + 7 ;

bool ans [ 4 ] ;
void solve ( )
{
	string c1 , s1 , c2 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	do
	{
		if ( c1 == c2 )
		{
			cout << 1 ;
			ans [ 0 ] = 1 ;
		}
		else
		{
			cout << 0 ;
		}		
	} while ( 0 ) ;
	do
	{
		if ( ans [ 0 ] && s1 [ 0 ] == s2 [ 0 ] && s1 [ 1 ] == s2 [ 1 ] )
		{
			cout << 1 ;
			ans [ 1 ] = 1 ;
		}
		else
		{
			cout << 0 ;
		}
	} while ( 0 ) ;
	do
	{
		if ( ans [ 0 ] && ans [ 1 ] && s1 [ 2 ] >= 'A' && s1 [ 2 ] <= 'C' && s2 [ 2 ] >= 'A' && s2 [ 2 ] <= 'C' )
		{
			cout << 1 ;
			ans [ 2 ] = 1 ;
		}
		else if ( ans [ 0 ] && ans [ 1 ] && s1 [ 2 ] >= 'D' && s1 [ 2 ] <= 'F' && s2 [ 2 ] >= 'D' && s2 [ 2 ] <= 'F' )
		{
			cout << 1 ;
			ans [ 2 ] = 1 ;
		}
		else
		{
			cout << 0 ;
		}
	} while ( 0 ) ;
	do
	{
		if ( ans [ 0 ] && ans [ 1 ] && ans [ 2 ] )
		{
			if ( s1 [ 2 ] == 'A' && s2 [ 2 ] == 'B' )
			{
				cout << 1 ;
			}
			else if ( s1 [ 2 ] == 'B' && s2 [ 2 ] == 'A' )
			{
				cout << 1 ;
			}
			else if ( s1 [ 2 ] == 'B' && s2 [ 2 ] == 'C' )
			{
				cout << 1 ;
			}
			else if ( s1 [ 2 ] == 'C' && s2 [ 2 ] == 'B' )
			{
				cout << 1 ;
			}
			else if ( s1 [ 2 ] == 'D' && s2 [ 2 ] == 'F' )
			{
				cout << 1 ;
			}
			else if ( s1 [ 2 ] == 'F' && s2 [ 2 ] == 'D' )
			{
				cout << 1 ;
			}
			else
			{
				cout << 0 ;
			}
		}
		else
		{
			cout << 0 ;
		}
	} while ( 0 ) ;
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout ) ;
	int T = 1 ;
//	cin >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}
