#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string a1, b1;
	cin >> a >> a1 >> b >> b1;
	if (a == b) {
		cout << '1';
	} else {
		cout << "0000";
		return 0;
	}
	if ((a1[0] - 48) * 10 + (a1[1] - 48) == (b1[0] - 48) * 10 + (b1[1] - 48)) {
		cout << '1';
	} else {
		cout << "000";
		return 0;
	}
	if (a1[2] > 'c' && b1[2] > 'c' || a1[2] < 'd' && b1[2] < 'd') {
		cout << '1';
	} else {
		cout << "00";
	}
	if (max(a1[2], b1[2]) - min(a1[2], b1[2]) == 1) {
		cout << '1';
	} else {
		cout << '0';
	}
	return 0;
}