#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[2], t[2];

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s[0] >> s[1] >> t[0] >> t[1];
	if (s[0] != t[0]) {
		cout << "0000\n";
	} else {
		for (int i = 0; i < 2; i++) {
			if (s[1][i] != t[1][i]) {
				cout << "1000\n";
				return 0;
			}
		}
		int num1 = 0, num2 = 0;
		if ('A' <= s[1][2] && s[1][2] <= 'C') {
			num1 = 1;
		}
		if ('A' <= t[1][2] && t[1][2] <= 'C') {
			num2 = 1;
		}
		if (num1 != num2) {
			cout << "1100\n";
			return 0;
		}
		if ((s[1][2] != 'C' || t[1][2] != 'A') && (s[1][2] != 'A' || t[1][2] != 'C')) {
			cout << "1111\n";
		} else {
			cout << "1110\n";
		}
	}
	return 0;
}