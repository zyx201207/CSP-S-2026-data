#include <bits/stdc++.h>
using namespace std;
char x1[5],  q1[5], x2[5], q2[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		cin >> x1[i];
	}
	for (int i = 1; i <= 3; i++) {
		cin >> q1[i];
	}
	for (int i = 1; i <= 2; i++) {
		cin >> x2[i];
	}
	for (int i = 1; i <= 3; i++) {
		cin >> q2[i];
	}
	if (x1[1] == x2[1] && x2[2] == x1[2]) {

		cout << '1';

	} else {

		cout << '0' << '0' << '0' << '0';
		return 0;
	}
	if (q1[1] == q2[1] && q2[2] == q1[2]) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0';
		return 0;
	}
	if ((q1[3] == 'A' || q1[3] == 'B' || q1[3] == 'C') && (q2[3] == 'A' || q2[3] == 'B' || q2[3] == 'C')) {
		cout << '1';
		if (q1[3] == 'A' && q2[3] == 'B') {
			cout << '1';
		} else if (q1[3] == 'B' && q2[3] == 'A') {
			cout << '1';
		} else if (q1[3] == 'B' && q2[3] == 'C') {
			cout << '1';
		} else if (q1[3] == 'C' && q2[3] == 'B') {
			cout << '1';
		} else {
			cout << '0';
		}
		return 0;
	}
	if ((q1[3] == 'D' || q1[3] == 'F') && (q2[3] == 'D' || q2[3] == 'F')) {
		cout << '11';
		return 0;
	}


	cout << '0' << '0';
	return 0;
}
