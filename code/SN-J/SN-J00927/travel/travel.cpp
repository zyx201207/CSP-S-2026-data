#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> a1 >> b >> b1;
	if(a == b)
	{
		cout << "1";
		if(a1[0] == b1[0] && a1[1] == b1[1])
		{
			cout << "1";
			if(a1[2] == 'A')
			{
				if(b1[2] == 'B')
					cout << "11";
				else if(b1[2] == 'C')
					cout << "10";
				else
					cout << "00";
			}
			else if(a1[2] == 'B')
			{
				if(b1[2] == 'A')
					cout << "11";
				else if(b1[2] == 'C')
					cout << "11";
				else
					cout << "00";
			}
			else if(a1[2] == 'C')
			{
				if(b1[2] == 'B')
					cout << "11";
				else if(b1[2] == 'A')
					cout << "10";
				else
					cout << "00";
			}
			else if(a1[2] == 'D')
			{
				if(b1[2] == 'E')
					cout << "11";
				else
					cout << "00";
			}
			else if(a1[2] == 'E')
			{
				if(b1[2] == 'D')
					cout << "11";
				else
					cout << "00";
			}
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
}
