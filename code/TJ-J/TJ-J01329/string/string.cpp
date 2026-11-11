#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , ans;
int a[ 200001 ];
char c[ 200001 ];
signed main( )
{
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[ i ] >> c[ i ];
	}
	int i1 = 1 , j1 = n;
	while( i1 < j1 )
	{
		if ( c[ i1 ] == c[ j1 ] )
		{
			if ( a[ i1 ] < a[ j1 ] )
			{
				a[ j1 ] -= a[ i1 ++ ];
			}
			else if ( a[ i1 ] == a[ j1 ] )
			{
				i1 ++;
				j1 --;
			}
			else if ( a[ i1 ] > a[ j1 ] )
			{
				a[ i1 ] -= a[ j1 -- ];
			}
		}
		else
		{
			ans += min( a[ i1 ] , a[ j1 ] );
			if ( a[ i1 ] < a[ j1 ] )
			{
				a[ j1 ] -= a[ i1 ++ ];
			}
			else if ( a[ i1 ] == a[ j1 ] )
			{
				i1 ++;
				j1 --;
			}
			else if ( a[ i1 ] > a[ j1 ] )
			{
				a[ i1 ] -= a[ j1 -- ];
			}
		}
	}
	cout << ans;
	return 0;
}
