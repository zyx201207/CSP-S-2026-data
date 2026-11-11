#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1, s1, c2, s2, ans;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans += '1';
		string s3 = s1.substr(0, 2);
		string s4 = s2.substr(0, 2);
		if (s3 == s4) {
			ans += '1';
			if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
				ans += '1';
				if (abs(s1[2] - s2[2]) == 1) {
					ans += '1';
				} else {
					ans += '0';
				}
			} else if ((s1[2] == 'D' || s1[2] == 'F') && (s1[2] == 'D' || s1[2] == 'F')) {
				ans += '1';
				if (abs(s1[2] - s2[2]) == 2) {
					ans += '1';
				} else {
					ans += '0';
				}
			} else {
				cout << "1100";
				return 0;
			}
		} else {
			cout << "1000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}
	cout << ans;
}