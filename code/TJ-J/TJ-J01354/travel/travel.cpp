#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		int a = (s1[0] - '0') * 10 + (s1[1] - '0');
		int b = (s2[0] - '0') * 10 + (s2[1] - '0');
		if (a == b)
		{
			cout << 1;
			if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C')
			{
				cout << 1;
				if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else if (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')
			{
				cout << 11 << endl;
			}
			else
			{
				cout << "00" << endl;
			}
		} 
		else
		{
			cout << "000" << endl;
		}
	}
	else
	{
		cout << "0000" << endl;
	}
	return 0;
}
