#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string c, s, ca, sa, ans = "";
	cin >> c >> s >> ca >> sa;

	if (c == ca) {
		ans += '1';
		int f = 1;
		for (int i = 0; i <= 1; i++) {
			if (s[i] != sa[i]) {
				f = 0;
			}
		}
		if (f == 1) {
			ans += '1';
			if ((s[2] <= 'C' && sa[2] <= 'C' && s[2] >= 'A' && sa[2] >= 'A') ||
			        (s[2] <= 'F' && sa[2] <= 'F' && s[2] >= 'E' && sa[2] >= 'E')) {
				ans += '1';
				if (abs(s[2] - sa[2]) == 1) {
					ans += '1';
				} else {
					ans += '0';
				}
			} else {
				ans += "00";
			}
		} else {
			ans += "000";
		}
	} else {
		ans += "0000";
	}
	if ((s[2] <= 'C' && sa[2] <= 'C' && s[2] >= 'A' && sa[2] >= 'A') ||
	        (s[2] <= 'F' && sa[2] <= 'F' && s[2] >= 'E' && sa[2] >= 'E')) {

	}
	cout << ans;
	return 0;
}