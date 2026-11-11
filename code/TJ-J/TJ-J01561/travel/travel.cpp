#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c, d, bz, dz;
	string a1, b1, c1, d1, ans = "";
	cin >> a1 >> b1 >> c1 >> d1;
	a = a1[0] * 10 + a1[1];
	b = b1[0] * 10 + b1[1];
	bz = b1[2] - 'A' + 1;
	c = c1[0] * 10 + c1[1];
	d = d1[0] * 10 + d1[1];
	dz = d1[2] - 'A' + 1;
	if (a == c) {
		if (b == d) {
			if (1 <= bz && 3 >= bz && 1 <= dz && dz <= 3 || bz <= 6 && bz >= 4 && dz >= 4 && dz <= 6) {
				if (!(bz == 1 && dz == 3 || bz == 3 && dz == 1)) {
					cout << "1111";

				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
				return 0;
			}
		} else {
			cout << "1000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}
	return 0;
}

