#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
bool flag = 1;

bool check(char n, char m) {
	if (max(n, m) <= 'C') {
		if (abs(n - m) == 1 && flag) {
			return 1;
		} else {
			return 0;
		}
	} else if (max(n, m) == 'F' && min(n, m) == 'D' && flag) {
		return 1;
	} else {
		return 0;
	}
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == c3) {
		cout << 1;
	} else {
		flag = 0;
		cout << 0;
	}
	if (c2[0] == c4[0] && c2[1] == c4[1] && flag) {
		cout << 1;
	} else {
		flag = 0;
		cout << 0;
	}
	if (max(c2[2], c4[2]) == 'F' && min(c2[2], c4[2]) == 'D' && flag) {
		cout << 1;
	} else if (max(c2[2], c4[2]) <= 'C' && flag) {
		cout << 1;
	} else {
		flag = 0;
		cout << 0;
	}
	if (check(c2[2], c4[2])) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	//travel
	return 0;
}