#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2;
char s01, s02;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> s01 >> c2 >> s2 >> s02;
	if (c1 == c2) {
		cout << "1";
		if (s1 == s2) {
			cout << "1";
			if ((s01 == 'A' || s01 == 'B' || s01 == 'C') && (s02 == 'A' || s02 == 'B' || s02 == 'C') || (s01 == 'D'
			        || s01 == 'F') && (s02 == 'D' || s02 == 'F')) {
				cout << "1";
				if ((s01 == 'A' || s01 == 'B') && (s02 == 'A' || s02 == 'B') || (s01 == 'B' || s01 == 'C') && (s02 == 'B'
				        || s02 == 'C') || (s01 == 'D' || s01 == 'F') && (s02 == 'D' || s02 == 'F')) {
					cout << "1\n";
				} else {
					cout << "0\n";
				}
			} else {
				cout << "00\n";
			}
		} else {
			cout << "000\n";
		}
	} else {
		cout << "0000\n";
	}
	return 0;
}