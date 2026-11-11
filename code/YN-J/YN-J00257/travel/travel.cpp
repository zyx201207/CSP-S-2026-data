#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else
		cout << 1;
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "000";
		return 0;
	} else
		cout << 1;
	bool ok1 = 1, ok2 = 1;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
		ok1 = 1;
	} else
		ok1 = 0;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
		ok2 = 1;
	} else
		ok2 = 0;
	if (ok1 == ok2) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}
