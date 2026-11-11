#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1, s1, c2, s2;
	bool f = false;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2 && c1 != "01" && c1 != "16" && c2 != "01" && c2 != "16")
		cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	for (int i = 0;i < 2;i++)
	{
		if (s1[i] == s2[i])
			f = true;
		else
			f = false;
	}
	if (f)
	{
		cout << 1;
		if (s1[2] == 'A' && s2[2] == 'B')
			cout << "11";
		else if (s1[2] == 'B' && s2[2] == 'C')
			cout << "11";
		else if (s1[2] == 'C' && s2[2] == 'D')
			cout << "00";
		else if (s1[2] == 'D' && s2[2] == 'F')
			cout << "11";
		else if (s2[2] == 'A' && s1[2] == 'B')
			cout << "11";
		else if (s2[2] == 'B' && s1[2] == 'C')
			cout << "11";
		else if (s2[2] == 'C' && s1[2] == 'D')
			cout << "00";
		else if (s2[2] == 'D' && s1[2] == 'F')
			cout << "11";
		else if (s1[2] == 'A' && s2[2] == 'C')
			cout << "10";
		else if (s1[2] == 'C' && s2[2] == 'A')
			cout << "10";
	}
	else
		cout << "000";
	return 0;
}
