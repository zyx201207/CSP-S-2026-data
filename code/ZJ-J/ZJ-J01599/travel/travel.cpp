#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
string k1, k2;
int l1, l2;

void solve(bool flag)
{
	if (flag)
		putchar('1');
	else
		putchar('0');
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	k1 = s1[0] + s1[1], k2 = s2[0] + s2[1];
	l1 = s1[2] - 'A' + 1, l2 = s2[2] - 'A' + 1;
	solve(c1 == c2);
	solve((c1 == c2) && (k1 == k2));
	solve((c1 == c2) && (k1 == k2) && ((l1 <= 3 && l2 <= 3) || (l1 > 3 && l2 > 3)));
	solve((c1 == c2) && (k1 == k2) && ((l1 <= 3 && l2 <= 3) || (l1 > 3 && l2 > 3)) && abs(l1 - l2) == 1);
	return 0;
}
