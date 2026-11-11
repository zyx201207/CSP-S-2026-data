#include <bits/stdc++.h>
using namespace std;
#define int long long
int cc,n,m,dd,q;
int mp [ 505 ][ 505 ];
int w [ 500005 ];
vector <int> t [ 505 ],a [ 505 ];
struct node
{
	int x,k;
};
vector <node> b [ 500005 ];
int tt [ 500005 ];
vector <int> gg;
signed main()
{
	freopen ( "subway.in","r",stdin );
	freopen ( "subway.out","w",stdout );
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	memset ( mp,0x3f,sizeof mp );
	cin >> cc >> n >> m >> dd >> q;
	for ( int i = 1;i <= m;i++ )
		cin >> w [ i ];
	for ( int i = 1;i <= n;i++ )
	{
		int k;
		cin >> k;
		for ( int j = 1;j <= k;j++ )
		{
			int x,y;
			cin >> x >> y;
			a [ i ].push_back ( x );
			b [ x ].push_back ( {i,y} );
			tt [ x ]++;
			if ( tt [ x ] == 2 )
				gg.push_back ( x );
			t [ i ].push_back ( y );
		}
	}
	for ( int s = 0;s < gg.size();s++ )
	{
		int i = gg [ s ];
		if ( b [ i ].size() < 2 )
			continue;
		for ( int j = 0;j < b [ i ].size();j++ )
		{
			for ( int k = j + 1;k < b [ i ].size();k++ )
			{
				int u = b [ i ][ j ].x,v = b [ i ][ k ].x;
				int g = b [ i ][ j ].k + b [ i ][ k ].k;
				mp [ u ][ v ] = min ( mp [ u ][ v ],g );
				mp [ v ][ u ] = min ( mp [ v ][ u ],g );
			}
		}
	}
	for ( int i = 1;i <= n;i++ )
		mp [ i ][ i ] = 0;
	for ( int k = 1;k <= n;k++ )
	{
		for ( int i = 1;i <= n;i++ )
		{
			for ( int j = i;j <= n;j++ )
				mp [ i ][ j ] = mp [ j ][ i ] = min ( mp [ i ][ j ],mp [ i ][ k ] + mp [ k ][ j ] );
		}
	}
	while ( q-- )
	{
		int x,y;
		cin >> x >> y;
		int as = 1e18; 
		for ( int i = 0;i < b [ x ].size();i++ )
		{
			for ( int j = 0;j < b [ y ].size();j++ )
			{
				int u = b [ x ][ i ].x,v = b [ y ][ j ].x;
				int g = b [ x ][ i ].k + b [ y ][ j ].k;
				as = min ( as,min ( mp [ u ][ v ],mp [ v ][ u ] ) + g );
			}
		}
		cout << as + w [ x ] + w [ y ] << endl;
	}
	return 0;
}