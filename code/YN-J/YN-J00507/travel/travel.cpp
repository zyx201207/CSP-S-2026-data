#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a[1005] = {};
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	if (a[0] - '0' == a[5] - '0' and a[1] - '0' == a[6] - '0') {
		cout << 1;
		if (a[2] - '0' == a[7] - '0' and a[3] - '0' == a[8] - '0') {
			cout << 1;
			if ('A' <= a[4] <= 'C' and 'A' <= a[9] <= 'C') {
				cout << 1;
				if ((a[4] == 'A' and a[9] == 'B') or (a[4] == 'B' and a[9] == 'C') or (a[4] == 'C' and a[9] == 'B') or (a[4] == 'B'
				        and a[9] == 'A')) {
					cout << 1;

				} else {
					cout << 0;

				}
			} else if ('D' <= a[4] <= 'E' and 'D' <= a[9] <= 'E') {
				cout << 1;
				if ((a[4] == 'D' and a[9] == 'E') or (a[4] == 'E' and a[9] == 'D')) {
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
		cout << "0000";
	}



	return 0;
}




