#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string a, b, c, d;
	cin >> a >> c >> b >> d;
	if(a == b)
	{
		cout << 1;
		if(c[0] == d[0] && c[1] == d[1])
		{
			cout << 1;
			if(c[2] == 'D' || c[2] == 'F')
			{
				c[2] = 'L';
			}
			else if(c[2] != 'B')
			{
				c[2] = 'R';
			}
			if(d[2] == 'D' || d[2] == 'F')
			{
				d[2] = 'L';
			}
			else if(d[2] != 'B')
			{
				d[2] = 'R';
			}
			
			if(c == d || !(c[2] == 'L' || d[2] == 'L'))
			{
				cout << 1;
				if(c == d || c[2] == 'B' || d[2] == 'B')
				{
					cout << 1;
				}
				else
				{
					cout << 0;
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
