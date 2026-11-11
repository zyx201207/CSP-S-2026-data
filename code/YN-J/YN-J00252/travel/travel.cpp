#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1, c2, s1, s2;
string t1, t2;
string a1, a2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int sum = 0;
	for (int i = 0; i < c1.size(); i++) {
		if (c1[i] == c2[i]) {
			sum++;
		}
	}
	if (sum == 2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	sum = 0;
	for (int i = 0; i < s1.size() - 1; i++) {
		if (s1[i] == s2[i]) {
			sum++;
		}
	}
	if (sum == 2) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	int a1 = s1[s1.size() - 1], a2 = s2[s2.size() - 1];
	if (a1 >= 'A' && a1 <= 'C') {
		if (a2 >= 'A' && a2 <= 'C') {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		if (a2 >= 'A' && a2 <= 'C') {
			cout << 0;
		} else {
			cout << 1;
		}
	}
	if (a1 == 'A' && a2 == 'B') {
		cout << 1;
	} else if (a1 == 'B' && a2 == 'A' || a2 == 'C') {
		cout << 1;
	} else if (a1 == 'C' && a2 == 'B') {
		cout << 1;
	} else if (a1 == 'D' && a2 == 'F') {
		cout << 1;
	} else if (a1 == 'F' && a2 == 'D') {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
