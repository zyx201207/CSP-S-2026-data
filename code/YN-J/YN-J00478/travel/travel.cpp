#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string tmp1, tmp2;
	for (int i = 0; i < 2; i ++) {
		tmp1 += s1[i];
		tmp2 += s2[i];
	}
	if (c1 == c2) {
		cout << "1";
		if (tmp1 == tmp2) {
			cout << "1";
			if ( ((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'F')
			        && (s2[2] >= 'D' && s2[2] <= 'F')) ) {
				cout << "1";
				if ((s1[2] + 1 == s2[2]) || (s1[2] - 1 == s2[2])) {
					cout << "1";
				} else
					cout << "0";
			} else
				cout << "00";
		} else
			cout << "000";

	} else
		cout << "0000";
	return 0;
}