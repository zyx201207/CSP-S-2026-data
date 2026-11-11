#include <bits/stdc++.h>
using namespace std;
string c1, c2, z1, z2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> z1 >> c2 >> z2;
	string s = "0000";
	int h;
	bool flg = 0, flgc = 0;
	if (c1 == c2) {
		s[0] = '1';
		flgc = 1;
	}
	if (flgc) {

		if (z1[0] == z2[0] && z1[1] == z2[1]) {
			s[1] = '1';
			flg = 1;
		}
		int a = int(z1[2] - z2[2]);
		if (((z1[2] <= 'C' && z1[2] >= 'A') && (z2[2] > 'C')) || ((z2[2] <= 'C' && z2[2] >= 'A') && (z1[2] > 'C'))) {
			h = 1;
		} else if (flg) {
			if (a <= 3 || a >= -3) {
				s[2] = '1';
			}
			if ( a == 1 || a == -1)
				s[3] = '1';
		}
	}
	cout << s;
	return 0;
}