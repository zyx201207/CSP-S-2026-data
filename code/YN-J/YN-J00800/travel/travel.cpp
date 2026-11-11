#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, aa, ba;
	char s, sa;
	cin >> a >> aa >> s >> b >> ba >> sa;
	if (a != b) {
		cout << "0000";
		return 0;
	} else {
		cout << 1;
		if (aa != ba) {
			cout << "000";
			return 0;
		} else {
			cout << 1;
			if (s == 'A' || s == 'B' || s == 'C') {
				if (sa == 'D' || sa == 'F') {
					cout << "00";
					return 0;
				} else if (abs((int)sa - s) != 1) {
					cout << 10;
					return 0;
				} else {
					cout << 11;
					return 0;
				}
			} else if (s == 'D' || s == 'F') {
				if (sa == 'A' || sa == 'B' || sa == 'C') {
					cout << "00";
					return 0;
				} else {
					cout << 11;
					return 0;
				}
			}
		}
	}
	return 0;
}