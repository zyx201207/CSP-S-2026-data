#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {

		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			char z1 = s1[2];
			char z2 = s2[2];
			if (z1 >= 65 && z1 <= 67 && z2 >= 65 && z2 <= 67 || z1 >= 68 && z1 <= 70 && z2 >= 68 && z2 <= 70) {
				if (z1 >= 65 && z1 <= 67 && z2 >= 65 && z2 <= 67 && abs(z1 - z2) == 1 || z1 >= 68 && z1 <= 70 && z2 >= 68 && z2 <= 70) {
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