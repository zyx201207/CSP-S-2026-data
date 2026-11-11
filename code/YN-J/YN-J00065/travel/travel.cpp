#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1;
string s2;
string t1;
string t2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1;
	cin >> s2;
	cin >> t1;
	cin >> t2;
	if (s1 == t1) {
		cout << 1;
		if (s2[0] == t2[0] && s2[1] == t2[1]) {
			cout << 1;
			if ((s2[2] > 'C' && t2[2] > 'C') || (s2[2] <= 'C' && t2[2] <= 'C')) {
				cout << 1;
				if (s2[2] + 1 == t2[2] || s2[2] - 1 == t2[2]) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}