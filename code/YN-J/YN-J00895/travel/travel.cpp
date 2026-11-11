#include <bits/stdc++.h>
using namespace std;

int main() {
	foropen("travel.in", "r", stdin;)
	foropen("travel.out", "w", stdout;)
	int a1, a2;
	char b0 = 'A', b1 = 'B', b2 = 'C', b3 = 'D', b4 = 'F', b5, b6;

	int c1, s1 = a1 * b5;
	int c2, s2 = a2 * b6;
	int x, y, z, a;

	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		int x = 1;
	} else {
		int x = 0;
	}

	if (a1 == a2) {
		int y = 1;
	} else {
		int y = 0;
	}

	if ((a1 == a2) && ((b5 == b1 || b5 == b0 || b5 == b2) && (b6 == b0 || b6 == b1 || b6 == b2))) {
		int z = 1;
	} else if ((a1 == a2) && ((b5 == b3 || b5 == b4) && (b6 == b3 || b6 == b4))) {
		int z = 1;
	} else {
		int z = 0;
	}

	if ((b5 == b0 && b6 == b1) || (b5 == b1 && b6 == b2) || (b5 == b3 && b6 == b4)) {
		if (z == 0) {
			int a = 0;
		} else {
			int a = 1;
		}
	}

	cout << x << y << z << a;
	return 0;
}