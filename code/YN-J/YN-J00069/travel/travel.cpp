#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string d, c;
	char a[3] = {0};
	char b[3] = {0};
	cin >> d;
	for (int i = 1; i <= 3; i++) {
		cin >> a[i];
	}
	cin >> c;

	for (int j = 1; j <= 3; j++) {
		cin >> b[j];
	}
	if (d == c) {
		cout << 1;
		if (a[1] == b[1] && a[2] == b[2]) {
			cout << 1;
			if (a[3] == 'A' || a[3] == 'B' || a[3] == 'C' && b[3] == 'A' || b[3] == 'B' || b[3] == 'C') {
				cout << 1;
				if (a[3] - b[3] == 1 || b[3] - a[3] == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if (a[3] == 'D' || a[3] == 'F' && b[3] == 'D' || b[3] == 'F') {
				cout << 1;
				if (a[3] - b[3] == 1 || b[3] - a[3] == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0;
				cout << 0;
			}

		} else {
			cout << 0;
			cout << 0;
			cout << 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	//zmjjkk
	return 0;
}