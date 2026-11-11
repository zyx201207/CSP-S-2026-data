#include <bits/stdc++.h>
using namespace std;

struct Node {
	string c;
	string s;
} R, X;

void pd4() {
	if (abs(R.s[2] - X.s[2]) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
}

void pd3() {
	if (R.s[2] >= 'A' && R.s[2] <= 'C' && X.s[2] >= 'A' && X.s[2] <= 'C') {
		cout << 1;
		pd4();
	} else if (R.s[2] >= 'D' && R.s[2] <= 'F' && X.s[2] >= 'D' && X.s[2] <= 'F') {
		cout << "11";
	} else {
		cout << "00";
	}
}

void pd2() {
	if (R.s[0] == X.s[0] && R.s[1] == X.s[1]) {
		cout << 1;
		pd3();
	} else {
		cout << "000";
	}
}

void pd1() {
	if (R.c == X.c) {
		cout << 1;
		pd2();
	} else {
		cout << "0000";
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> R.c >> R.s >> X.c >> X.s;
	pd1();
	return 0;
}