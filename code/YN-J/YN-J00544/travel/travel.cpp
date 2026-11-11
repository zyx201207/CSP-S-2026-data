#include <bits/stdc++.h>
using namespace std;
string c, s, v, d, rz, xz;
string ans = "";
char sn, sz, p;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> v >> d;
	if (c == v) {
		ans += '1';
		rz += s[0] + s[1];
		xz += d[0] + d[1];
		if (rz == xz) {
			ans += '1';
			char a = s[2];
			char b = d[2];
			if ( a > 'C' || b > 'C') {
				if (a == 'C' || b > 'C') {
					ans += "00";
				} else {
					ans += '1';
					sz = s[2] + 1;
					p += d[2];
					sn = s[2] - 1;
					if (sz == p ) {
						ans += '1';
					} else if (sn == p) {
						ans += '1';
					} else {
						ans += '0';
					}
				}
			} else if (s[2] <= 'C' || d[2] <= 'C') {
				ans += '1';
				sz = s[2] + 1;
				p += d[2];
				sn = s[2] - 1;
				if (sz == p ) {
					ans += '1';
				} else if (sn == p) {
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
		ans = "0000";
	}
	cout << ans;
	return 0;
}