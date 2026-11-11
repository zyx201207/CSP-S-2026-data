#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	long long a1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	long long a2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (c1 == c2 && a1 == a2) {
		cout << 1;
	} else {
		cout << 0;
	}
	char b1 = s1[2];
	char b2 = s2[2];
	int f = 1;
	if (c1 == c2 && a1 == a2) {
		if (b1 == 'A' || b1 == 'B' || b1 == 'C' && b2 != 'D' && b2 != 'F') {
			cout << 1;
			f = 0;
		}
		if (b1 == 'D' || b1 == 'F' && b2 != 'A' && b2 != 'B' && b2 != 'C') {
			cout << 1;
			f = 0;
		}
		if (f) {
			cout << 0;
		}
	} else {
		cout << 0;
	}
//	cout << b1 << ' ' << b2 << endl;
	if (c1 == c2 && a1 == a2) {
		if (b1 == 'A' && b2 == 'B') {
			cout << 1;
		} else if (b1 == 'B' && b2 == 'A') {
			cout << 1;
		} else if (b1 == 'B' && b2 == 'C') {
			cout << 1;
		} else if (b1 == 'C' && b2 == 'B') {
			cout << 1;
		} else if (b1 == 'D' && b2 == 'F') {
			cout << 1;
		} else if (b1 == 'F' && b2 == 'D') {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
}
