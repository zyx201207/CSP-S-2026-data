#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s;
	getline(cin, s);
	char x1[2] = {s[0], s[1]};
	char x2[3] = {s[3], s[4], s[5]};
	char x3[2] = {s[7], s[8]};
	char x4[3] = {s[10], s[11], s[12]};
	int y1 = 1, y2 = 1, y3 = 1, y4 = 1;
	if (x1[0] != x3[0] || x1[1] != x3[1])
		y1 = 0;
	if (y1 == 0 || x2[0] != x4[0] || x2[1] != x4[1])
		y2 = 0;
	if (y2 == 0 || (x2[2] <= 'C' && x4[2] >= 'D') || (x2[2] >= 'D' && x4[2] <= 'C'))
		y3 = 0;
	if (y3 == 0 || abs(x2[2] - x4[2]) != 1)
		y4 = 0;
	cout << y1 << y2 << y3 << y4;
	return 0;
}