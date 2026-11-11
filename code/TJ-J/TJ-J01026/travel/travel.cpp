#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << '1';
		int seat1=0,seat2 = 0;
		seat1 = (s1[0] -'0') * 10 + s1[1];
		seat2 = (s2[0] -'0') * 10 + s2[1];
		if(seat1 == seat2)
		{
			cout << '1';
			seat1 = s1[2] - 'A' + 1;
			seat2 = s2[2] - 'A' + 1;
			if(seat1 <= 3 && seat2 <= 3 || (seat1 > 3 && seat2 >3))
			{
				cout << "1";
				int num = seat1- seat2;
				if(num == 1 || num == -1 || (seat1 ==4 && seat2 == 6 || (seat1 == 6 && seat2==4)))
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
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
	else cout << "0000";
	return 0;
}
