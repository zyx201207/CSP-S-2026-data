#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool check1(string s1,string  s2)
{
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
	{
		if (s2[2] == 'A' ||s2[2] == 'B' || s2[2] == 'C')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (s1[2] == 'D' || s1[2] == 'F')
	{
		if (s2[2] == 'D' || s2[2] == 'F')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool check2(string s1,string s2)
{
	if (s1[2] == 'A' && s2[2] == 'B')
	{
		return true;
	}
	if (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C'))
	{
		return true;
	}
	if (s1[2] == 'C' && s2[2] == 'B')
	{
		return true; 
	}
	if (s1[2] == 'D' && s2[2] == 'F')
	{
		return true;
	}
	if (s1[2] == 'F' && s2[2] == 'D')
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
//	cout << check1(s1,s2) << endl;
	if (c1 == c2)
	{
		cout << "1"; 
	}
	else
	{
		cout << "0"; 
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << "1"; 
	}
	else
	{
		cout << "0";
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check1(s1,s2))
	{
		cout << "1";
	}
	else
	{
		cout << "0"; 
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check1(s1,s2) && check2(s1,s2))
	{
		cout << "1";
	}
	else
	{
		cout << "0"; 
	}
	return 0;
}
