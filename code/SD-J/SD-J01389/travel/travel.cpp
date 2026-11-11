#include<bits/stdc++.h>
using namespace std;
bool check1(string x,string y)
{
	return (x[0] == y[0] && x[1] == y[1]);
}
bool check2(string x,string y)
{
	return ((x[2] <= 'C' && y[2] <= 'C') || (x[2] > 'C' && y[2] > 'C'));
}
bool check3(string x,string y)
{
	return (abs(x[2]-y[2]) == 1);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << 1;
		if (check1(b,d))
		{
			cout << 1;
			if (check2(b,d))
			{
				cout << 1;
				if (check3(b,d))
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
