#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string xa, pa, xb, pb;
	cin >> xa >> pa >> xb >> pb;
	if (xa != xb) {
		cout << "0000";
	} else {
		cout << '1';
		int x = 0, y = 0;
		for (int i = 0; i <= 1; i++) {
			x *= 10;
			x += pa[i] - '0';
			y *= 10;
			y += pb[i] - '0';
		}
		if (x != y) {
			cout << "000";
		} else {
			cout << '1';
			char px = pa[2], py = pb[2];
			if ((px <= 'C' && py >= 'D') || (px >= 'D' && py <= 'C')) {
				cout << "00";
			} else {
				cout << '1';
				int r = px - 'A', t = py - 'A';
				if (abs(r - t) != 1) {
					cout << "0";
				} else {
					cout << '1';
				}
			}
		}
	}

	return 0;
}