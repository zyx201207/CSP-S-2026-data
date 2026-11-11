#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in" , "w" , stdin) ;
	freopen("travel.out" , "r" , stdout) ;
	string c1 , c2 , s1 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	
	if(c1 == c2)
	{
		cout << 1 ;
	} 
	else
	{
		cout << "0000" ;
		return 0 ;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1 ;
	}
	else
	{
		cout << "000" ;
		return 0 ;
	}
	
	if(s1[2] == 'D')
	{
		if(s2[2] == 'F')
		{
			cout << 11 ;
			return 0;
		}
		cout << "00" ;
	}
	else if(s1[2] == 'F')
	{
		if(s2[2] == 'D')
		{
			cout << 11 ;
			return 0;
		}
		cout << "00" ;
	}
	else if(s1[2] == 'A')
	{
		if(s2[2] == 'B')
		{
			cout << 11 ;
			return 0;
		}
		if(s2[2] == 'C')
		{
			cout << 10 ;
			return 0;
		}
		cout << "00" ;
	}
	else if(s1[2] == 'B')
	{
		if(s2[2] == 'A')
		{
			cout << 11 ;
			return 0;
		}
		if(s2[2] == 'C')
		{
			cout << 11 ;
			return 0;
		}
		cout << "00" ;
	}
	else if(s1[2] == 'C')
	{
		if(s2[2] == 'B')
		{
			cout << 11 ;
			return 0;
		}
		if(s2[2] == 'A')
		{
			cout << 10 ;
			return 0;
		}
		cout << "00" ;
	}
	return 0;
}
