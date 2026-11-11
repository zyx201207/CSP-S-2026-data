#include <iostream>
#include <algorithm>
#include <cmath>

bool cmpp( int a , int b)
{
	return a > b;
}

int a[100000005];

int main()
{
	
	//std::ios::sync_with_j(false);
	//std::cin.tie(0);
	
	freopen( "and.in" , "r" , stdin);
	freopen( "and.out" , "w" , stdout);
	
	int n , m;
	std::cin >> n >> m;
	
	
	
	for( int i = 1 ; i <= n ; i++)
		std::cin >> a[i];
		
	std::sort( a + 1 , a + n + 1 , cmpp);
	
	int sum = a[1] , cnt = a[2];
	
	for( int i = 1 ; i <= m ; i++)
	{
		sum = (sum & a[i]);
	}
	
	for( int i = 2 ; i <= m + 1; i++)
	{
		cnt = (cnt & a[i]);
	}
	
	std::cout << std::max( sum , cnt);
	
	return 0;
 } 
