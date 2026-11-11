#include <bits/stdc++.h>
using namespace std;
#define int long long
char a, aa, b, bb, c;
char x, xx, y, yy, z;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> aa >> b >> bb >> c;
	cin >> x >> xx >> y >> yy >> z;
	if (a != x || aa != xx) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (b != y || bb != yy) {
		cout << "000";
		return 0;
	}
	cout << 1;
	if (c <= 'C' && z > 'C') {
		cout << "00";
		return 0;
	}
	if (z <= 'C' && c > 'C') {
		cout << "00";
		return 0;
	}
	cout << 1;
	if (c <= 'C') {
		if (c == 'A' && z == 'B') {
			cout << 1;
			return 0;
		}
		if (c == 'B' && z == 'C') {
			cout << 1;
			return 0;
		}
	}
	if (c == 'D' && z == 'F') {
		cout << 1;
		return 0;
	}
	if (z <= 'C') {
		if (z == 'A' && c == 'B') {
			cout << 1;
			return 0;
		}
		if (z == 'B' && c == 'C') {
			cout << 1;
			return 0;
		}
	}
	if (z == 'D' && c == 'F') {
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}
