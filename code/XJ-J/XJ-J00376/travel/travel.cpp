#include <bits/stdc++.h>
using namespace std;
int c_1, c_2;
char tmp_1[3], tmp_2[3];
int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	scanf ("%d%s %d%s ", &c_1, &tmp_1, &c_2, &tmp_2);
	string s_1 = tmp_1, s_2 = tmp_2;
	if (c_1 != c_2)
	{
		printf ("0000");
		return 0;
	}
	string p_1 = s_1.substr (0, 2);
	string p_2 = s_2.substr (0, 2);
	if (p_1 != p_2)
	{
		printf ("1000");
		return 0;
	}
	else printf ("11");
	string x = s_1.substr (2, 1);
	string y = s_2.substr (2, 1);
	if (((x == "A" || x == "B" || x == "C") && (y == "A" || y == "B" || y == "C")) || ((x == "D" || x == "F") && (y == "D" || y == "F")))
	{
		printf ("1");
	}
	else
	{
		printf ("00");
		return 0;
	}
	if (((x == "A" && y == "B") || (x == "B" && y == "A")) || ((x == "B" && y == "C") || (x == "C" && y == "B")) || ((x == "D" && y == "F") || (x == "F" && y == "D")))
	{
		printf ("1");
	}
	else printf ("0");
	return 0;
}