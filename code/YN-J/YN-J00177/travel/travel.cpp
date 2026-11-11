#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = (s1[0] - '0') * 10 + (s1[1] - '0');
	int b = (s2[0] - '0') * 10 + (s2[1] - '0');
	int c = (s1[2] - 'A') + 1, d = (s2[2] - 'A') + 1;
	if (c1 == c2) {
		cout << 1;
		if (a == b) {
			cout << 1;
			if ((c <= 3 && d <= 3) || (c >= 4 && d >= 4)) {
				cout << 1;
				if (c == d + 1 || d == c + 1) {
					cout << 1;
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}