#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		s3 = s1;
		s4 = s2;
		s3.erase(2,2);
		s4.erase(2,2);
		if(s3 != s4)
		{
			cout << "1000";
			return 0;
		}
		else
		{
			if((((s1[2] >= 'A') && (s1[2] <= 'C')) && ((s2[2] >= 'D') && (s2[2] <= 'E'))) || (((s1[2] >= 'D') && (s1[2] <= 'E')) && ((s2[2] >= 'A') && (s2[2] <= 'C'))))
			{
				cout << "1100";
				return 0;
			}
			else
			{
				if(abs((int)(s1[2] - s2[2])) != 1)
				{
					cout << "1110";
					return 0;
				}
				else
				{
					cout << "1111";
					return 0;
				}
			}
		}
	} 
	return 0;
}
