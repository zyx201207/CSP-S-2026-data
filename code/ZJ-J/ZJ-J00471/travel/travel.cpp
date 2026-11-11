#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> s1 >> s2;
	if (c1 == s1) {
		cout << "1";
		if (c2[0] == s2[0] && c2[1] == s2[1]) {
			cout << "1";
			int c = c2[2], s = s2[2];
			if ((c >= 'A' && c <= 'C' && s >= 'A' && s <= 'C') || (c >= 'D' && c <= 'E' && s >= 'D' && s <= 'E')) {
				cout << "1";
				if ((c2[2] == 'A' && s2[2] == 'B')
				 || (s2[2] == 'A' && c2[2] == 'B')
				 || (c2[2] == 'B' && s2[2] == 'C')
				 || (s2[2] == 'B' && c2[2] == 'C')
				 || (c2[2] == 'D' && s2[2] == 'E')
				 || (s2[2] == 'D' && c2[2] == 'E')) {
					cout << "1\n";
				} else {
					cout << "0\n";
				}
			} else {
				cout << "00\n";
			}
		} else {
			cout << "000\n";
		}
	} else {
		cout << "0000\n";
	}
	return 0;
}
