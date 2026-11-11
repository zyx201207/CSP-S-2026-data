#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.cpp","r",stdin);
	freopen("travel.cpp","w",stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	cout << "0000";
	else
	{
		cout << 1;
		if(s1[0] != s2[0] || s1[1] != s2[1])
		cout << "000";
		else
		{
			cout << 1;
			if(s1[2] - 64 <= 3 && s2[2] - 64 <= 3)
			{
				cout << 1;
				if(abs(int(s1[2] - s2[2])) == 1)
				cout << 1;
				else
				cout << 0;
			}
			else
			if(s1[2] - 64 > 3 && s2[2] - 64 > 3)
			cout << "11";
			else
			cout << "00";
		}
	}
	return 0;
}
