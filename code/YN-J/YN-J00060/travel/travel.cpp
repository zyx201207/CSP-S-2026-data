#include <bits/stdc++.h>
using namespace std;
string c, s, cc, ss;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> cc >> ss;
	char a = s[2];
	char b = ss[2];
	bool flag1 = false;
	bool flag2 = true;
	bool flag3 = false;
	bool flag4 = false;

	if (c == cc) {
		flag1 = true;
		cout << 1;
	} else {
		cout << 0;
	}

	for (int i = 0; i < 2; i++) {

		if (s[i] != ss[i]) {
			flag2 = false;
		}
	}

	if (flag2 == false || flag1 == false) {
		cout << 0;
	} else {
		cout << 1;
	}

	if (a == 'A') {
		if (b == 'B') {
			flag3 = true;
			flag4 = true;
		}

		if (b == 'C') {
			flag3 = true;
		}
	} else if (a == 'B') {
		if (b == 'A' || b == 'C') {
			flag3 = true;
			flag4 = true;
		}
	} else if (a == 'C') {
		if (b == 'B') {
			flag3 = true;
			flag4 = true;
		}

		if (b == 'A') {
			flag3 = true;
		}
	} else if (a == 'D') {
		if (b == 'F') {
			flag3 = true;
			flag4 = true;
		}
	} else if (a == 'F') {
		if (b == 'D') {
			flag3 = true;
			flag4 = true;
		}
	}

	if (flag1 == false || flag2 == false || flag3 == false) {
		cout << 0;
	} else {
		cout << 1;
	}

	if (flag1 == false || flag2 == false || flag3 == false || flag4 == false) {
		cout << 0;
	} else {
		cout << 1;
	}

	return 0;
}