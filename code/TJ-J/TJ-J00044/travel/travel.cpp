#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int k;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0]-'0' != c2[0]-'0')
	{
		cout << 0000;
		return 0;
	}
	else
	{
		if(c1[1]-'0' != c2[1]-'0')
		{
			cout << 0000;
			return 0;
		}
		else
		{
			cout << 1;
			if(s1[0]-'0' != s2[0]-'0')
			{
				 cout << 000;
				 return 0;
			}
			else
			{
				if(s1[1]-'0' != s2[1]-'0')
				{
					cout << 000;
					return 0;
				}
				else
				{
					cout << 1;
					if(s1[2]-'A' <= 'C'-'A' && s2[2]-'A' <= 'C'-'A')
					{
						cout << 1;
						if(s1[2] == 'C' && s2[2] == 'B')
						{
							cout << 1;
						}
						else if(s1[2] == 'A' && s2[2] == 'B')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
					else if(s1[2]-'A' > 'C'-'A' && s2[2]-'A' > 'C'-'A')
					{
						cout << 11;
						return 0;
					}
					else
					{
						cout << 00;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
