#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s;
	for (int i = 1; i <= 10; i++) {
		cin >> s[i];
	}
	if (s[1] * 10 + s[2] == s[6] * 10 + s[7]) {
		cout << "1";
		if (s[3] * 10 + s[4] == s[8] * 10 + s[9]) {
			cout << "1";
			if ((('C' >= s[5] && s[5] >= 'A') && ('C' >= s[10] && s[10] >= 'A')) || (('F' >= s[5] && s[5] >= 'D') && ('F' >= s[10]
			        && s[10] >= 'D'))) {
				cout << "1";
				if (abs(s[5] - s[10]) == 1) {
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