#include <bits/stdc++.h>
using namespace std;
struct seat
{
	string c,s;
} R,X;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> R.c >> R.s >> X.c >> X.s;
	if (R.c != X.c)
	{
		cout << "0000";
	}
	else
	{
		cout << "1";
		if ((R.s[0] + R.s[1]) != (X.s[0] + X.s[1]))
		{
			cout << "000";
		}
		else
		{
			cout << "1";
			if ((R.s[2] <= 'C' && X.s[2] <= 'C') || (R.s[2] >= 'D' && X.s[2] >= 'D'))
			{
				cout << "1";
				if (abs(int(R.s[2] - X.s[2])) == 1)
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
	}
	return 0;
}
