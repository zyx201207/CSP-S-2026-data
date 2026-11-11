#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5 , M = 3e5+3 , RP = 0x3f3f3f3f;
int n , m;
int a[ N ] , g[ N ] , lst[ M ] , ans[ M ];
int main( )
{
	freopen( "card.in" , "r" , stdin );
	freopen( "card.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[ i ];
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		memset( lst , 0 , sizeof lst );
		for ( int j = i ; j <= n ; j ++ )
		{
			if ( lst[ a[ j ] ] )
			{
				for ( int k = lst[ a[ j ] ] ; k <= j ; k ++ )
				{
					g[ k ] = 0;
				}
				for ( int k = 1 ; k <= m ; k ++ )
				{
					if ( lst[ k ] >= lst[ a[ j ] ] && lst[ k ] <= j )
					{
						lst[ k ] = 0;
						for ( int l = lst[ a[ j ] ] ; l >= i ; l -- )
						{
							if ( g[ l ] == k )
							{
								lst[ k ] = l;
								break;
							}
						}
					}
				}
			}
			g[ j ] = a[ j ];
			lst[ a[ j ] ] = j;
		}
		for ( int j = i ; j <= n ; j ++ )
		{
			ans[ g[ j ] ] ++;
		}
	}
	for ( int i = 1 ; i <= m ; i ++ )
	{
		cout << ans[ i ] << ' ';
	}
	return 0;
}
