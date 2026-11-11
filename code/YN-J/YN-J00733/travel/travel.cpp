#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, s;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			if (s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A' || s1[2] <= 'E' && s1[2] >= 'D' && s2[2] <= 'E'
			        && s2[2] >= 'D') {
				if (abs(s1[2] - s2[2]) == 1) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}