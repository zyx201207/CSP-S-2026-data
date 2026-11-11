#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	int st1 = (y1[0] - '0') * 10 + (y1[1] - '0');
	int st2 = (y2[0] - '0') * 10 + (y2[1] - '0');

	if (x1 == x2) {
		cout << 1;
	} else
		cout << 0;

	if (st1 == st2) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (st1 == st2) {
		if (y1[2] - 'A' <= 2 && y2[2] - 'A' <= 2) {
			cout << 1;
		} else
			cout << 0;
	} else {
		cout << 0;
	}
	if (st1 == st2) {
		int f = y1[2], s = y2[2];
		bool ck = 0;
		if ((f == 'D' && s == 'F') || (f == 'F' && s == 'D')) {
			cout << 1;
			ck = 1;
		}
		if (abs(f - s) == 1 && (f - 'A' <= 2 && s - 'A' <= 2)) {
			cout << 1;
			ck = 1;
		}
		if (!ck)
			cout << 0;
	} else
		cout << 0;
	return 0;
}
