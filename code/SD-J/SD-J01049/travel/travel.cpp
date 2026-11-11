#include <bits/stdc++.h>
using namespace std;
string rxiang,rzuo,xxiang,xzuo;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> rxiang >> rzuo >> xxiang >> xzuo;
	if (rxiang != xxiang)
	{
		cout << "0000";
		return 0;
	}
	else 
	{
		cout << "1";
		if ((rzuo[0] - '0') * 10 + (rzuo[1] - '0') != (xzuo[0] - '0') * 10 + (xzuo[1] - '0'))
		{
			cout << "000";
			return 0;
		}
		else 
		{
			cout << "1";
			if ((((rzuo[2] - 'A' + 1) <= 3 && (rzuo[2] - 'A' + 1) >= 1) && ((xzuo[2] - 'A' + 1) >= 1 && (xzuo[2] - 'A' + 1) <= 3)) || (((rzuo[2] - 'A' + 1) <= 5 && (rzuo[2] - 'A' + 1) >= 4) && ((xzuo[2] - 'A' + 1) >= 4 && (xzuo[2] - 'A' + 1) <= 5)))
			{
				cout << "1";
				if (abs((rzuo[2] - 'A') - (xzuo[2] - 'A')) == 1)
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
				cout << "00";
				return 0;
			}
		}
	}
	return 0;
}

