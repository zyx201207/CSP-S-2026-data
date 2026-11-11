#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
//新人第一次考csp-j ACplease
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin  >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000" << endl;
		return 0;
	}
	else
	{
		if (s1[0] != s2[0] or s1[1] != s2[1])
		{
			cout << "1000" << endl;
			return 0;
		}
		else
		{
			char ch = s1[2],ch1 = s2[2];
			if (ch == 'D' or ch == 'F')
			{
				if (ch1 == 'D' or ch1 == 'F')
				{
					cout << "1111" << endl;
					return 0;
				}
				else
				{
					cout << "1100" << endl;
					return 0;
				}
			}
			else
			{
				if (ch1 == 'A' or ch1 == 'B' or ch1 == 'C')
				{
					if (ch == 'A')
					{
						if (ch1 == 'B')
						{
							cout << "1111" << endl;
							return 0;
						}
						else
						{
							cout << "1110" << endl;
							return 0;
						}
					}
					else if (ch == 'B')
					{
						cout << "1111" << endl;
						return 0;
					}
					else
					{
						if (ch1 == 'B')
						{
							cout << "1111" << endl;
							return 0;
						}
						else
						{
							cout << "1110" << endl;
							return 0;
						}
					}
				}
				else
				{
					cout << "1100" << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
