#include <bits/stdc++.h>
using namespace std;
string s, k;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	cin >> a >> s >> b >> k;
	if (a == b && a != 01 && a != 16 && b != 01 && b != 16) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (s[0] == k[0] && s[1] == k[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (s[2] >= 'A' && s[2] <= 'C') {
		if (k[2] >= 'A' && k[2] <= 'C') {
			cout << "1";
			if (s[2] - k[2] == 1 || k[2] - s[2] == 1) {
				cout << "1";
			} else {
				cout << "0";
			}
		} else {
			cout << "00";
		}
	} else {
		if (k[2] == 'D' || k[2] == 'F') {
			cout << "11";
		}
	}
	return 0;
}
