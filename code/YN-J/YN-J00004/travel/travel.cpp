#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string x, y;
	cin >> a >> x >> b >> y;
	if (a != b) {
		cout << "0000";
		return 0;
	}
	cout << (a == b);
	int t1 = ((x[0] - '0') * 10 + (x[1] - '0'));
	int t2 = ((y[0] - '0') * 10 + (y[1] - '0'));
	if (t1 == t2) {
		cout << 1;
		if ((x[2] <= 'C' && y[2] <= 'C') || ((x[2] == 'D' || x[2] == 'F') && (y[2] == 'D' || y[2] == 'F'))) {
			cout << 1;
			if (((x[2] == 'D' || x[2] == 'F') && (y[2] == 'D' || y[2] == 'F')) || x[2] - y[2] == 1 || x[2] - y[2] == -1)
				cout << 1;
			else
				cout << 0;
		} else
			cout << 0 << 0 ;
	} else
		cout << "000";

	return 0;
}
