#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool flag = 1;
	if (a == c) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (b[0] == d[0] && d[1] == b[1] && flag == 1) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (((b[2] <= 'C' && d[2] <= 'C') || (b[2] > 'C' && d[2] > 'C')) && flag == 1) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if ((b[2] <= 'C' && d[2] <= 'C') && flag == 1) {
		if (int(abs(b[2] - d[2])) == 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if ((b[2] > 'C' && d[2] > 'C') && flag == 1) {
		if (int(abs(b[2] - d[2])) == 2) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
}