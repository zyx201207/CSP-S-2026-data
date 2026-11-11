#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	string aa = "", bb = "";
	char ac, bc;
	int at = 0, bt = 0;
	cin >> a >> aa >> b >> bb;
	at = ((int)(aa[0] - '0')) * 10 + ((int)(aa[1] - '0'));
	bt = ((int)(bb[0] - '0')) * 10 + ((int)(bb[1] - '0'));
	ac = aa[2];
	bc = bb[2];
	//cout << at << ' ' << bt;
	if (a == b) {
		cout << '1';
		if (at == bt) {
			cout << '1';
			if (ac <= 'C' && bc <= 'C' || ac >= 'D' && bc >= 'D') {
				cout << '1';
				if (ac <= 'C' && bc <= 'C') {
					if (abs(ac - bc) == 1) {
						cout << '1';
					} else {
						cout << '0';
					}
				} else {
					if ((ac == 'D' || ac == 'F') && (bc == 'D' || bc == 'F')) {
						cout << '1';
					} else {
						cout << '0';
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