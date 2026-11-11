#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1!=c2)
		cout << "0000";
	else
	{
		if (s1[0]==s2[0] && s1[1]==s2[1])
		{
			int a=s1[2]-'A',b=s2[2]-'A';
			if (a<=2 && b<=2)
			{
				if (a+1==b || a-1==b)
					cout << 1111;
				else
					cout << 1110;
			}
			else if (a>=3 && b>=3)
			{
				if (a+1==b || a-1==b)
					cout << 1111;
				else
					cout << 1110;
			}
			else
				cout << 1100;
		}
		else
			cout << 1000;
	}
	return 0;
}
