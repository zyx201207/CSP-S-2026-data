#include<bits/stdc++.h>
using namespace std ;

int const N = 5e5 + 5 ;

int n ;
long long m , cnt , maxn , mim ;
long long a[N] , b[N] ;

long long check ( long long c )
{
	int yy = -1  ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		if ( a[i] > c )
		{
			yy = i - 1 ;
			break ;
		}
	}
	if ( yy == -1 ) yy = n ;
	long long cnn = 0 , mm = m ;
	for ( int i = yy ; i >= 1 ; i-- )
	{
		if ( mm >= abs ( c - a[i] ) )
		{
			cnn ++ ;	
			mm -= abs ( c - a[i] ) ;	
		}
		else
		{
		
			return cnn ;	
		}
	}
	return cnn ;
}


int main()
{
	
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	
	cin >> n >> m ; 
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i] ;
		maxn = max ( maxn , a[i] ) ;
	}
	mim = a[1] ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		mim = min ( mim , a[i] ) ;
	}
	sort( a + 1 , a + 1 + n ) ;
	if ( maxn <= 100 )
	{
		
		for ( long long i = mim ; i <= maxn ; i++ )
		{
			cnt = max ( cnt , check(i) ) ;
			
		}
		
		cout << cnt << '\n' ;
	}
	else
	{
		long long h = a[2] - a[1] ;
		cout << m / h ;
	}
	return 0 ;
}