#include <bits/stdc++.h>
using namespace std;

bool check(char a, char b) {
	if (a >= 'A' && a <= 'C') {
		if (b >= 'A' && b <= 'C') {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (b >= 'A' && b <= 'C') {
			return 0;
		} else {
			return 1;
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, ans;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		ans[1] = '1';

		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans[2] = '1';

			if (check(s1[2], s2[2])) {
				ans[3] = '1';

				if (abs(int(s1[2]) - int(s2[2])) == 1) {
					ans[4] = '1';
				} else {
					ans[4] = '0';
				}
			} else {
				ans[3] = '0';
				ans[4] = '0';
			}
		} else {
			ans[2] = '0';
			ans[3] = '0';
			ans[4] = '0';
		}
	} else {
		ans[1] = '0';
		ans[2] = '0';
		ans[3] = '0';
		ans[4] = '0';
	}

	for (int i = 1; i <= 4; i++) {

		cout << ans[i];
	}

	return 0;
}
