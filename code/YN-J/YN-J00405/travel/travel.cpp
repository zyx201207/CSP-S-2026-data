#include <bits/stdc++.h>
using namespace std;
string s, s1, s2, s3, ans;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> s1 >> s2 >> s3;
	if (s == s2) {
		ans += "1";
		if (s1[0] == s3[0] && s1[1] == s3[1]) {
			ans += "1";
			if (s1[2] <= 'C' && s3[2] <= 'C') {
				ans += "1";
				if (abs(s1[2] - s3[2]) == 1 && ((s1[2] != 'C' && s3[2] != 'D') || (s1[2] != 'D' && s3[2] != 'C'))) {
					ans += "1";
				} else {
					ans += "0";
				}
			} else if (s1[2] > 'C' && s3[2] > 'C') {
				ans += "1";
				if (abs(s1[2] - s3[2]) == 1 && ((s1[2] != 'C' && s3[2] != 'D') || (s1[2] != 'D' && s3[2] != 'C'))) {
					ans += "1";
				} else {
					ans += "0";
				}
			} else {
				ans += "0";
			}
		} else {
			ans += "0";
		}
	} else {
		ans += "0";
	}
	while (ans.size() < 4) {
		ans += "0";
	}
	cout << ans;
	return 0;
}