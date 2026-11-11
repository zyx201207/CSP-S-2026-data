#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;

int f1 = 0, f2 = 0, f3 = 0, f4 = 0;


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1  >> s1 >> c2  >> s2;
	if (c1 == c2) {
		cout << 1;
		f1 = 1;
	} else {
		cout << 0;
	}
	char x = s1[2], y = s2[2];
	if (f1 == 1 && ((s1[0] == s2[0]) && (s1[1] == s2[1]))) {
		cout << 1;
		f2 = 1;
	} else {
		cout << 0;
	}
	if (f2 == 1 && ((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')) || (x == 'D' || x == 'F')
	        && (y == 'D' || y == 'F')) {
		cout << 1;
		f3 = 1;
	} else {
		cout << 0;
	}
	if ((x == 'B' && y == 'A') || (x == 'C' && y == 'B') || (x == 'F' && y == 'D')) {
		f4 = 1;
	}
	if (f3 == 1 && f4 == 1 && (x == 'A' && y == 'B') || (x == 'B' && y == 'C') || (x == 'D' && y == 'F')) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}