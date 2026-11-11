#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int n1 = 10 * (s1[0] - '0') + s1[1] - '0';
	int n2 = 10 * (s2[0] - '0') + s2[1] - '0';
	if (c1 == c2) {
		if (n1 == n2) {
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) {
				if (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1) {
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