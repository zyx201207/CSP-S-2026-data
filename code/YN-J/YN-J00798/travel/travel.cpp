#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string c1, c2;
	char s1, s2;
	int a1, a2;
	cin >> c1 >> a1 >> s1 >> c2 >> a2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << "1";
		if (a1 != a2) {
			cout << "000";
		} else {
			cout << "1";
			if (((s1 == 'A' || s1 == 'B' || s1 == 'C') && (s2 == 'A' || s2 == 'B' || s2 == 'C')))  {
				cout << "1";
				if (s1 == 'A' && s2 == 'B') {
					cout << "1";
				} else if (s1 == 'B' && s2 == 'A') {
					cout << "1";
				} else if (s1 == 'B' && s2 == 'C') {
					cout << "1";
				}  else if (s1 == 'C' && s2 == 'B') {
					cout << "1";
				} else {
					cout << "0";
				}
			} else if ((s1 == 'E' || s1 == 'F') && (s2 == 'E' || s2 == 'F')) {
				cout << "11";
			} else {
				cout << "00";
			}
		}
	}
	return 0;
}