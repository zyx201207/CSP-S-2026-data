#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string aa, ab, ba, bb, xz = "", rz = "";
	cin >> aa >> ab >> ba >> bb;
	if (aa == ba) {
		cout << "1";
		xz = ab[0] + ab[1];
		rz = bb[0] + bb[1];
		if (xz == rz) {
			cout << "1";
			if (ab[2] > 'C' && bb[2] > 'C') {
				if (abs(ab[2] - bb[2]) == 1) {
					cout << "11";
				} else {
					cout << "10";
				}

			} else if (ab[2] <= 'C' && bb[2] <= 'C') {
				if (abs(ab[2] - bb[2]) == 1) {
					cout << "11";
				} else {
					cout << "10";
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