#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[3];
	char c2[3];
	char s1[4];
	char s2[4];
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if ((s1[2] <= 67 && s2[2] <= 67) || (s1[2] >= 67 && s2[2] >= 67)) {
				cout << 1;
				if ((s1[2] - s2[2]) * (s1[2] - s2[2]) == 1) {
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