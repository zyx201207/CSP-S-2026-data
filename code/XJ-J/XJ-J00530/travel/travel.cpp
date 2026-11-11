#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	int c, v;
	string s, d;
	cin >> c >> s >> v >> d;
	if(c == v)
	{
		cout << "1";
		if(s[0] == d[0] && s[1] == d[1])
		{
			cout << "1";
			if((s[2] == 'A' && d[2] == 'B') || (s[2] == 'B' && d[2] == 'A') || (s[2] == 'A' && d[2] == 'C') || (s[2] == 'C' && d[2] == 'A') || (s[2] == 'B' && d[2] == 'C') || (s[2] == 'C' && d[2] == 'B') || (s[2] == 'D' && d[2] == 'F') || (s[2] == 'F' && d[2] == 'D'))
			{
				cout << "1";
				if((s[2] == 'A' && d[2] == 'B') || (s[2] == 'B' && d[2] == 'A') || (s[2] == 'B' && d[2] == 'C') || (s[2] == 'C' && d[2] == 'B') || (s[2] == 'D' && d[2] == 'F') || (s[2] == 'F' && d[2] == 'D'))
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
	else
	{
		cout << "0000";
	}
	return 0;
}