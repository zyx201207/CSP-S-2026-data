#include <bits/stdc++.h>
using namespace std;

struct t {
	int c;
	char s[3];
} a[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		cin >> a[i].c;
		cin >> a[i].s[1] >> a[i].s[2] >> a[i].s[3];
	}
	int s1 = a[1].s[1], s11 = a[1].s[2];
	int s2 = a[2].s[1], s22 = a[2].s[2];
	char p1 = a[1].s[3], p2 = a[2].s[3];
	if (a[1].c == a[2].c) {
		cout << 1;
		if (s1 == s2 && s11 == s22) {
			cout << 1;
			if ((p1 <= 'C' && p2 <= 'C') || (p1 > 'C' && p2 > 'C')) {
				cout << 1;
				if (p1 + 1 == p2) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}