#include <bits/stdc++.h>
using namespace std;
int a[5];

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);
	string k, b;
	string s, z;
	cin >> k >> s >> b >> z;
	if (k == b) {
		a[1]++;
	} else {
		for (int t = 1; t <= 4; t++) {
			cout << a[t];
		}
		return 0;
	}
	if (s[0] == z[0] && s[1] == z[1]) {
		a[2]++;
	} else {
		for (int t = 1; t <= 4; t++) {
			cout << a[t];
		}
		return 0;
	}
	if (s[2] <= 'C' && z[2] <= 'C') {
		a[3] = 1;
		if (s[2] - z[2] == 1 || s[2] - z[2] == -1) {
			a[4] = 1;
		}
	} else if (s[2] >= 'D' && z[2] >= 'D') {
		a[3] = 1;
		if (s[2] - z[2] == -2 || s[2] - z[2] == 2) {
			a[4] = 1;
		}
	}
	for (int t = 1; t <= 4; t++) {
		cout << a[t];
	}
	return 0;
}