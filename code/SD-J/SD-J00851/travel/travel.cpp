#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n1, n2, ans1, ans2;
	string s1, s2;
	cin >> n1 >> s1 >> n2 >> s2;
	ans1 = (s1[0] - 32) * 10 + (s1[1] - 32), ans2 = (s2[0] - 32) * 10 + (s2[1] - 32);
	if (n1 == n2)
	{
		cout << 1;
		if (ans1 == ans2)
		{
			cout << 1;
			if (((s1[2] <= 'C') && (s2[2] <= 'C')) || ((s1[2] >= 'D') && (s2[2] >= 'D')))
			{
				cout << 1;
				if (((s1[2] == 'A') && (s2[2] == 'B')) || ((s1[2] == 'B') && (s2[2] == 'A')) || ((s1[2] == 'B') && (s2[2] == 'C')) || ((s1[2] == 'C') && (s2[2] == 'B')) || ((s1[2] == 'D') && (s2[2] == 'F')) || ((s1[2] == 'F') && (s2[2] == 'D')))
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
