#include<bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 != b1)
		cout << "0000";
	else
	{
		if (a2[0] == b2[0] && a2[1] == b2[1])
		{
			if (a2[2] <= 'C'&&b2[2] >= 'D' || a2[2] >= 'D'&&b2[2] <= 'C')
				cout << "1100";
			else
			{
				if (abs(a2[2] - b2[2]) == 1 || (a2[2] == 'D' && b2[2] == 'F') || (a2[2] == 'F' && b2[2] == 'D'))
					cout << "1111";
				else cout << "1110";
			}
		}
		else cout << "1000";
	}
	return 0;
}