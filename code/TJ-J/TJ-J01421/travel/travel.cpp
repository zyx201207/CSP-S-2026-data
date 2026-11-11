#include <bits/stdc++.h>
using namespace std;
int a, b;
string a1, b1;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin >> a >> a1 >> b >> b1;
	if (a == b)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (a1[0] == b1[0] && a1[1] == b1[1])
	{
		cout << "1";
	}
	if (a1[0] != b1[0] || a1[0] != b1[0]) 
	{
		cout << "000";
		return 0;
	}
	if (a1[2] == 'A' || a1[2] == 'B' || a1[2] == 'C')
	{
		if (b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C')
		{
			cout << "1";
			if (a1[2] == 'A' && b1[2] == 'B')
			{
				cout << "1";
				return 0;
			}
			if (a1[2] == 'B' && b1[2] == 'C')
			{
				cout << "1";
				return 0;
			}
			if (a1[2] == 'B' && b1[2] == 'A')
			{
				cout << "1";
				return 0;
			}
			if (a1[2] == 'C' && b1[2] == 'B')
			{
				cout << "1";
				return 0;
			}
			if (a1[2] == 'C' && b1[2] == 'A')
			{
				cout << "0";
				return 0;
			}
			if (a1[2] == 'A' && b1[2] == 'C')
			{
				cout << "0";
				return 0;
			}
		}
	}
	else if (a1[2] == 'D' || a1[2] == 'F')
	{
		if (b1[2] == 'D' || b1[2] == 'F')
		{
			cout << "11";
			return 0;
		}
	}
	else{
		cout << "00";
		return 0;
	}
	cout << "00";
	return 0;
}
