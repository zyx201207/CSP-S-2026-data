#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
string ztt = "0000";

main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;

	if (a != c) {
		cout << ztt;
		return 0;
	} else {
		ztt[0] = '1';

		if (b[0] != d[0] || b[1] != d[1]) {
			cout << ztt;
			return 0;
		} else {
			ztt[1] = '1';
			int x = b[2] - 'A' + 1;
			int y = d[2] - 'A' + 1;

			if ((x > 3 && y <= 3) || (y > 3 && x <= 3)) {
				cout << ztt;
				return 0;
			} else {
				ztt[2] = '1';

				if (x - y == 1 || y - x == 1) {
					ztt[3] = '1';
				} else {
					cout << ztt;
					return 0;
				}
			}
		}
	}

	cout << ztt;

	return 0;
}