#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f1(char s12, char s22)
{
	if(s12 == 'A' || s12 == 'B' || s12 == 'C')
	{
		if(s22 == 'A' || s22 == 'B' || s22 == 'C')
		{
			return true;
		}
		return false;
	}
	else
	{
		if(s22 == 'D' || s22 == 'F')
		{
			return true;
		}
		return false;
	}
}
bool f2(char s12, char s22)
{
	if(s12 == 'A' && s22 == 'B')
	{
		return true;
	}
	if(s12 == 'B' && (s22 == 'A' | s22 == 'C'))
	{
		return true;
	}
	if(s12 == 'C' && s22 == 'B')
	{
		return true;
	}
	if(s12 == 'D' && s22 == 'F')
	{
		return true;
	}
	if(s12 == 'F' && s22 == 'D')
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
	}
	else
	{
		cout << 1;
		if(s1[0] != s2[0] || s1[1] != s2[1])
		{
			cout << "000";
		}
		else
		{
			cout << 1;
			if(!f1(s1[2], s2[2]))
			{
				cout << "00";
			}
			else
			{
				cout << 1;
				if(f2(s1[2], s2[2]))
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
	}
	return 0;
}
