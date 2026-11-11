#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out ", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 0, b = 0, c = 0, d = 0;
	bool flag = true;
	if (c1 == c2) {
		a = 1;
	} else
		flag = false;
	if (flag) {
		if (s1.substr(0, 2) == s2.substr(0, 2)) {
			b = 1;
		} else
			flag = false;
	}
	if (flag) {
		if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
			if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
				c = 1;
				if (s1[2] == 'A') {
					if (s2[2] == 'B')
						d = 1;
				} else if (s1[2] == 'B') {
					if (s2[2] == 'A' || s2[2] == 'C')
						d = 1;
				} else if (s1[2] == 'C') {
					if (s2[2] == 'B')
						d = 1;
				}
			}
		} else if (s1[2] == 'D' || s1[2] == 'F') {
			if (s2[2] == 'D' || s2[2] == 'F') {
				c = 1;
				if ((s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F')) {
					d = 1;
				}
			}
		}
	}

	cout << a << b << c << d;
	return 0;
}
