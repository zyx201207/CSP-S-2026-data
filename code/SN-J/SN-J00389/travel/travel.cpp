//SN-J00389 shijialin xi bei gong ye da xue fu shu zhong xue 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string c1, s1, c2, s2;

int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		if ((s1[0] == s2[0]) && (s1[1] == s2[1]))
		{
			cout << 1;
			char yi = s1[2], er = s2[2];
			if (((yi <= 'C') && (er <= 'C')) || ((yi > 'C') && (er > 'C')))
			{
				cout << 1;
				if ((yi - er == 1) || (er - yi == 1))
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
// 60% jesus
