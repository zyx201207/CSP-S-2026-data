#include <bits/stdc++.h>
using namespace std;
string c1, c2;
char a, b, c, d, e, f;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> a >> b >> c >> c2 >> d >> e >> f;

	if (c1 == c2) {
		cout << "1111";

		if (a == d && b == e ) {
			cout << 1;


		} else {
			cout << 0;
		}
		if (a == d && b == e ) {
			if ((c == 'A' || c == 'B' || c == 'C') && (f == 'A' || f == 'B' || f == 'C') ) {
				cout << 1;
			} else if ((c == 'D' || c == 'F') && (f == 'D' || f == 'F')) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
		if (a == d && b == e ) {
			if ((c == 'A' || c == 'B' || c == 'C') && (f == 'A' || f == 'B' || f == 'C') ) {
				if ((c == 'A' && f == 'B') || (c == 'B' && f == 'A') || (c == 'B' && f == 'C') || (c == 'C' && f == 'B')) {
					cout << 1;
				}
			} else if ((c == 'D' || c == 'F') && (f == 'D' || f == 'F')) {
				if ((c == 'D' && f == 'F') || (c == 'F' && f == 'D')) {
					cout << 1;
				}
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	} else {
		cout << "0000";
	}
	return 0;
}