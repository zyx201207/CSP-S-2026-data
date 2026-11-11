#include <bits/stdc++.h>
#define int long long
using namespace std;
int c , T , n , d , ans , head , tail;
int inq[ 6767 ] , tms[ 6767 ] , mn[ 6767 ] , x[ 6767 ];
pair< int , int > q[ 6767 ];
signed main( )
{
	freopen( "migrate.in" , "r" , stdin );
	freopen( "migrate.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> c >> T;
	while ( T -- )
	{
		cin >> n >> d;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			cin >> x[ i ];
		}
		if ( c <= 10 )
		{
			ans = 0;
			for ( int i = 1 ; i <= n ; i ++ )
			{
				head = 0;
				tail = -1;
				memset( inq , 0 , sizeof inq );
				memset( tms , 0 , sizeof tms );
				pair< int , int > t;
				t.first = i;
				t.second = 0;
				q[ ++ tail ] = t;
				while( head <= tail )
				{
					pair< int , int > h = q[ head ];
					head ++;
					for ( int j = h.first ; j <= n && x[ j ] - x[ h.first ] <= d ; j ++ )
					{
						if ( ! inq[ j ] )
						{
							inq[ j ] = true;
							t.first = j;
							t.second = h.second + 1;
							mn[ j ] = t.second;
							q[ ++ tail ] = t;
						}
						if ( h.second + 1 == mn[ j ] )
						{
							tms[ j ] ++;
						}
					}
				}
				for ( int j = 1 ; j <= n ; j ++ )
				{
					if ( tms[ j ] == 2 )
					{
						ans ++;
					}
				}
			}
			cout << ans << '\n';
		}
		else if ( c == 11 || c == 12 )
		{
			if ( x[ 2 ] - x[ 1 ] * 2 > d )
			{
				cout << "0\n";
				continue;
			}
			if ( x[ 2 ] - x[ 1 ] * 3 <= d )
			{
				cout << "0\n";
				continue;
			}
			ans = 0;
			for ( int i = 1 ; i <= n ; i ++ )
			{
				ans += n - i - 2;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
