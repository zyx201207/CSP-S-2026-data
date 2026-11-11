#include <bits/stdc++.h>
using namespace std;
string ac, as, bc, bs;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	if (ac == bc) {
		cout << "1";
		if (as[0] == bs[0] && as[1] == bs[1]) {
			cout << "1";
			if (((as[2] != 'F' && as[2] != 'D') && (bs[2] != 'F' && bs[2] != 'D')) || ((as[2] == 'F' || as[2] == 'D')
			        && (bs[2] == 'F' || bs[2] == 'D'))) {
				cout << "1";
				if ((as[2] == 'A' && bs[2] == 'C') || (as[2] == 'C' && bs[2] == 'A')) {
					cout << "0";
				} else {
					cout << "1";
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