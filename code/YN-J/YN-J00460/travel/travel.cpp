#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string c, d;
	cin >> a >> c >> b >> d;
	int x, y, z, t;
	x = y = z = t = 0;
	if (a == b) {
		x = 1;
	}
	if (x == 1 && c[0] == d[0] && c[1] == d[1]) {
		y = 1;
	}
	if (y == 1 && (c[2] >= 'A' && c[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (c[2] >= 'D' && c[2] <= 'F' && d[2] >= 'D'
	        && d[2] <= 'F')) {
		z = 1;
	}
	if (z == 1) {
		if (c[2] == 'A' && d[2] == 'B')
			t = 1;
		if (c[2] == 'B' && d[2] == 'A')
			t = 1;
		if (c[2] == 'B' && d[2] == 'C')
			t = 1;
		if (c[2] == 'C' && d[2] == 'B')
			t = 1;
		if (c[2] == 'D' && d[2] == 'F')
			t = 1;
		if (c[2] == 'F' && d[2] == 'D')
			t = 1;
	}
	cout << x << y << z << t;
	return 0;
}