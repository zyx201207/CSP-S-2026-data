#include <bits/stdc++.h>
using namespace std;
freopen ("travel.in""r" "stdin");
freopen ("travel.out""w" "stdout");

int main () {
	int a[6][20] = {0}, b[6][20] = {0};
	char c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int sum = 0;
	int h = c1 - '0', t = c2 - '0';
	if (h == t && h > 1 && h <= 17 && h != 16 && t > 01 && t <= 17 && t != 16) {
		cout << "1";
		sum += 1;
	} else {
		cout << "0" << "0" << "0" << "0";
	}

	int d = (c1 - '0') / 10, e = (c2 - '0') / 10;
	if (sum == 1 ) {
		if ( d == e && d > 0 && d <= 18 && d > 0 && d <= 18) {
			cout << "1";
			sum += 1;
		} else {
			cout << "0" << "0" << "0";
		}
	}

	int f = (c1 - '0') % 10, g = (c2 - '0') % 10;
	if (sum == 2 ) {
		if ( (f < g && (f >= 68 || g <= 67)) || (f > g && (g >= 68 || f <= 67))) {
			cout << "1";
		} else {
			cout << "0" ;
		}
	}

	if (sum == 2 ) {
		if (sum == 2 && f + 1 == g || g + 1 == f) {
			cout << "1";
		} else {
			cout << "0" ;
		}
	}
	return 0;
}