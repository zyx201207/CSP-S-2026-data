#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	int flag1 = 0, flag2 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2 && c1 != "01" && c1 != "16") {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if (s1[2] == 'F' || s1[2] == 'D') {
				flag1 = 1;
			}
			if (s2[2] == 'F' || s2[2] == 'D') {
				flag2 = 1;
			}
			if (flag1 == flag2) {
				cout << 1;
				if (flag1 == 1 && flag2 == 1) {
					cout << 1;
				} else if (s1[2] == s1[2] + 1 || s2[2] == s1[2] + 1) {
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