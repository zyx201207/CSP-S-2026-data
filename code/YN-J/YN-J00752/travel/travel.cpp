#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string c1, s1, c2, s2;

signed main() {
	IOS
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if (!((s1[2] <= 'C') ^ (s2[2] <= 'C'))) {
				cout << 1;
				if (abs(s1[2] - s2[2]) == 1)
					cout << 1;
				else
					cout << 0;
			} else
				cout << 0 << 0;
		} else
			cout << 0 << 0 << 0;
	} else
		cout << 0 << 0 << 0 << 0;

	return 0;
}
//02 02B 02 01A