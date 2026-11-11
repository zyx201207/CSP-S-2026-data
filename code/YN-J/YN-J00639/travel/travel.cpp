#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << '1';
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << '1';
			if (int (s1[2]) >= 65 && int (s1[2]) <= 67 && int (s2[2]) >= 65 && int (s2[2]) <= 67 ) {
				cout << '1';
				if (int(s1[2]) - int(s2[2]) == 1 || int(s2[2]) - int(s1[2]) == 1) {
					cout << '1';
				} else {
					cout << '0';
				}
			} else if (int (s1[2]) >= 68 && int (s1[2]) <= 70 && int (s2[2]) >= 68 && int (s2[2]) <= 70) {
				cout << '1';
				if (int (s1[2]) - int(s2[2]) == 2 || int (s2[2]) - int(s1[2]) == 2) {
					cout << '1';
				} else {
					cout << '0';
				}
			} else if (int (s1[2]) >= 67 && int (s1[2]) <= 68 && int (s2[2]) >= 67 && int (s2[2]) <= 68) {
				cout << '0';
				cout << '0';
			} else {
				cout << '0';
				cout << '0';
				cout << '0';
			}
		} else {
			cout << '0';
			cout << '0';
			cout << '0';
		}
	} else {
		cout << '0';
		cout << '0';
		cout << '0';
		cout << '0';
	}
	return 0;
}