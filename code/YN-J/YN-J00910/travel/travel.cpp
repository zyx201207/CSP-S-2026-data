#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string c1, s1, c2, s2;
char p1, p2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	if (c1 == c2)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < s1.size() - 1; i++) {
		if (s1[i] != s2[i]) {
			cout << "000";
			return 0;
		}
	}
	cout << 1;
	p1 = s1[s1.size() - 1];
	p2 = s2[s2.size() - 1];
	if (p1 == 'A' || p1 == 'B' || p1 == 'C') {
		if (p2 == 'D' || p2 == 'E') {
			cout << "00";
			return 0;
		} else
			cout << 1;
	} else {
		if (p2 == 'D' || p2 == 'F') {
			cout << 1;
		} else {
			cout << "00";
			return 0;
		}
	}
	if (p2 == p1 - 1 || p2 == p1 + 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}