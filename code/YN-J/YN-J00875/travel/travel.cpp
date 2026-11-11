#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int bb = 0;
	if (c1 != c2) {
		bb = 1;
		cout << "0";
	} else {
		cout << "1";
	}
	if (s1[0] == s2[0] && s1[1] == s2[1] && bb != 1) {
		cout << "1";
		if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D') && bb != 1) {
			cout << "1";
			if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) {
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
	return 0;
}
