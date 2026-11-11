#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c[2];
	int rl1 = 0,rl2 = 0;
	int rr,ll;
	string s1,s2;
	cin >> c[1] >> s1 >> c[2] >> s2;
	if(s1[2] > 'C')
	{
		rl1 = 1;
	}
	if(s2[2] > 'C')
	{
		rl1 = 1;
	}
	if(s1[2] == 'A') rr = 1;
	if(s1[2] == 'B') rr = 2;
	if(s1[2] == 'C') rr = 3;
	if(s1[2] == 'D') rr = 4;
	if(s1[2] == 'F') rr = 5;
	
	if(s2[2] == 'A') ll = 1;
	if(s2[2] == 'B') ll = 2;
	if(s2[2] == 'C') ll = 3;
	if(s2[2] == 'D') ll = 4;
	if(s2[2] == 'F') ll = 5;
	if(c[1] == c[2])
	{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			if(rl1 == rl2)
			{
				cout <<"1";
				if(rl1 == 1)
				{
					cout << "1";
				}
				if(rl1 == 0)
				{
					if(s1[2] == 'A')
					{
						if(s2[2] == 'B') cout << "1";
						else cout << "0";
					}
					if(s1[2] == 'B')
					{
						if(s2[2] == 'A' || s2[2] == 'C') cout << "1";
						else cout << "0";
					}
					if(s1[2] == 'C')
					{
						if(s2[2] == 'B') cout << "1";
						else cout << "0";
					}
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
	else
	{
		cout << "0000";
	}
	return 0;
}
