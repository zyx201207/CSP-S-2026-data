#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			bool f1 = false, f2 = false;
			if (s1[2] >= 'D')
				f1 = true;
			if (s2[2] >= 'D')
				f2 = true;
			if (f1 == f2) {
				cout << 1;
				if (f1 == true) {
					cout << 1;
				} else {
					if ((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A')) {
						cout << 0;
					} else {
						cout << 1;
					}
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