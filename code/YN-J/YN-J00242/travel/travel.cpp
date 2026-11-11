#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string c1, s1, c2, s2;
int ans[5];

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans[1] = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1] ) {
			ans[2] = 1;
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
				ans[3] = 1;
				int a = (int)(s1[2] - 'A'), b = (int)(s2[2] - 'A');
				if (abs(a - b) == 1) {
					ans[4] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout << ans[i];
	}
	return 0;
}
