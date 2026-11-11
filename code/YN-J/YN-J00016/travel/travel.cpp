#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s;
	int ans[4];
	char c[11];
	for (int i = 1; i <= 4; i++) {
		cin >> s;
		if (i == 1) {
			c[1] = s[0];
			c[2] = s[1];
		}
		if (i == 2) {
			c[3] = s[0];
			c[4] = s[1];
			c[5] = s[2];
		}
		if (i == 3) {
			c[6] = s[0];
			c[7] = s[1];
		}
		if (i == 4) {
			c[8] = s[0];
			c[9]  = s[1];
			c[10] = s[2];
		}
	}
	if (c[1] == c[6] && c[2] == c[7]) {
		ans[1] = 1;
	} else {
		ans[1] = 0;
	}
	if (c[3] == c[8] && c[4] == c[9] && c[1] == c[6] && c[2] == c[7]) {
		ans[2] = 1;
	} else {
		ans[2] = 0;
	}
	if (c[3] == c[8] && c[4] == c[9] && c[1] == c[6] && c[2] == c[7] && (c[5] == c[10] || c[5] == c[10] + 1
	        || c[5] == c[10] - 1 && c[5] != 'C', c[10] != 'D' || c[5] != 'D', c[10] != 'C')) {
		ans[3] = 1;
	} else {
		ans[3] = 0;
	}
	if (c[4] == c[9] + 1 || c[4] == c[9] - 1 || c[5] == c[10] + 1 || c[5] == c[10] - 1 && (c[5] != 'C', c[10] != 'D'
	        || c[5] != 'D', c[10] != 'C')) {
		ans[4] = 1;
	} else {
		ans[4] = 0;
	}
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}