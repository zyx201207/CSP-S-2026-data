#include <bits/stdc++.h>
using namespace std;


string ans;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;

	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans += '1';
		string a1, a2;
		a1 = s1[0] + s1[1];
		a2 = s2[0] + s2[1];
		if (a1 == a2) {
			ans += '1';
			if ((s1[2] >= 65 && s1[2] <= 67) && (s2[2] >= 65 && s2[2] <= 67) || (s1[2] == 68 || s1[2] == 70)
			        && (s2[2] == 68 || s2[2] == 70)) {
				ans += '1';
				if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) {
					ans += '1';
				} else {
					ans += '0';
				}
			} else {
				ans += '0';
				ans += '0';
			}
		} else {
			ans += '0';
			ans += '0';
			ans += '0';
		}
	} else {
		ans += '0';
		ans += '0';
		ans += '0';
		ans += '0';
	}

	cout << ans;
	return 0;
}