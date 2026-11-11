#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
char x, y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> x >> c >> d >> y;
	if (a == c) {
		cout << 1;
		if (b == d) {
			cout << 1;
			if ('A' <= x && x <= 'C' && 'A' <= y && y <= 'C' || 'D' <= x && x <= 'E' && 'D' <= y && y <= 'E') {
				cout << 1;
				if (abs (x - y) == 1) {
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