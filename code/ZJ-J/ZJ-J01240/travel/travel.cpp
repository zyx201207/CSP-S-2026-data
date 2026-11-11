#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	bool same = 0;
	if(a1 == b1)
	{
		same = 1;
		cout << "1";
	}
	else cout << "0000";
	if(same)
	{
		if(a2[1] == b2[1])
		{
			cout << "1";
			if((b2[2] >= 'D' and a2[2] >= 'D') or (b2[2] <='C' and a2[2] <= 'C'))
			{
				cout << "1";
				if(a2[2] - b2[2] == 1 or b2[2] - a2[2] == 1)
				{
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	return 0;
}