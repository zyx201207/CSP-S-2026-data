#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string c1,c2,s1,s2,s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1])
	{
		s+='1';
	}
	else
	{
		s+="0000";
		cout << s;
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		s+='1';
	}
	else
	{
		s+= "000";
		cout << s;
		return 0;
	} 
	if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] <= 'C' && s2[2] >= 'A') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] <= 'F' && s2[2] >= 'D'))
	{
		s += '1';
	}
	else
	{
		s += "00";
		cout << s;
		return 0;
	}
	if (s1[2]-s2[2] == 1 || s1[2] - s2[2] == -1)
	{
		s += '1';
	}
	else
	{
		s += '0';
	}
	cout << s;
	return 0;
}
