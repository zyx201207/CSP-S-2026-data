#include <bits/stdc++.h>
using namespace std;
string c, s, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> c2 >> s2;
	if (c == c2) {
		cout << 1;
		string a = s.substr(0, 2);
		string b = s2.substr(0, 2);
		if (a == b) {
			cout << 1;
			char p = s[2], q = s2[2];
			cout << int(p) - 65 << " " << int(q) - 65 << endl;
			if ((int(p) - 65 <= 2 && int(q) - 65 <= 2) || (int(p) - 65 >= 3 && int(q) - 65 >= 3)) {
				cout << 1;
				if ((p == 'D' && q == 'F') || (p == 'F' && q == 'D')) {
					cout << 1;
				} else {
					if (p + 1 == q || q - 1 == q) {
						cout << 1;
					} else {
						cout << 0;
					}
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