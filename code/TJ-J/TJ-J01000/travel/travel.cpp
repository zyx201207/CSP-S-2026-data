#include <bits/stdc++.h> 
using namespace std;
string a1,b1,a2,b2;
int main()
{
	perfor ("travel.in","r",stdin);
	perfor ("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 == b1)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	int a3 = a2[0] + a2[1];
	int a4 = a2[2];
	int b3 = b2[0] + b2[1];
	int b4 = b2[2];
	if (a3 == b3)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	int a5 = a4 - 'A';
	int b5 = b4 - 'A';
	if (a5 < 3 && b5 < 3)
	{
		cout << 1;
	}
	else if (a5 >= 3 && b5 >= 3)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	if (a5 > b5)
	{
		if (a5 - b5 == 1)
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
		if (b5 - a5 == 1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	return 0;
}
