#include <bits/stdc++.h>
using namespace std;

long long s1, s2;
long long a1, a2;
char c1, c2;
long long c3, c4;
long long ans = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin  >> a1 >> s1 >> c1 >> a2 >> s2 >> c2;
	if (c1 == 'A') {
		c3 = 1;
	}
	if (c1 == 'B') {
		c3 = 2;
	}
	if (c1 == 'C') {
		c3 = 3;
	}
	if (c1 == 'D') {
		c3 = 4;
	}
	if (c1 == 'E') {
		c3 = 5;
	}
	if (c2 == 'A') {
		c4 = 1;
	}
	if (c2 == 'B') {
		c4 = 2;
	}
	if (c2 == 'C') {
		c4 = 3;
	}
	if (c2 == 'D') {
		c4 = 4;
	}
	if (c2 == 'E') {
		c4 = 5;
	}

	ans == 0;
	if (a1 == a2) {
		cout << "1";
		ans = 1;
	} else {
		cout << "0";
	}

	if (ans == 1 && s1 == s2) {
		cout << "1";
		ans = 2;
	} else {
		cout << "0";
	}

	if (ans == 2 && c3 <= 3 && c4 <= 3) {
		cout << "1";
		ans = 3;
	} else {
		if (ans == 2 && c3 >= 4 && c4 >= 4) {
			cout << "1";
			ans++;
		} else {
			cout << "0";
		}
	}
	if (ans == 3) {
		if (c3 + 1 == c4) {
			cout << "1";
		} else if (c3 - 1 == c4) {
			cout << '1';
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}
	return 0;
}