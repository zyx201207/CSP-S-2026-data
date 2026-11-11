#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
bool flag1, flag2, flag3, flag4;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == c3)
		flag1 = true;
	string g, h;
	g += c2[0], g += c2[1];
	h += c4[0], h += c4[1];
	if (g == h && flag1)
		flag2 = true;
	char a = c2[2], b = c4[2];
	if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' && flag2)
		flag3 = true;
	if (a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F' && flag2)
		flag3 = true;
	if (abs(a - b) == 1 && flag3)
		flag4 = true;
	cout << flag1 << flag2 << flag3 << flag4;
	return 0;
}