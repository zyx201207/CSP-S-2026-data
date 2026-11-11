#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << "1";
		char t1 = s1[0], t2 = s2[0], m1 = s1[1], m2 = s2[1];
		if (t1 != t2 || m1 != m2) {
			cout << "000";
		} else {
			cout << "1";
			char q1 = s1[2], q2 = s2[2];
			if (((q1 == 'A' || q1 == 'B' || q1 == 'C') && (q2 == 'D' || q2 == 'F')) || ((q2 == 'A' || q2 == 'B' || q2 == 'C') && (q1 == 'D' || q1 == 'F'))) {
				cout << "00";
			} else {
				cout << "1";
				if (q1 - q2 == 1 || q1 - q2 == -1) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
		}
	}
	return 0;
}
