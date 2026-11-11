// 阮文轩 西北大学附属中学 SN-J00737
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	int f = 0, g = 0, d = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		g++;
	}
	else
		cout << 0;
	if (g && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1;
		d++;
	}
	else
		cout << 0;
	if (d && ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')))
	{
		cout << 1;
		f++;
	}
	else
		cout << 0;
	if (f && abs(s1[2] - s2[2]) == 1 && !(s1[2] == 'D' && s2[2] == 'C'))
		cout << 1;
	else
		cout << 0;
	return 0;
}
