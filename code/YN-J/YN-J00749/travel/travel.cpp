#include <bits/stdc++.h>
using namespace std;
string r, r1, x, x1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int flag = 0;
	cin >> r >> r1 >> x >> x1;
	if (r == x) {
		cout << "1";
	}
	if (r != x) {
		cout << "0000";
		return 0;
	}
	if (r1[0] == x1[0] && r1[1] == x1[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (r1[2] >= 'A' && r1[2] <= 'C') {
		if (x1[2] >= 'A' && x1[2] <= 'C') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	} else if (r1[2] >= 'D' && r1[2] <= 'F') {
		if (x1[2] >= 'D' && x1[2] <= 'F') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	}
	int n = r1[2] - 'A' + 1;
	int m = x1[2] - 'A' + 1;
	int cnt = abs(n - m);
	if (cnt == 1) {
		cout << "1";
	}
	return 0;
}
