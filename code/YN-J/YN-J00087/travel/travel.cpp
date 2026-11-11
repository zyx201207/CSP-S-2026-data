#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int q = b[0] + b[1];
	int w = d[0] + d[1];

	if (a == c ) {
		cout << 1;

		if (q == w) {
			cout << 1;

			if (((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B'
			        || d[2] == 'C') ) || ( (d[2] == 'D' || d[2] == 'F') && (b[2] == 'D' || b[2] == 'F'))) {
				cout << 1;

				if ((b[2] + 1 == d[2]) || (d[2] + 1 == b[2])) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}

	return 0;
}
