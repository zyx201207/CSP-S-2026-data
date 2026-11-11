#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2, a3, a4;
	int a = 1, b = 1, c = 1;
	cin >> a1 >> a2 >> a3 >> a4;
	if (a1 == a3) {
		cout << 1;
	} else {
		cout << 0;
		a = 0;
	}
	if (a == 1 && a2[0] == a4[0] && a2[1] == a4[1]) {
		cout << 1;
	} else {
		cout << 0;
		b = 0;
	}
	if (a == 1 && a2[2] < 'D' && a4[2] < 'D' && b == 1) {
		cout << 1;
	} else if (a == 1 && a2[2] > 'C' && a4[2] > 'C' && b == 1) {
		cout << 1;
	} else {
		cout << 0;
		c = 0;
	}
	if (a2[2] + 1 == a4[2] || a2[2] - 1 == a4[2] ) {
		if (c == 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
}