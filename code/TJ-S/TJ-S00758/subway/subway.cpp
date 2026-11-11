#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 500010 , N = 510 , RP = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
	int to;
	int cost;
};
int c , n , m , d , q , k , s , e , ans;
int w[ M ];
bool vis[ M + N ];
vector< Edge > E[ M + N ];
void dfs( int place , int len )
{
	if ( place == e )
	{
		ans = min( ans , len );
		return;
	}
	if ( vis[ place ] )
	{
		return;
	}
	vis[ place ] = true;
	int l = E[ place ].size( );
	for ( int i = 0 ; i < l ; i ++ )
	{
		dfs( E[ place ][ i ].to , len + E[ place ][ i ].cost );
	}
	return;
}
signed main( )
{
	freopen( "subway.in" , "r" , stdin );
	freopen( "subway.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1 ; i <= m ; i ++ )
	{
		cin >> w[ i ];
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> k;
		for ( int j = 1 ; j <= k ; j ++ )
		{
			Edge tmp;
			cin >> tmp.to >> tmp.cost;
			E[ m + i ].push_back( tmp );
			int a = tmp.to;
			tmp.to = m + i;
			E[ a ].push_back( tmp );
		}
	}
	while( q -- )
	{
		cin >> s >> e;
		ans = 0x3f3f3f3f3f3f3f3f;
		memset( vis , 0 , sizeof vis );
		dfs( s , 0 );
		cout << ans + w[ s ] + w[ e ] << '\n';
	}
	return 0;
}
