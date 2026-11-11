#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1, c2;
	string z1, z2;
	cin >> c1 >> z1 >> c2 >> z2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	int n1 = z1[1] - '0' + z1[0] - '0';
	int n2 = z2[1] - '0' + z2[0] - '0';
	if (n1 == n2) {
		cout << 1;
		if ((z1[2] <= 'C' && z2[2] <= 'C') || (z1[2] >= 'D' && z2[2] >= 'D')) {
			cout << 1;
		} else {
			cout << 0;
			cout << 0;
			return 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if (z1[2] - z2[2] == -1 || z1[2] - z2[2] == 1 ) {
		cout << 1;
	} else {
		cout << 0;
		return 0;
	}
	return 0;
}