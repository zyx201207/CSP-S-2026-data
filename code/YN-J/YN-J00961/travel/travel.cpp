#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2;
	char s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	if (c1 == c1) {
		a = 1;
		cout << a;
	} else {
		cout << a;
	}

	if (c1 == c1) {
		if (s1 == s2) {
			b = 1;
			cout << b;
		}
	} else {
		cout << b;
	}

	if (c1 == c2) {
		if (s1 == s2) {
			if (s1 == 'A' || s1 == 'B' || s1 == 'C') {
				if (s2 == 'A' || s2 == 'B' || s2 == 'C') {
					c = 1;
					cout << c;
				}
			} else if (s1 == 'D' || s1 == 'F') {
				if (s2 == 'D' || s2 == 'F') {
					c = 1;
					cout << c;
				}
			}
		}
	} else {
		cout << c;
	}

	if (c1 == c2) {
		if (s1 == s2) {
			if (s1 == 'A' || s1 == 'B' || s1 == 'C') {
				if (s2 == 'A' || s2 == 'B' || s2 == 'C') {
					if ((s1 == 'A' && s2 == 'B') || (s1 == 'B' && s2 == 'C') || (s1 == 'D' && s2 == 'F') || (s2 == 'A' && s1 == 'B')
					        || (s2 == 'B' && s1 == 'C') || (s2 == 'D' && s1 == 'F')) {
						d = 1;
						cout << d;
					}
				}
			} else if (s1 == 'D' || s1 == 'F') {
				if (s2 == 'D' || s2 == 'F') {
					if ((s1 == 'A' && s2 == 'B') || (s1 == 'B' && s2 == 'C') || (s1 == 'D' && s2 == 'F') || (s2 == 'A' && s1 == 'B')
					        || (s2 == 'B' && s1 == 'C') || (s2 == 'D' && s1 == 'F')) {
						d = 1;
						cout << d;
					}
				}
			}
		}
	} else {
		cout << d;
	}

	return 0;
}