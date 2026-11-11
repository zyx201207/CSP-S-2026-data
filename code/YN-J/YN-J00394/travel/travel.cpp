#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2;
	string b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1 != a2) {
		cout << "0000";
	} else {
		cout << 1;
		int c1, c2;
		c1 = ('0' - b1[0]) * 10 + ('0' - b1[1]);
		c2 = ('0' - b2[0]) * 10 + ('0' - b2[1]);
		if (c1 != c2) {
			cout << "000";
		} else {
			cout << 1;
			char d1 = b1[2];
			char d2 = b2[2];
			if (d2 < d1) {
				char num = d1;
				d1 = d2;
				d2 = num;
			}
			if (d1 < 'D' && d2 > 'C')
				cout << "00";
			else {
				cout << 1 ;
				if ((d1 == 'C' && d2 == 'D') || (d1 == 'A' && d2 == 'C')) {
					cout << 0;
				} else
					cout << 1;
			}

		}
	}
	return 0;
}