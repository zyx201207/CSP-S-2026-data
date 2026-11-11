#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1, z2, c3, z4;
	cin >> c1 >> z2 >> c3 >> z4;
	int flag1 = 0, flag2 = 0;
	for (int i = 0; i <= 1; i++) {
		if (c1[i] != c3[i]) {
			flag1 = 1;
		}
	}
	if (flag1 == 0) {
		cout << "1";
		for (int i = 0; i <= 1; i++) {
			if (z2[i] != z4[i]) {
				flag2 = 1;
			}
		}
		if (flag2 == 0) {
			cout << "1";
			if (z2[2] == 'C' && z4[2] == 'D') {
				cout << "00";
				return 0;
			} else {
				cout << "1";
				if (abs(z2[2] - z4[2]) == 1) {
					cout << "1";
				} else {
					cout << "0";
					return 0;
				}
			}
		} else {
			cout << "000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}
	return 0;
}

