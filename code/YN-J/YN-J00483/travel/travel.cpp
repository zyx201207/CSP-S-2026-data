#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in"."r".in);
	freopen("travel.out"."w".out);
	int ch1, ch2;
	string s, a;
	cin >> ch1 >> s >> ch2 >> a;
	if (ch1 == ch2) {
		cout << '1';
		if (s[1] == a[1] && s[0] == a[0]) {
			if ('A' <= s[2] <= 'F' && 'A' <= a[2] <= 'F') {
				cout << '1';
				if ('A' <= s[2] <= 'C' && 'A' <= a[2] <= 'C' || 'D' <= s[2] <= 'F' && 'D' <= a[2] <= 'F') {
					cout << '1';
					if (s[2] == 'A' && a[2] == 'B' || s[2] == 'B' && a[2] == 'A' || s[2] == 'B' && a[2] == 'C' || s[2] == 'C'
					        && a[2] == 'B' || s[2] == 'C' && a[2] == 'D' || s[2] == 'D' && a[2] == 'C' || s[2] == 'E' && a[2] == 'J' || s[2] == 'J'
					        && a[2] == 'E') {
						cout << '1';
					} else {
						cout << '0';
					}
				} else {
					cout << '0';
				}
			} else {
				cout << '0';
			}
		}
		return 0;
	}
}