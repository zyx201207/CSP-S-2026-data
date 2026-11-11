#include <bits/stdc++.h>
using namespace std;
int c1, c2;
int ss3, ss4;
char s1[3], s2[3];
char s5, s6;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	if (s1[0] == 0) {
		ss3 = int(s1[1] - '0');
	} else {
		ss3 = int(s1[0] - '0') * 10 + int(s1[1] - '0');
	}
	s5 = s1[2];

	if (s2[0] != 0) {
		ss4 = int(s2[0] - '0') * 10 + int(s2[1] - '0');
	} else {
		ss4 = int(s2[1] - '0');
	}
	s6 = s2[2];
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << '1';
		if (ss3 != ss4) {
			cout << "000";
		} else {
			cout << '1';
			if (s5 <= 'C' && s6 >= 'D' || s5 >= 'D' && s6 <= 'C') {
				cout << "00";
			} else {
				cout << '1';
				if (s5 + 1 == s6 || s6 + 1 == s5) {
					cout << '1';
				} else
					cout << '0';
			}
		}
	}
	return 0;
}