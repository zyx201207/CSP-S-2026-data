//by.pcx
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	int flg = 1;
	cin >> a  >> c >> b >> d;
	if (a == b)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (c[0] == d[0] && c[1] == d[1] && flg)
		cout << 1;
	else {
		cout << 0;
		flg = 0;
	}
	if (c[2] >= 'A' && c[2] <= 'C') {
		if (d[2] >= 'A' && d[2] <= 'C' && flg)
			cout << 1;
		else {
			cout << 0;
			flg = 0;
		}
	} else {
		if (d[2] >= 'F' && d[2] <= 'D' && flg)
			cout << 1;
		else {
			cout << 0;
			flg = 0;
		}
	}
	if (flg) {
		if (c[2] == d[2] + 1 || d[2] == c[2] + 1)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	return 0;
}