#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" travel.in", "r", stdin);
	freopen(" travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a[0] != c[0] || a[1] != c[1]) {
		cout << "0000";
		return 0;
	}
	if (b[0] - '0' != d[0] - '0' && b[1] - '0' != d[1] - '0') {

		cout << "1000";
		return 0;
	}
	if (b[2] - 'A' <= 3 && d[2] - 'A' > 3) {

		cout << "1100";
		return 0;
	}
	if (b[2] == 'D' || b[2] == 'A') {
		if (b[2] + 1 != d[2]) {
			cout << "1110";
			return 0;
		}
	} else if (b[2] == 'F' || b[2] == 'C') {
		if (b[2] - 1 != d[2]) {
			cout << "1110";
			return 0;
		}
	} else if (b[2] == 'B') {
		if (b[2] - 1 != d[2] && b[2] + 1 != d[2]) {
			cout << "1110";
			return 0;
		}
	}
	cout << "1111";
	return 0;
}