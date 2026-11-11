#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		cout << 1;
	}
	string tmp1 = s1.substr(0, 2);
	string tmp2 = s2.substr(0, 2);
	if (tmp1 != tmp2) {
		cout << "000";
		return 0;
	} else {
		cout << 1;
	}
	char a, b;
	a = s1[2];
	b = s2[2];
	int f = 0;
	if ((a >= 'D' && b >= 'D') || (a < 'D' && b < 'D')) {
		f = 1;
	}
	if (tmp1 != tmp2 || f == 0) {
		cout << "00";
		return 0;
	} else {
		cout << 1;
	}
	if (a < b) {
		swap(a, b);
	}
	if (a - b == 1 && (a != 'D' && b != 'C')) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}