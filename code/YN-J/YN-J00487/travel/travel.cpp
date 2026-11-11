#include <bits/stdc++.h>
using namespace std;
string a;
string a1;
int  x, x1;
string b, b1;
int t = 1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a;
	cin >> b;
	cin >> a1;
	cin >> b1;
	x = int(b[2]);
	x1 = int (b1[2]);
	if (a == a1) {
		cout << 1;
	}
	if (a != a1) {
		cout << "0000";
		return 0;
	}
	if (a == a1 &&  b[0] == b1[0] && b[1] == b1[1] ) {
		cout << 1;
	} else {
		cout << 0;
	}
	while (t--) {
		if (a != a1) {
			cout << 0;
			break;
		}
		if (x > 67 && x1 <= 67) {
			cout << 0;
			break;
		}
		if (x <= 67 && x1 > 67) {
			cout << 0;
			break;

		}
		if (  b[0] == b1[0] && b[1] == b1[1]) {
			cout << 1;
			break;
		} else {
			cout << 0;
			break;
		}
	}
	b[0] = int(b[0]);
	b[1] = int(b[1]);
	b1[0] = int(b1[0]);
	b1[1] = int(b1[1]);

	if (b[0] == b1[0] && a == a1 ) {
		if (x > 67 && x1 <= 67) {
			cout << 0;
			return 0;
		}
		if (x <= 67 && x1 > 67) {
			cout << 0;
			return 0;
		}
		if (x == x1 + 1 && b[1] == b1[1] ) {
			cout << 1;
			return 0;
		}
		if (x == x1 + 1 && b[1] == b1[1]) {
			cout << 1;
			return 0;
		}
		if (x == x1 - 1 && b[1] == b1[1] ) {
			cout << 1;
			return 0;
		}
		if (x == x1 - 1 && b[1] == b1[1] ) {
			cout << 1;
			return 0;
		}
		if (x == x1  && b[1] == b1[1] + 1 ) {
			cout << 1;
			return 0;
		}
		if (x == x1 && b[1] == b1[1] + 1 ) {
			cout << 1;
			return 0;
		}
		cout << 0;
	} else {
		cout << 0;
	}
	return 0;
}
