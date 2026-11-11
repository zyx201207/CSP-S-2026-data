#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("travel.in", "r", stdin);
	freopen("treavl.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int sda, sdb;
	sda = s1[2] - 'A' + 1 ;
	sdb = s2[2] - 'A' + 1 ;
	int c, d;

	if ((sdb >= 1) && (sdb <= 3))
		d = 1;
	else
		d = 2;

	if ((sda >= 1) && (sda <= 3))
		c = 1;
	else
		c = 2;

	string ans = "";

	if (c1 == c2) {

		ans += '1';

		if ((s1[0] == s2[0])
		        && (s1[1] == s2[1])) {
			ans += '1';

			if (c == d) {
				ans += '1';

				if (abs(sda - sdb) == 1) {

					ans += '1';
				} else
					ans += '0';

			} else
				ans += "00";
		} else
			ans += "000";
	} else
		ans += "0000";


	cout << ans;

	return 0;
}
