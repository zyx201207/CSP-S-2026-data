#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
char x[5], y[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << "1";
	else {
		cout << "0" << "0" << "0" << "0";
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		x[i] = s1[i];
		y[i] = s2[i];
	}
	if (x[1] == y[1]) {
		cout << "1";
		if (x[2] == 'F' && y[2] == 'D' || x[2] == 'D' && y[2] == 'F') {
			cout << "1" << "1";
		}
		if ((x[2] == 'C' || x[2] == 'B' || x[2] == 'A') && (y[2] == 'C' || y[2] == 'B' || y[2] == 'A')) {
			cout << "1";
			if ((x[2] == 'A' && y[2] == 'B') || (x[2] == 'B' && y[2] == 'C') || (y[2] == 'A' && x[2] == 'B') || (y[2] == 'B'
			        && x[2] == 'C')) {
				cout << "1";
			} else {
				cout << "0";
			}
		} else {
			cout << "0" << "0";
		}
	} else {
		cout << "0" << "0" << "0";
	}

	return 0;
}