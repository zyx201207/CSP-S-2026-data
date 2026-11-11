#include<bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 7;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, t, p;
	cin >> c >> s >> t >> p;
	if (c != t) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
	}
	if (s[0] == p[0] && s[1] == p[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (s[2] >= 'D' && p[2] >= 'D') {
		cout << "1";
	} else if (s[2] < 'D' && p[2] < 'D') {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (s[2] - p[2] == 1 || p[2] - s[2] == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}
