#include <bits/stdc++.h> 
using namespace std;

int main ()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[2];
	char b = s2[2];
	if (c1 == c2)
	{
		cout << 1 ;
	}
	else 
	{
		cout << 0 ;
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1 ;
	}
	else 
	{
		cout << 0 ;
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((a < 'D' && b < 'D') || (a > 'C' && b > 'C')))
	{
		cout << 1 ;
	}
	else 
	{
		cout << 0 ;
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((a == 'A' && b == 'B'|| b == 'A' && a == 'B' )|| (a == 'B' && b == 'C' || b == 'B' && a == 'C' )|| (a == 'F' && b == 'D' || b == 'F' && a == 'D')))
	{
		cout << 1 ;
	}
	else 
	{
		cout << 0 ;
	}
	return 0 ;
}
