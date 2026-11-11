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
int c , n , m , d , q , w [ 500010 ] , k [ 500010 ] , f [ 510 ] [ 510 ];
vector < pair < int , int > > g [ 510 ];
signed main()
{
//	freopen ( ".in" , "r" , stdin );
//	freopen ( ".out" , "w" , stdout );
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1 ; i <= m ; i++ )
	{
		cin >> w [ i ];
	}
	memset ( f , 0x3f , sizeof ( f ) );
	for ( int i = 1 ; i <= n ; i++ )
	{
		f [ i ] [ i ] = 0;
	}
	int siz = 0;
	for ( int i = 1 ; i <= n ; i++ )
	{
		siz++;
		cin >> k [ i ];
		for ( int j = 1 ; j <= k [ i ] ; j++ )
		{
			int u , v;
			cin >> u >> v;
			g [ i ] . push_back ( { siz , v } );
		}
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( auto u : g [ i ] )
		{
			for ( auto v : g [ i ] )
			{
				cout << f [ u . first ] [ v . first ] << " " << u . second << " " << v . second << endl;
				if ( f [ u . first ] [ v . first ] > u . second + v . second )
				{
					f [ u . first ] [ v . first ] = f [ v . first ] [ u . first ] = u . second + v . second;
				}
			}
		}
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = 1 ; j <= n ; j++ )
		{
			for ( int l = 1 ; l <= n ; l++ )
			{
				if ( f [ i ] [ j ] > f [ i ] [ l ] + f [ l ] [ j ] )
				{
					f [ i ] [ j ] = f [ i ] [ l ] + f [ l ] [ j ];
				}
			}
		}
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = 1 ; j <= n ; j++ )
		{
			cout << f [ i ] [ j ] << " ";
		}
		cout << endl;
	}
	while ( q-- )
	{
		int l , r;
		cin >> l >> r;
		int ans = MAX;
		for ( auto i : g [ l ] )
		{
			for ( auto j : g [ r ] )
			{
				int x = i . first , y = j . first , x1 = i . second , y1 = j . second;
				
			}
		}
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
