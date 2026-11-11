#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0' << '0';
		return 0;
	}
	if (b[0] == d[0] and b[1] == d[1]) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0';
		return 0;
	}
	if (b[2] <= 'C' and d[2] <= 'C') {
		cout << '1';
	} else if (b[2] >= 'D' and d[2] >= 'D') {
		cout << '1';
	} else {
		cout << '0' << '0';
		return 0;
	}
	if (b[2] - d[2] == 1 or d[2] - b[2] == 1) {
		cout << '1';
	} else {
		cout << '0';
	}
	return 0;
}