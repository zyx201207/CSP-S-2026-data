#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << "1";
		if (s1[0] == s2[0] and s1[1] == s2[1])
		{
			cout << "1";
			bool f1 = (s1[2] <= 'C' ? 0 : 1);
			bool f2 = (s2[2] <= 'C' ? 0 : 1);
			if (f1 == f2)
			{
				cout << "1";
				int a = abs(s1[2] - s2[2]);
				if (a == 1)
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	
	
	
	return 0;
}

