#include <bits/stdc++.h>
using namespace std;
int n , m , ans , cnt;
int a[ 200001 ];
bool u[ 200001 ] , flag;
void dfs( int step )
{
	if ( step > n )
	{
		if ( cnt == m )
		{
			int t;
			for ( int i = 1 ; i <= n ; i ++ )
			{
				if ( u[ i ] )
				{
					t = a[ i ];
					break;
				}
			}
			for ( int i = 1 ; i <= n ; i ++ )
			{
				if ( u[ i ] )
				{
					t &= a[ i ];
				}
			}
			ans = max( ans , t );
		}
		return;
	}
	u[ step ] = false;
	dfs( step + 1 );
	u[ step ] = true;
	cnt ++;
	dfs( step + 1 );
	cnt --;
	u[ step ] = false;
}
int main( )
{
	freopen( "and.in" , "r" , stdin );
	freopen( "and.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[ i ];
		if ( ! ( a[ i ] & 1 ) )
		{
			flag = true;
		}
	}
	if ( m == 1 )
	{
		int mx = -1;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			mx = max( mx , a[ i ] );
		}
		cout << mx;
		return 0;
	}
	if ( m == 2 )
	{
		int mx = -1;
		for ( int i = 1 ; i < n ; i ++ )
		{
			for ( int j = i + 1 ; j <= n ; j ++ )
			{
				mx = max( mx , a[ i ] & a[ j ] );
			}
		}
		cout << mx;
		return 0;
	}
	if ( m == n )
	{
		ans = a[ 1 ];
		for ( int i = 2 ; i <= n ; i ++ )
		{
			ans &= a[ i ];
		}
		cout << ans;
		return 0;
	}
	if ( n <= 20 )
	{
		dfs( 1 );
		cout << ans;
		return 0;
	}
	if ( ! flag )
	{
		sort( a + 1 , a + 1 + n , greater< int >( ) );
		ans = a[ 1 ];
		for ( int i = 1 ; i <= m ; i ++ )
		{
			ans &= a[ i ];
		}
		cout << ans;
	}
	return 0;
}
