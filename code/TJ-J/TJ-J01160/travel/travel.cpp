#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << '1';
			char h = '0';
			char n = '0';
			if(s1[2] >= 'A' && s1[2] <= 'C')
			{
				if(s2[2] >= 'A' && s2[2] <= 'C')
				{
					h = '1';
					if(s1[2] == s2[2] + 1 || s2[2] == s1[2] + 1)
					{	
						n = '1';
			 		}
				}
			}
			else if(s1[2] == 'D' || s1[2] == 'F')
			{
				if(s2[2] == 'D' || s2[2] == 'F')
				{
					h = '1';
					n = '1';
				}
			}
			cout << h << n;
		}	
		else
		{
			cout << "1000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
} 
