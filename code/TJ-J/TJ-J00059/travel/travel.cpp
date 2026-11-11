#include <iostream>
#include <algorithm>

//a在第几排 
int sss(std::string a)
{
	int o = a[0] - '0';
	int s = a[1] - '0';
	
	return o * 10 + s;
}

//两人是否相邻 
bool iii(std::string a , std::string b)
{
	int a1 = a[2] - 'A' + 1;
	int b1 = b[2] - 'A' + 1;
	
	if( a1 == 1 && b1 == 2)
		return 1;
	else if( a1 == 3 && b1 == 2)
		return 1;
	else if( a1 == 2 && b1 == 3)
		return 1;
	else if( a1 == 2 && b1 == 1)
		return 1;
	else if( a1 == 4 && b1 == 5)
		return 1;
	else if( a1 == 5 && b1 == 4)
		return 1;
	else 
		return 0;	
}

//两人是否在同一侧 
bool kkk( std::string a , std::string b)
{
	int a1 = a[2] - 'A' + 1;
	int b1 = b[2] - 'A' + 1;
	
	if( a1 <= 3 && b1 <= 3) 
		return 1;
	else if( a1 >= 4 && b1 >= 4)
		return 1;
	else return 0;
 } 

int main()
{
	
	freopen( "travel.in" , "r" , stdin);
	freopen( "travel.out" , "w" , stdout);
	
	std::string c1 , c2;
	std::string s1 , s2;
	
	std::cin >> c1 >> s1;
	std::cin >> c2 >> s2;
	
	//两张车票对应的座位是否在同一节车厢
	if( c1 == c2 )
		std::cout << '1';
	else std::cout << '0';
	
	//两张车票对应的座位是否在同一节车厢的同一排
	if( c1 == c2 && sss(s1) == sss(s2) )
		std::cout << '1';
	else std::cout << '0';
	
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	if( c1 == c2 && sss(s1) == sss(s2) && kkk( s1 , s2 ))
		std::cout << '1';
	else std::cout << '0';
	
	//两张车票对应的座位是否相邻
	if( c1 == c2 && sss(s1) == sss(s2) && iii( s1 , s2 ))
		std::cout << '1';
	else std::cout << '0';
	 
	return 0;
 } 
