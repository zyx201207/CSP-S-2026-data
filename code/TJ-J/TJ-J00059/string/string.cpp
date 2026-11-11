//string
#include <iostream>
#include <algorithm>
#include <cmath>

std::string reverse1( std::string a )
{
	std::string b = "";
	
	for( int i = a.size() - 1 ; i >= 0 ; i--)
		b += a[i];
	
	return b;
 } 
 
std::string pat( int n , char a)
{
	std::string b = "";
	
	for( int i = 0; i < n ; i++)
		b += a;
	
	return b;
 }
 
//char findd( std::string a )
//{
//	
//	for( int i = a.size() - 1;; i >= 0 ; i--)
//	{
//		if( a[i] != a[i-1])
//		{
//			return a[i];
//		}
//	}
//}
 
struct Pls{
	int m;
	char ddd;
};

Pls pls[200005];

int main()
{
	
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout);
	
	std::string kkk = "";
	
	char lll;
	int n ;
	std::cin >> n;
	
	if( n == 1 )
	{
		std::cout << 0;
		return 0;
	}
	
	for( int i = 0 ; i < n ; i++)
	{
		std::cin >> pls[i].m >> pls[i].ddd;
		kkk += pat( pls[i].m , pls[i].ddd );
	}
	
	if( kkk == reverse1( kkk ))
	{
		std::cout << 0;
		return 0;
	}
	
	std::string lkl = kkk;
	long long sum = 0;
	
	for( int i = 0 ; i < pls[0].m ; i++ , sum++)
	{
		lkl += pls[0].ddd;
		if( lkl == reverse1( lkl ))
		{
			std::cout << sum ;
			return 0;
		}
	}
	
	std::cout << (kkk.size() - pls[n-1].m ) ;
	
	return 0;
 } 
