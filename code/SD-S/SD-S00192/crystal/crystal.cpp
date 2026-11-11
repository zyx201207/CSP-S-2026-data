# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 5e5 + 7 ;

ll a [ MAXN ] , pre [ MAXN ] ;
void solve ( )
{
	int n ;
	ll m ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		cin >> a [ i ] ;
	}
	sort ( a + 1 , a + 1 + n ) ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		pre [ i ] = pre [ i - 1 ] + a [ i ] ;
	}
	int ans = 1 ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		int l = 1 , r = i , res = 0 ;
		while ( l <= r )
		{
			int mid = ( l + r ) >> 1 ;
			if ( 1ll * a [ i ] * ( i - mid ) - ( pre [ i - 1 ] - pre [ mid - 1 ] ) <= m )
			{
				res = mid ;
				r = mid - 1 ;
			}
			else
			{
				l = mid + 1 ;
			}
		}
		ans = max ( ans , i - res + 1 ) ;
	}
	cout << ans << '\n' ;
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	int T = 1 ;
//	cin >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}

