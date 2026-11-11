#include <bits/stdc++.h>
#define int long long
using namespace std;
int l = 1e13 , r = -1e13 , n , m;
int a[ 500001 ] , b[ 500001 ];
bool check( int x )
{
	int ans = 0x3fffffffffffffff;
	for ( int i = x ; i <= n ; i ++ )
	{
		int t = b[ i ] - b[ i - x ];
		ans = min( ans , a[ i ] * x - t );
		if ( ans <= m )
		{
			return true;
		}
	}
	return ( ans <= m );
}
signed main( )
{
	freopen( "crystal.in" , "r" , stdin );
	freopen( "crystal.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[ i ];
	}
	sort( a + 1 , a + 1 + n );
	l = 1 , r = n;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		b[ i ] = b[ i - 1 ] + a[ i ];
	}
	while( l < r )
	{
		int mid = ( l + r + 1 ) >> 1;
		if ( check( mid ) )
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
