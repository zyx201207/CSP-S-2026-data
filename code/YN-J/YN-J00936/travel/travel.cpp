#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "r", stdout);
	string a, x, b, y;
	cin >> x >> a >> y >> b;
	if (x == y) {
		cout << 1;
		if (a[0] == b[0] && a[1] == b[1]) {
			cout << 1;
			if (65 <= int(a[2]) && int(a[2]) <= 67 && 65 <= int(b[2]) && int(b[2]) <= 67) {
				cout << 1;
				if (a[2] + 1 == b[2] || a[2] - 1 == b[2]) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if (68 <= int(a[2]) && int(a[2]) <= 69 && 68 <= int(b[2]) && int(b[2]) <= 69) {
				cout << 1;
				if (a[2] + 1 == b[2] || a[2] - 1 == b[2]) {
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
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}