#include<bits/stdc++.h>
using namespace std ;

int const N = 2e6 + 5 ;

int c , t ;
int n , k ;
long long d , a[N] , cntt ;

long long f[5005][5005] , cnt[5005][5005] ;

void dfs( long long v , int u , int s )
{
	if ( u > n )
	{
		return  ;
	}
	if ( v == f[s][u] ) cnt[s][u] ++ ;
	for ( int i = u ; i <= n ; i++ )
	{
		if ( a[i] - a[u] <= k )
		{
			dfs ( v + 1 , i + 1 , s ) ;
		}
		dfs ( v + (long long)i - (long long)u , i + 1 , s ) ;
	}
	
}


int main()
{
	
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout ) ;
	
	cin >> c >> t ;
	while ( t-- )
	{
		cntt = 0  ;
		memset( cnt , 0 , sizeof(cnt) ) ;
		cin >> n >> k ;
		for ( int i = 1 ; i <= n ; i++ )
		{
			cin >> a[i] ;
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = i + 1 ; j <= n ; j++ )
			{
				f[i][j]  = j - i ;
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = i + 1 ; j <= n ; j++ )
			{
				f[i][j] = min ( f[i][j-1] + 1 , f[i][j] ) ;
				
				for ( int l = j + 1 ; l <= n ; l++ )
				{
					if ( a[l] - a[j] <= k )
					{
						f[i][l] = min(f[i][j] + 1,f[i][l]) ;
						
					}
				}
			}
		
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			dfs ( 1 , i + 1 , i ) ;
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = i + 1 ; j <= n ; j++ )
			{
				
				if ( cnt[i][j] == 4 )
				{
					cntt ++ ;
				}
			}
		}
	cout << cntt << '\n' ;
	}
	
	return 0 ;
}