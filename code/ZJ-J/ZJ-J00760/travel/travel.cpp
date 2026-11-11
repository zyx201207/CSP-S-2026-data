#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> c2 >> s1 >> s2;
	if(c1 == s1)
	{
		cout << 1;
		if(c2[0] == s2[0] && c2[1] == s2[1]) 
		{
			cout << 1;
			if(((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s2[2] == 'D' || s2[2] == 'F') && (c2[2] == 'D' || c2[2] == 'F')))
			{
				cout << 1;
				char c = c2[2], s = s2[2];
				if(s == 'F') s -= 1;
				if(c == 'F') c -= 1;
				if(abs(c - s) == 1)
				{
					cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}