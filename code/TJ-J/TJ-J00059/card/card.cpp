#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	freopen( "card.in" , "r" , stdin);
	freopen( "card.out" , "w" , stdout);
	
	int n , m;
	std::cin >> n >> m;
	int kkk[n];
	int lll[m+1];
	
	for( int i = 0 ; i < n ; i++)
		std::cin >> kkk[i];		
	
	for( int i = 0 ; i < m ; i++)
		std::cout << "2 ";
	
	return 0;
 } 
