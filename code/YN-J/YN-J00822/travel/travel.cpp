#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s[2], s1[2], n = "0000";
	cin >> s[0] >> s[1] >> s1[0] >> s1[1];

	if (s[0] == s1[0]) {
		n[0] = '1';

		if (s[1][0] == s1[1][0] && s[1][1] == s1[1][1]) {
			n[1] = '1';

			if ((s[1][2] > 'C' && s1[1][2] > 'C') || (s[1][2] <= 'C' && s1[1][2] <= 'C')) {
				n[2] = '1';

				if (s[1][2] + 1 == s1[1][2] || s[1][2] - 1 == s1[1][2]) {
					n[3] = '1';
				}
			} else {
				cout << n;
				return 0;
			}
		} else {
			cout << n;
			return 0;
		}
	} else {
		cout << n;
		return 0;
	}

	cout << n;
	return 0;
}