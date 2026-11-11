#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool ans1(char x, char y) {
	if ((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C'))
		return true;
	if (((x == 'D') || (x == 'E')) && ((y == 'D' || y == 'E')))
		return true;
	return false;
}
bool ans2(char x, char y) {
	if (abs(x - y) == 1 && !((x == 3 && y == 4 )|| (x == 4 && y == 3)))
		return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << "1";
	else {
		cout << "0000" << '\n';
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1])
		cout << "1";
	else {
		cout << "000" << '\n';
		return 0;
	}
	if (ans1(s1[2], s2[2]))
		cout << "1";
	else {
		cout << "00" << '\n';
		return 0;
	}
	if (ans2(s1[2], s2[2]))
		cout << "1" << '\n';
	else {
		cout << "0" << '\n';
	}
	return 0;
}
