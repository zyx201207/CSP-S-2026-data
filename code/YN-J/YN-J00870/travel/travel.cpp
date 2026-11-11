#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2;
	char s1[3], s2[3];
	cin >> c1 >> s1 >> c2 >> s2;
	if (s1[3] - s2[3] == 1 || s2[3] - s1[3] == 1) {
		cout << "1111";
	}
	if (c1 != c2) {
		cout << "0000";
	}
	if (c1 == c2) {
		cout << "1";
		if (s1[1] == s2[1] && s1[2] == s2[2]) {
			cout << "1";
			if (s1[1] != s2[1]) {
				cout << "1000";
			}
			if (s1[3] - s2[3] <= 2 || s2[3] - s1[3] <= 2) {
				cout << "1";
			}
			if (s1[3] = s2[3] > 2 || s2[3] - s1[3] > 2) {
				cout << "1100";
			}
			if (s1[3] - s2[3] == 1 || s2[3] - s1[3] == 1) {
				cout << "1";
			} else {
				cout << "1110";
			}
		}
	}
	return 0;
}