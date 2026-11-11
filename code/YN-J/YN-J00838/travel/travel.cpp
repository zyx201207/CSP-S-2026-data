#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travl.in", "r", stdin);
	freopen("travl.out", "w", stdout);
	string s, s_2, c, c_2;
	cin >> s >> c >> s_2 >> c_2;
	int a = c[3], b = c_2[3];
	int d = c[2], e = c_2[2];
	if (s == s_2) {
		if (d == e) {
			if (a == 65 || a == 66 || a == 67 && b == 65 || b == 66 || b == 67) {
				if (a == 68 || a == 69 &&  b == 68 || b == 69) {
					if (a - b == 1 || b - a == 1) {
						cout << "1111";
					} else {
						cout << "1110";
					}
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