#include <bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
using std::clog;
std::string c1, s1, c2, s2;
signed main() {
	#ifndef MCH
		freopen("travel.in", "r", stdin);
		freopen("travel.out", "w", stdout);
	#endif
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	if (c1 != c2) {
		cout << "000" << endl;
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		if (i == 2) {
			bool f = ((s1[i] <= 'C' && s2[i] <= 'C') || (s1[i] > 'C' && s2[i] > 'C'));
			cout << 1 << (f)
			<< (f && (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) && (s1[2] != 'C' && s2[2] != 'D'));
			break;
		}
		if (s1[i] != s2[i]) {
			cout << "000" << endl;
			return 0;
		}
	}
	cout << endl;
	return 0;
}

