#include <bits/stdc++.h>
using namespace std;
string r, rw, x, xw;
int cnt = 0, cnt2 = 0;

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> r >> rw >> x >> xw;

	if (r == x) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	if (rw.substr(0, 2) == xw.substr(0, 2)) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	if (rw.substr(2, 1) == "A" || rw.substr(2, 1) == "B" || rw.substr(2, 1) == "C") {
		cnt++;
	} else {
		cnt2++;
	}

	if (xw.substr(2, 1) == "A" || xw.substr(2, 1) == "B" || xw.substr(2, 1) == "C") {
		cnt++;
	} else {
		cnt2++;
	}

	if (cnt2 == 2) {
		cout << "11";
		return 0;

	} else if (cnt == 2) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}

	if (rw.substr(2, 1) == "A" && xw.substr(2, 1) == "C") {
		cout << "0";
	} else {
		cout << "1";
	}

	return 0;
}