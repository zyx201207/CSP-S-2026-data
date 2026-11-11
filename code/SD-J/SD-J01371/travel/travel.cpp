#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			int i = b[2] - 'A';
			int j = d[2] - 'A';
			if (i > 2 && j > 2) {
				cout << "11";
			} else if (i <= 2 && j <= 2) {
				cout << "1";
				if (i + 1 == j || j + 1 == i) {
					cout << "1";
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

