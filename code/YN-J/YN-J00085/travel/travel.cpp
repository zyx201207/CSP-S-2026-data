#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2;
	string a, b;
	cin >> a >> s1 >> b >> s2;

	if (a == b) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	int bo = 1;

	for (int i = 0; i < 2; i++) {
		if (s1[i] != s2[i]) {
			bo = 0;
		}
	}

	if (bo != 0) {
		cout << bo;
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C') and (s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C')) {
		cout << 1;
	} else if ((s1[2] == 'D' or s1[2] == 'F') and (s2[2] == 'D' or s2[2] == 'F') ) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}

	if (abs(s1[2] - s2[2]) == 1) {
		cout << 1;


	} else {
		cout << 0;
	}
	return 0;
}