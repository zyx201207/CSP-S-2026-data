#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a[5];
	char b[5];
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	cin >> b[1] >> b[2] >> b[3] >> b[4] >> b[5];
	int x = a[5], y = b[5];
	if (a[1] == b[1] && a[2] == b[2]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (a[1] == b[1] && a[2] == b[2] && a[3] == b[3] && a[4] == b[4] ) {
		cout << 1;
		if (a[3] == b[3] && a[4] == b[4] && x >= 65 && x <= 67 && y >= 65 && y <= 67 ) {
			cout << 1;
			if (x + 1 == y || x - 1 == y) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else if  (a[3] == b[3] && a[4] == b[4] && x >= 68 && x <= 69 && y >= 68 && y <= 69 ) {
			cout << 1;
			if (x + 1 == y || x - 1 == y) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0;
	}
	return 0;
}

