#include <bits/stdc++.h>
using namespace std;
char c1[2], s1[3], c2[2], s2[3];

int abs(int x) {
	if (x < 0)
		return -x;
	return x;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1[0] >> c1[1] >> s1[0] >> s1[1] >> s1[2] >> c2[0] >> c2[1] >> s2[0] >> s2[1] >> s2[2];
	if (c1[0] != c2[0] || c1[1] != c2[1])
		cout << "0000" << endl;
	else {
		cout << '1';
		if ((s1[0] == s2[0]) && (s1[1] == s2[1])) {
			cout << "1";
			if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'D' || s2[2] == 'E')) ||
			        ((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && (s1[2] == 'D' || s1[2] == 'E')))
				cout << "00";
			else {
				cout << '1';
				if (abs(int(s2[2] - s1[2])) == 1)
					cout << '1' << endl;
				else
					cout << '0' << endl;
			}
		} else
			cout << "000" << endl;
	}
	return 0;
}