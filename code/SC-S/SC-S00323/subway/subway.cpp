#include<bits/stdc++.h>
#define qvq return 0
using namespace std ;

const int N = 1e6 + 10, M = 5e2 + 10 ;

struct NODE
{
	long long v, w ;
} ;

vector<NODE> vec[N] ;

long long m, n, d, a[N], mp[M][M] ;

signed main()
{
	freopen( "subway.in", "r", stdin ) ;
	freopen( "subway.out", "w", stdout ) ;
	
	ios_base::sync_with_stdio( false ) ;
	cin.tie( nullptr ), cout.tie( nullptr ) ;
	
	memset( mp, 0x3f, sizeof( mp ) ) ;
	
	int id, qwq ;
	
	cin >> id >> m >> n >> d >> qwq ;
	
	for(int i=1; i<=m; i++)	mp[i][i] = 0 ;
	
	for(int i=1; i<=n; i++)	cin >> a[i] ;
	
	for(int i=1; i<=m; i++)
	{
		int siz ;	cin >> siz ;
		for(int j=1; j<=siz; j++)
		{
			int st, x ;	cin >> st >> x ;
			vec[st].push_back( { i, x } ) ;
		}
	}
	
	for(int i=1; i<=n; i++)
		for( auto x : vec[i] )
			for( auto y : vec[i] )
			{
				if( x.v == y.v )	break ;
				mp[x.v][y.v] = min( mp[x.v][y.v], x.w + y.w ) ;
				mp[y.v][x.v] = min( mp[y.v][x.v], x.w + y.w ) ;
			}
	
	for(int k=1; k<=m; k++)
		for(int i=1; i<=m; i++)
			for(int j=1; j<=m; j++)
				mp[i][j] = min( mp[i][j], mp[i][k] + mp[k][j] ) ;
	
	while( qwq-- )
	{
		int u, v ;	cin >> u >> v ;
		long long ans = 1e18 ;
		for( auto x : vec[u] )
			for( auto y : vec[v] )
				ans = min( ans, mp[x.v][y.v] + x.w + y.w ) ;
		cout << ans + a[u] + a[v] << "\n" ;
	}
	
	qvq ;
}
//	olD_mOwOn :)