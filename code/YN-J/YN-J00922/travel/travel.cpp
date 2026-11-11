#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	char a, b;
	//cin >> c1 >> s1 >> a >> c2 >> s2 >> b;

	if (c1 == c2) {
		cout << "1";
	} else {

		cout << "0000";
		return 0;
	}

	if (s1 == s2) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (a == 'A' || a == 'B' || a == 'C' && b == 'A' || b == 'B' || b == 'C') {
		cout << "1";

		if (a == 'A' && b == 'B' || a == 'B') {
			cout << "1";
		} else {
			cout << "0";
		}
	} else if (a == 'D' || a == 'F' && b == 'D' || b == 'F') {
		cout << "11";
	} else {
		cout << "00";
	}

	return 0;
}