#include <bits/stdc++.h>
using namespace std;
char a[17];
char b[17];
char a2[6];
char b2[6];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool fff = 1;
	cin >> a >> a2 >> b >> b2;
	if (a[1] != '1' && b[1] != '1') {
		if (a[0] == '1' && a[1] == '6' || b[0] == '1' && b[1] == '6') {
			cout << "0000";
			return 0;
		} else {
			fff = 1;
		}
	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		if (a[i] == b[i]) {
			fff = 1;
		} else {
			cout << "0000";
			return 0;
		}
	}
	for (int i = 0; i < 2; i++) {
		if (a2[i] == b2[i]) {
			fff = 1;
		} else {
			cout << "1000";
			return 0;
		}
	}
	if ( a2[2] == 'D' && b2[2] == 'C' || a2[2] == 'C' && a2[2] == 'D') {
		cout << "1100";
		return 0;
	} else {
		if (a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C' && b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C' && b2[2] != a2[2]
		   ) {
			fff = 1;
		} else if (a2[2] == 'D' || a2[2] == 'F' && b2[2] == 'D' || b2[2] == 'F' && a2[2] != b2[2] ) {
			fff = 1;
		} else {
			cout << "1100";
			return 0;
		}
	}
	if (a2[2] + 1 == b2[2] + 0 || b2[2] + 1 == a2[2] + 0 || a2[2] == 'D' && b2[2] == 'F' || a2[2] == 'F' && b2[2] == 'D') {
		cout << "1111";
	} else {
		cout << "1110";
	}

	return 0;
}