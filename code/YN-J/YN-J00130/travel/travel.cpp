#include <bits/stdc++.h>
using namespace std;
char a1[3], a2[4], b1[3], b2[4];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++)
		cin >> a1[i];
	for (int i = 1; i <= 3; i++)
		cin >> a2[i];
	for (int i = 1; i <= 2; i++)
		cin >> b1[i];
	for (int i = 1; i <= 3; i++)
		cin >> b2[i];
	if (a1[1] == b1[1] && a1[2] == b1[2]) {
		cout << 1;
		if (a2[1] == b2[1] && a2[2] == b2[2]) {
			if (a2[3] - b2[3] <= 5) {
				cout << 1;
				if (a2[3] == 'A' || a2[3] == 'B' || a2[3] == 'C' && b2[3] == 'A' || b2[3] == 'B' || b2[3] == 'C') {
					cout << 1;
					if (a2[3] - b2[3] == 1) {
						cout << 1;
					} else if (b2[3] - a2[3] == 1) {
						cout << 1;
					} else {
						cout << 0;
					}
				} else if (a2[3] == 'D' || a2[3] == 'E' && b2[3] == 'D' || b2[3] == 'E') {
					cout << 1;
					if (a2[3] - b2[3] == 1) {
						cout << 1;
					} else if (a2[3] > b2[3] || a2[3] - b2[3] == 1) {
						cout << 1;
					} else {
						cout << "00";
					}
				} else {
					cout << "00";
				}
			} else if (b2[3] - a2[3] <= 5) {
				cout << 1;
				if (a2[3] == 'A' || a2[3] == 'B' || a2[3] == 'C' && b2[3] == 'A' || b2[3] == 'B' || b2[3] == 'C') {
					cout << 1;
					if (a2[3] - b2[3] == 1) {
						cout << 1;
					} else if (b2[3] - a2[3] == 1) {
						cout << 1;
					} else {
						cout << 0;
					}
				} else if (a2[3] == 'D' || a2[3] == 'E' && b2[3] == 'D' || b2[3] == 'E') {
					cout << 1;
					if (a2[3] - b2[3] == 1) {
						cout << 1;
					} else if (b2[3] - a2[3] == 1) {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << "00";
				}
			} else {
				cout << "000";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}