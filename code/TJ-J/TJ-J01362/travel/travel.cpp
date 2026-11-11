#include <bits/stdc++.h>
using namespace std;

bool a( int c1, int c2 )
{
	if ( c1 == c2 ) 
	{
		return 1;
	}
	else return 0;
}

bool b( string s1, string s2 )
{
	if ( s1[1] == s2[1]  && s1[2] == s2[2] )
	{ 
		return 1;
	}
	else return 0;
}

bool c( string s1, string s2 )
{
	if ( ( ( s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C' ) && ( s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C' ) ) || ( ( s1[3] == 'D' || s1[3] == 'F' ) && ( s2[3] == 'D' || s2[3] == 'F' ) ) )
	{
		return 1;
	}
	else return 0;
}

bool d ( string s1, string s2 )
{
	if ( ( s1[3] == 'A' && s2[3] == 'B' ) || ( s1[3] == 'B' && s2[3] == 'A' ) || ( s1[3] == 'B' && s2[3] == 'C' ) || ( s1[3] == 'C' && s2[3] == 'B' ) || ( s1[3] == 'D' && s2[3] == 'F' ) || ( s1[3] == 'F' && s2[3] == 'D' ) )
	{
		return 1;
	}
	else return 0;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if ( c1 != c2 )
	{
		cout << "0000";
		return 0;
	}
	if ( a(c1,c2) == 1 )
	{
		cout << "1";
	}
	else 
	{
		cout << "0";
	}
	if ( b(s1,s2) == 1 )
	{
		cout << "1";
	}
	else 
	{
		cout << "0";
	}
	if ( c(s1,s2) == 1 )
	{
		cout << "1";
	}
	else 
	{ 
		cout << "0";
	}
	if ( d(s1,s2) == 1 )
	{
		cout << "1";
	}  
	else 
	{
		cout << "0";
	}
	return 0;
}
