#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	string a;
	string b;
	string c;
	string d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		if ( b[0] == d[0] && b[1] == d[1]) {
			cout << 1;
			if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C') {
				if (d[2] == 'A' || d[2] == 'B' || d[2] == 'C') {
					cout << 1;
					if (b[2] == 'B' || d[2] == 'B') {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << 0 << 0;
				}
			} else {
				if (d[2] == 'D' || d[2] == 'F') {
					cout << 1 << 1;
				} else {
					cout << 0 << 0;
				}
			}
		} else {
			cout << 0 << 0 << 0;
		}
	}  else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}