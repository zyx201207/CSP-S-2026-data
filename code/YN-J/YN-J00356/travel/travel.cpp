#include <bits/stdc++.h>
using namespace std;

bool s(char x, char y) {
	if (((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')) || ((x == 'D' || x == 'F') && (y == 'D'
	        || y == 'F'))) {
		return true;
	}
	return false;
}

bool b(char x, char y) {
	if (((x == 'A' && y == 'B') || (x == 'B' && y == 'A')) || ((x == 'B' && y == 'C') || (x == 'C' && y == 'B'))
	        || ((x == 'D' && y == 'F') || (x == 'F' && y == 'D'))) {
		return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if (s(s1[2], s2[2])) {
				cout << "1";
				if (b(s1[2], s2[2])) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}