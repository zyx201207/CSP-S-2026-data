#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char n1[2], n2[2];
	char k1[3], k2[3];
	cin >> n1[0] >> n1[1] >> k1[0] >> k1[1] >> k1[2];
	cin >> n2[0] >> n2[1] >> k2[0] >> k2[1] >> k2[2];
	if (n1[0] == n2[0] && n1[1] == n2[1]) {
		cout << 1;
		if (k1[0] == k2[0] && k1[1] == k2[1]) {
			cout << 1;
		} else {
			cout << 0;
		}
		if (k1[0] == k2[0] && k1[1] == k2[1]) {
			if ((k1[2] == 'F' || k1[2] == 'D') && (k2[2] == 'F' || k2[2] == 'D')) {
				cout << 1;
			} else if ((k1[2] == 'A' || k1[2] == 'B' || k1[2] == 'C') && (k2[2] == 'A' || k2[2] == 'B' || k2[2] == 'C')) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
		if (k1[0] == k2[0] && k1[1] == k2[1]) {
			if ((k1[2] == 'A' && k2[2] == 'B') || (k1[2] == 'B' && k2[2] == 'A')) {
				cout << 1;
			} else if ((k1[2] == 'B' && k2[2] == 'C') || (k1[2] == 'C' && k2[2] == 'B')) {
				cout << 1;
			} else if ((k1[2] == 'D' && k2[2] == 'F') || (k1[2] == 'F' && k2[2] == 'D')) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}