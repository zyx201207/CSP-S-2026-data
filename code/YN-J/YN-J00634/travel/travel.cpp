#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	string s1, s2;
	cin >> n >> s1 >> m >> s2;
	int a = 0, b = 0;
	for (int i = 0; i < 2; i++) {
		a = a * 10 + (s1[i] - '0'), b = b * 10 + (s2[i] - '0');
	}
	if (n == m) {
		cout << 1;
		if (a == b) {
			cout << 1;
			char x = s1[2], y = s2[2];
			if ((x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C') || (x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F')) {
				cout << 1;
				if (abs(x - y) == 1 || (x >= 'D' && y >= 'D')) {
					cout << 1;
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}