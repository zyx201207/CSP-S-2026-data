#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool sh = true;
	int a = (c1[0] - '0');
	int b = (c2[0] - '0');
	int c = (c1[1] - '0');
	int d = (c2[1] - '0');
	if (a == b && c == d) {
		cout << 1;
	} else {
		cout << 0;
		sh = false;
	}
	int a1 = (s1[0] - '0');
	int b1 = (s2[0] - '0');
	int c4 = (s1[1] - '0');
	int d1 = (s2[1] - '0');
	if (sh == true) {
		if (a1 == b1 && c4 == d1) {
			cout << 1;
		} else {
			sh = false;
			cout << 0;
		}

	} else {
		sh = false;
		cout << 0;
	}
	int j2 = s1[2] - '0' - 17;
	int j1 = s2[2] - '0' - 17;
	if (sh == true) {
		if (j1 <= 2 && j2 <= 2) {
			cout << 1 ;
		} else if (j1 > 2 && j2 > 2) {
			cout << 1;
		} else {
			sh = false;
			cout << 0;
		}
	} else {
		sh = false;
		cout << 0;
	}
	if (sh == true) {
		if (abs(j1 - j2) == 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
}