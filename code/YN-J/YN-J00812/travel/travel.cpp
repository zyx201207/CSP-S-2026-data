#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a[10];
	char b[10];
	int s = 0, d = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> b[i];
	}
	if ((a[0] == b[0]) && (a[1] == b[1])) {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}

	if ((a[2]) == b[2] && a[3] == b[3]) {
		cout << 1;

	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;

	}
	if (a[4] == 'A' || a[4] == 'B' || a[4] == 'C') {
		s = 0;
	} else {
		s = 1;
	}
	if (b[4] == 'A' || b[4] == 'B' || b[4] == 'C') {
		d = 0;
	} else {
		d = 1;
	}

	if (s == d) {
		cout << 1;

		if (s == 1) {
			cout << 1;

		} else {
			if ((a[4] == 'B') || (b[4] == 'B')) {
				cout << 1;
			} else {
				cout << 0;
			}
		}

	} else {
		cout << 0;
		cout << 0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}