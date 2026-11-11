#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	int id1 = s1[2] - 'A', id2 = s2[2] - 'A';
	// A,B,C,D,F
	bool fl1 = (id1 <= 2);
	bool fl2 = (id2 <= 2);
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && fl1 == fl2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && fl1 == fl2)
	{
		if (fl1)
		{
			if (abs(id1 - id2) == 1) cout << 1;
			else cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		cout << 0;
	}
	
	return 0;
}
