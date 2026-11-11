#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a;
	string b;
	string c;
	string d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	if (a == c) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	bool flag = 0;
	for (int i = 0; i < 2; i++) {
		if (b[i] != d[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if ((b[2] - '0' - 1 == d[2] - '0') || (d[2] - '0' - 1 == b[2] - '0')) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}