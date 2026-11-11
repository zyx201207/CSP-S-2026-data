#include <bits/stdc++.h>
using namespace std;
bool tongpai(string s1, string s2)
{
	char c[3], c1[3];
	for (int i = 0; i < s1.length() - 1; i++)
	{
		c[i] = s1[i];
		c1[i] = s2[i];
		if (c[i] != c1[i])
		{
			return false;
		}
	}
	return true;
}
bool tongce(string s1, string s2)
{
	if (tongpai(s1, s2))
	{
		if (s1[2] <= 'C' && s2[2] <= 'C')
		{
			return true;
		}
		else if (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')
		{
			return true;
		}
	}
	return false;
}
bool xianglin(string s1, string s2)
{
	if (tongce(s1, s2))
	{
		if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	if (!tongpai(s1, s2))
	{
		flag2 = false;
	}
	if (!tongce(s1, s2))
	{
		flag3 = false;
	}
	if (!xianglin(s1, s2))
	{
		flag4 = false;
	}
	cout << flag1 << flag2 << flag3 << flag4;
	return 0;
}