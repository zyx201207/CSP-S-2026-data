#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool a, b, c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		a = true;
	}
	if (s1[0] + s1[1] == s2[0] + s2[1] && !a) {
		cout << 1;
	} else {
		b = true;
	}
	//cout << b;
	if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' || s1[2] == 'D' && s2[2] == 'F' || s2[2] == 'D'
	        && s1[2] == 'F') && !b && !a) {
		cout << 1;
	} else {
		c = true;
	}
	if (s1[2] == 'D' || s1[2] == 'F') {
		cout << 1;
	} else if ((s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C'
	            && s2[2] == 'B') && !b && !a && !c) {
		cout << 1;
	} else {
		d = true;
	}
	if (a == true) {
		cout << "0000";
	} else if (b == true) {
		cout << "000";
	} else if (c == true) {
		cout << "00";
	} else if (d == true) {
		cout << "0";
	}
	return 0;
}