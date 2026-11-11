#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x = 0;
int c, c1;
int z, y;
char zw, w;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> z >> zw >> c1 >> y >> w;

	if (c == c1) {
		x += 1000;
	} else {
		cout << "0000";
		return 0;
	}

	if (z == y) {
		x += 100;

		if (zw == 'A') {
			if (w == 'B') {
				x += 11;
			}

			if (w == 'C') {
				x += 10;
			}
		}

		if (zw == 'B') {
			if (w == 'A' || w == 'C') {
				x += 11;
			}
		}

		if (zw == 'C') {
			if (w == 'A') {
				x += 10;
			}

			if (w == 'B') {
				x += 11;
			}
		}

		if (zw == 'D') {
			if (w == 'F') {
				x += 11;
			}
		}

		if (zw == 'F') {
			if (w == 'D') {
				x += 11;
			}
		}
	}

	if (!x) {
		cout << "0000";
	} else {
		cout << x;
	}

	return 0;
}