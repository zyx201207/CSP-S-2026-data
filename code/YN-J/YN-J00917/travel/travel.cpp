// Yang Mofei
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000" << endl;
		return 0;
	}
	cout << 1;

	char l1 = s1.back();
	char l2 = s2.back();

	s1.pop_back();
	s2.pop_back();

	if (s1 != s2) {
		cout << "000" << endl;
		return 0;
	}
	cout << 1;

	if ((l1 <= 'C' && l2 <= 'C') || (l1 >= 'D' && l2 >= 'D')) {
		cout << 1;
		if ((int)abs(l1 - l2) == 1 || (min(l1, l2) == 'D' &&
		                               max(l1, l2) == 'F')) {
			cout << 1;
		} else {
			cout << 0;
			return 0;
		}
	} else {
		cout << "00";
		return 0;
	}

	return 0;
}