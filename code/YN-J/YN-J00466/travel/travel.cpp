#include <bits/stdc++.h>
using namespace std;
int a[6];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2;
	cin >> a1 >> a2;
	string b1, b2;
	cin >> b1 >> b2;
	if (a1 == b1) {
		a[1] = 1;
	} else {
		cout << "0000";
		return 0;
	}
	if (b2[1] == a2[1] && b2[0] == a2[0]) {
		a[2] = 1;
	} else {
		cout << b2[2];
		cout << "1000";
		return 0;
	}
	if ((b2[2] != 'C' && a2[3] != 'D') && (b2[2] != 'D' && b2[2] != 'C')) {
		a[4] = 1;
	} else {
		cout << "1100";
		return 0;
	}
	if (abs(b2[2] - a2[2]) == 1 ) {
		a[3] = 1;
	} else {
		cout << "1110";
		return 0;
	}
	cout << "1111";



	return 0;
}