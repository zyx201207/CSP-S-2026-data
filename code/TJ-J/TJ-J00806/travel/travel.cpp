#include<bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string a, b;
	string x, y;
	cin >> a >> x >> b >> y;
	if (a != b)
	{
		cout << 0000;
		return 0;
	}
	cout << 1;
	if (x[0] == y[0] && x[1] == y[1])
	{
		cout << 1;
		if ((x[2] >= 'D' && y[2] >= 'D') || (x[2] <= 'C' && y[2] <= 'C'))
		{
			cout << 1;
			if (x[2] - y[2] == 1 || y[2] - x[2] == 1)
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
			cout << 00;
		}
	}
	else
	{
		cout << 000;
	}
	return 0;
}
