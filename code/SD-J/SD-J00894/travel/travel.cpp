#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;

string s, t;
string a, b;
map<char, int> mp1;
map<char, int> mp2;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> a;
	cin >> t >> b;
	if(s != t)
	{
		cout << "0000" << endl;
	}
	else
	{
		string x = "", y = "";//×ùÎ»ºÅ
		for(int i = 0; i < 2; i++)
		{
			x += a[i];
			y += b[i];
		} 
		if(x != y)
		{
			cout << "1000" << endl;
		}
		else
		{
			mp1['A'] = 1, mp1['B'] = 2, mp1['C'] = 3;
			mp2['D'] = 1, mp2['F'] = 2;
			if((mp1.find(a[2]) != mp1.end() && mp1.find(b[2]) != mp1.end()) || (mp2.find(a[2]) != mp2.end() && mp2.find(b[2]) != mp2.end()))
			{
				int f = 0;
				if(mp1.find(a[2]) != mp1.end())
				{
					if(abs(mp1[a[2]] - mp1[b[2]]) == 1)
					{
						f = 1;
					}
				}
				if(mp2.find(a[2]) != mp2.end())
				{
					if(abs(mp2[a[2]] - mp2[b[2]]) == 1)
					{
						f = 1;
					}
				}
				if(f)
				{
					cout << "1111" << endl;
				}
				else
				{
					cout << "1110" << endl;
				}
			}
			else
			{
				cout << "1100" << endl;
			}
		}
	}
	return 0;
} 
//
