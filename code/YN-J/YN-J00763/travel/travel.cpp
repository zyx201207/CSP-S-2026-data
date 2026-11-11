#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s, e, sa, ea, p = "", pa = "", zw = "", zwa = "", ans = "";
	cin >> s >> e >> sa >> ea;
	p = e.substr(0, 2);
	pa = ea.substr(0, 2);
	zw = e.substr(2, 1);
	zwa = ea.substr(2, 1);
//	cout << p << " " << pa << " " << zw << " " << zwa;
//	³µ£¬ÅÅ£¬²à£¬ÏàÁÚ
	if (s == sa) {
		ans += "1";
		if (p == pa) {
			ans += "1";
			if (zw <= "C") {
				if (zwa <= "C") {
					ans += "1";
					char c = zw[0], ca = zwa[0];
					int shu = c - 'A' + 1, sha = ca - 'A' + 1;
					int cnt = abs(shu - sha);
					if (cnt == 1) {
						ans += "1";
					} else {
						ans += "0";
					}
				} else {
					ans += "00";
				}
			} else if (zw >= "D") {
				if (zwa >= "D") {
					ans += "11";
				} else {
					ans += "00";
				}
			}
		} else {
			ans += "000";
		}
	} else {
		ans += "0000";
	}
	cout << ans;
	return 0;
}