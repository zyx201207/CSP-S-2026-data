#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool flag = true;
	if (a == c)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1])
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if (b[2] <= 'C' && d[2] <= 'C')
	{
		cout << "1";
	}
	else if (b[2] >= 'D' && d[2] >= 'D')
	{
	    flag = false;
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if (flag) 
	{
		if (b[2] - 1 == d[2] || b[2] + 1 == d[2])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	else
	{
		if (b[2] - 2 == d[2] || b[2] + 2 == d[2])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	return 0;
}
