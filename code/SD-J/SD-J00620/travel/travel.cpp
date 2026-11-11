#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << "1";
		long long a,b;
		a = (s1[0] - '0')* 10 + (s1[1] - '0');
		b = (s2[0] - '0')* 10 + (s2[1] - '0');
		if(a == b)
		{
			cout << "1";
			char c,d;
			c = s1[2];
			d = s2[2];
			if(('A' <=c && c <= 'C') && ('A' <=d && d <= 'C'))
			{
				cout << "1";
				if(c + 1 == d || c - 1== d)
				{
					cout << "1";
					return 0;
				}
				else
				{
					cout << "0";
					return 0;
				}
			}
			else
			{
				if(('D' <=c && c <= 'F') && ('D' <=d && d <= 'F'))
				{
					cout << "11";
					return 0;
				}
				else
				{
					cout << "00";
					return 0;
				}
			}
		}
		else
		{
			cout << "000";
			return 0;
		}
	}
	return 0;
} 
