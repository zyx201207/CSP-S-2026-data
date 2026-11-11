#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1 ;
	} else {
		cout << 0 << 0 << 0 << 0 << endl;
		return 0;
	}
	int sit_num1 = (b[0] - '0') * 10 + (b[1] - '0');
	int sit_num2 = (d[0] - '0') * 10 + (d[1] - '0');
	char p1 = b[2], p2 = d[2];
	if (sit_num1 == sit_num2) {
		cout << 1 ;
	} else {
		cout << 0 << 0 << 0 << endl;
		return 0;
	}
	if (((p1 <= 'C' && p1 >= 'A') && (p2 <= 'C' && p2 >= 'A')) || ((p1 <= 'F' && p1 >= 'D') && (p2 <= 'F' && p2 >= 'D'))) {
		cout << 1 ;
	} else {
		cout << 0 << 0 << endl;
		return 0;
	}
	if ((p1 - p2 == 1) || (p2 - p1 == 1)) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
		return 0;
	}
	return 0;
}