#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1, s2, z1, z2;
	cin >> s1 >> z1 >> s2 >> z2;
	if (s1[0] == s2[0] and s1[1] == s2[1])
	{
		cout << "1";
		if (z1[0] == z2[0] and z1[1] == z2[1])
		{
			cout << "1";
			if ((z1[2] == 'A' or z1[2] == 'B' or z1[2] == 'C') and (z2[2] == 'A' or z2[2] == 'B' or z2[2] == 'C'))
			{
				cout << "1";
				{
					if ( (z1[2] == 'A' && z2[2] == 'B') or (z2[2] == 'A' && z1[2] == 'B') or (z1[2] == 'B' && z2[2] == 'C') or (z2[2] == 'B' && z1[2] == 'C') ) 
					{
						cout << "1";
					}
					else
					{
						cout << "0";
					}
				}
				
			}
			else if ((z1[1] == 'D' && z2[2] == 'F') or (z1[1] == 'F' && z2[2] == 'D'))
			{
				cout << "11";
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}