#include <bits/stdc++.h>
using namespace std;
int check_same(string a, string b)
{
	char h = a[2];
	char j = b[2];
	if(h == 'A')
	{
		if(j == 'B')
		{
			return 11;
		}
		if(j == 'C')
		{
			return 10;
		}
	}
	if((h == 'B') && (j == 'A' || j == 'C'))
	{
		return 11;
	}
	if(h == 'C')
	{
		if(j == 'B')
		{
			return 11;
		}
		if(j == 'A')
		{
			return 10;
		}
	}
	if(h == 'D' || h == 'F')
	{
		if(j == 'D' || j == 'F')
		{
			return 11;
		}
	}
	
	return 00;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x_num1, x_num2, y_num1, y_num2;
	cin >> x_num1 >> x_num2 >> y_num1 >> y_num2;
	if(x_num1[0] + x_num1[1] != y_num1[0] + y_num1[1])
	{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	else
	{
		if(x_num2[0]+x_num2[1] != y_num2[0] + y_num2[1])
		{
			cout << 1000;
			return 0;
		}
		else
		{
			if(check_same(x_num2, y_num2) == 11)
			{
				cout << 1111;
			}
			else if(check_same(x_num2, y_num2) == 10)
			{
				cout << 1110;
			}
			else
			{
				cout << 1100;
			}
		}
	}
	
	
	return 0;
}
