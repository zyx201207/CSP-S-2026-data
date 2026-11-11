#include<iostream>
using namespace std;
int main()
{
	int n , n2 , s ;
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	string a[ 200001 ] , a2 ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> n2 >> a2 ;
		s += n2 ;
		int x = 1 ;
		while ( n2 -- )
		{
			a[ x ] = a2 ;
			x ++ ;
		}
	}
	s /= 2 ;
	int dn = 0;
	for ( int i = 1 ; i <= s ; i ++ )
	{
		if( a[ i ] != a[ 2 * s - i + 1 ] ) 
		{
			dn ++ ;
		}
	}
	cout << dn ;
	return 0;
}
