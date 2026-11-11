#include <bits/stdc++.h>
using namespace std;
string t1, s1, t2, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> t1 >> s1 >> t2 >> s2;
	if (t1 != t2)
	{
		cout << "0000";
	}
	else if (s1[0] != s2[0] || s1[1] != s2[1])
	{
		cout << "1000";
	}
	else if (((s1[2] - 'A') <= 2) != ((s2[2] - 'A') <= 2))
	{
		cout << "1100";
	}
	else if (abs(s1[2] - s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
	{
		cout << "1111";
	}
	else
	{
		cout << "1110";
	}
	return 0;
}