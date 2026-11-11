#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1, s2, s3, s4, z1, z2;
bool ans1, ans2, ans3, ans4;
char c1, c2;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		ans1 = 1;
		z1 = s2[0] + s2[1], z2 = s4[0] + s4[1];
		if (z1 == z2) {
			ans2 = 1;
			c1 = s2[2];
			c2 = s4[2];
			if (c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C') {
				ans3 = 1;
			} else if (c1 >= 'D' && c1 <= 'F' && c2 >= 'D' && c2 <= 'F') {
				ans3 = 1;
			} else
				ans3 = 0;
			if ((c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D')) {
				ans4 = 1;
			} else if (c1 != 'D' && c2 != 'D' && c1 != 'F' && c2 != 'F') {
				int cz = abs((int)(c1 - c2));
				if (cz == 1) {
					ans4 = 1;
				} else
					ans4 = 0;
			} else
				ans4 = 0;
		} else
			ans2 = 0, ans3 = 0, ans4 = 0;
	} else
		ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}