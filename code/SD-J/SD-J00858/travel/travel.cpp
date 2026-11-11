#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	string n[5] ={"A","B","C","D","F"};
	if (c1 == c2)
	{
		a == "1";
	}
	else if (c1 != c2)
	{
		a == "0";
	}
	else if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		b == "1";
	}
	else if (s1[0] != s2[0]||s1[1] != s2[1])
	{
		b == "0";
	}
	else if (s1[2] == n[0]&&s2[2] == n[1])
	{
		c == "1";
	}
	else if (s1[2] == n[0]&&(s2[2] == n[2])
	{
		c == "1";
	}
	else if (s1[2] == n[1]&&s2[2] == n[2])
	{
		c == "1";
	}
	else if (s1[2] == n[2]&&s2[2] == n[1])
	{
		c == "1";
	}
	else if (s1[2] == n[2]&&s2[2] == n[0])
	{
		c == "1";
	}
	else if (s1[2] == n[1]&&s2[2] == n[0])
	{
		c == "1";
	}
	else if (s1[2] == n[3]&&s2[2] == n[4])
	{
		c == "1";
	}
	else if (s1[2] == n[4]&&s2[2] == n[3])
	{
		c == "1";
	}
	else 
	{
		c == "0";
	}
	else if(s1[2] == n[0] && s1[2] == n[1])
	{
		d == "1";
	}
	else if(s1[2] == n[1] && s1[2] == n[2])
	{
		d == "1";
	}
	else if(s1[2] == n[1] && s1[2] == n[0])
	{
		d == "1";
	}
	else if(s1[2] == n[2] && s1[2] == n[1])
	{
		d == "1";
	}
	else if(s1[2] == n[3] && s1[2] == n[4])
	{
		d == "1";
	}
	else if(s1[2] == n[4] && s1[2] == n[3])
	{
		d == "1";
	}
	else 
	{
		d == "0";
	}
	cout << a+b+c+d << endl;
	return 0; 
}
