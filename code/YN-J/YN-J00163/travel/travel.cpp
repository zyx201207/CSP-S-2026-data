#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a;
	string b;
	string a_zw;
	string b_zw;
	cin >> a >> a_zw;
	cin >> b >> b_zw;

	if (a == b) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (a_zw[1] == b_zw[1] && a == b && a_zw[2] == b_zw[2]) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (a == b && a_zw == b_zw) {
		if ((a_zw[3] == 'A' && b_zw[3] == 'B') || (a_zw[3] == 'B' && b_zw[3] == 'A')) {
			cout << "1";
		} else if ((a_zw[3] == 'B' && b_zw[3] == 'C') || (a_zw[3] == 'C' && b_zw[3] == 'B')) {
			cout << "1";
		} else if ((a_zw[3] == 'A' && b_zw[3] == 'C') || (a_zw[3] == 'C' && b_zw[3] == 'A')) {
			cout << "1";
		} else if ((a_zw[3] == 'E' && b_zw[3] == 'D') || (a_zw[3] == 'D' && b_zw[3] == 'E')) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}

	if (a == b && a_zw == b_zw) {
		if ((a_zw[3] == 'A' && b_zw[3] == 'B') || (a_zw[3] == 'B' && b_zw[3] == 'A')) {
			cout << "1";
		} else if ((a_zw[3] == 'B' && b_zw[3] == 'C') || (a_zw[3] == 'C' && b_zw[3] == 'B')) {
			cout << "1";
		} else if ((a_zw[3] == 'D' && b_zw[3] == 'E') || (a_zw[3] == 'E' && b_zw[3] == 'D')) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}

	return 0;
}