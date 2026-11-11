#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
// 03 13C 03 13D
signed main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	char zR = s1[2], zX = s2[2];
	if (((zR == 'A' || zR == 'B' || zR == 'C') && (zX == 'D' || zX == 'F')) || ((zX == 'A' || zX == 'B' || zX == 'C') && (zR == 'D' || zR == 'F')))
	{
		cout << "00";
		return 0;
	}
	else {
		cout << 1;
	}
	int p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if ((zR == 'A' && zX == 'B') || (zR == 'B' && zX == 'C') || (zR == 'B' && zX == 'A') || (zR == 'C' && zX == 'B') || (zR == 'D' && zX == 'F') || (zR == 'F' && zX == 'D')) {
		cout << 1;
	}
	else if (p1 == p2 + 1 || p1 == p2 - 1) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}
