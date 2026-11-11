#include <bits/stdc++.h>
using namespace std;
string s, s1, c, c1, k;
char n, m;


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> s1 >> c >> c1;
	n = s1[2];
	m = c1[2];
	if (s[0] == c[0] && s[1] == c[1]) {
		k += '1';
		if (s1[0] == c1[0] && s1[1] == c1[1]) {
			k += '1';

			if (n <= 'C' && m <= 'C') {
				k += '1';
				if (n - m - '1' == 0 || m - n - 1 == 0)
					k += '1';

				else
					k += '0';
			} else if (n >= 'D' && m >= 'D') {
				k += '1';
				k += '1';
			} else {

				k += '0';
				k += '0';
			}
		} else {
			k += '0';
			k += '0';
			k += '0';
		}
	} else {
		k += '0';
		k += '0';
		k += '0';
		k += '0';
	}
	cout << k;
	return 0;
}