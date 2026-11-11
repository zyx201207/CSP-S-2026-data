# include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
using ull = unsigned long long ;
const int INF = 1e9 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-9 ;
const int MAXN = 2e5 + 7 ;

int a [ MAXN ] ;
char c [ MAXN ] ;
void solve ( )
{
	int n ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; ++ i )
	{
		cin >> a [ i ] >> c [ i ] ;
	}
	int l = 0 , r = n + 1 ;
	ll lenl = 0 , lenr = 0 ;
	ll ans = 0 ;
	while ( l < r - 1 )
	{
		
		if ( lenl == lenr )
		{
			lenl += a [ ++ l ] ;
			lenr += a [ -- r ] ;
			if ( c [ l ] != c [ r ] )
			{
				ans += min ( a [ l ] , a [ r ] ) ;
			}
			if ( l >= r )
			{
				break ;
			}
		}
		else if ( lenl < lenr )
		{
			while ( lenl < lenr && l < r - 1 )
			{
				++ l ;
				if ( lenl + a [ l ] <= lenr )
				{
					if ( c [ l ] != c [ r ] )
					{
						ans += a [ l ] ;
					}
				}
				else
				{
					if ( c [ l ] != c [ r ] )
					{
						ans += ( lenr - lenl ) ;
					}
				}
				lenl += a [ l ] ;
			}
		}
		else
		{
			while ( lenl > lenr && l < r - 1 )
			{
				-- r ;
				if ( lenr + a [ r ] <= lenl )
				{
					if ( c [ l ] != c [ r ] )
					{
						ans += a [ r ] ;	
					}
				}
				else
				{
					if ( c [ l ] != c [ r ] )
					{
						ans += ( lenl - lenr ) ;
					}
				}
				lenr += a [ r ] ;
			}
		}
	}
	cout << ans << '\n' ;
}

int main ( )
{
	ios :: sync_with_stdio ( false ) ;
	cin . tie ( nullptr ) ;
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
	int T = 1 ;
//	cin >> T ;
	while ( T -- )
	{
		solve ( ) ;
	}
	return 0 ;
}
