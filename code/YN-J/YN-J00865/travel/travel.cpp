#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	int c1, s1;
	string c2, s2, c3, s3, c4, s4;
	cin >> c1 >> c2 >> s1 >> s2;
	c4 = c2;
	s4 = s2;
	c3 = c4.erase(2);
	s3 = s4.erase(2);
	if (c1 != s1) {
		cout << '0' << '0' << '0' << '0';
	} else {
		cout << '1';
		if (c3 != s3) {
			cout << '0' << '0' << '0';
		} else {
			cout << '1';
			if (((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
			        || ((c2[2] == 'D' || c2[2] == 'E') && (s2[2] == 'D' || s2[2] == 'E'))) {
				cout << '1';
				if ((c2[2] == 'A' && s2[2] == 'B') || (c2[2] == 'B' && s2[2] == 'A') || (c2[2] == 'B' && s2[2] == 'C') || (c2[2] == 'C'
				        && s2[2] == 'B') || (c2[2] == 'D' && s2[2] == 'E') || (c2[2] == 'E' && s2[2] == 'D')) {
					cout << '1';
				} else {
					cout << '0';
				}
			} else {
				cout << '0' << '0';
			}
		}

	}
	return 0;
}