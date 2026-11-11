#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, z, x;
	cin >> c1 >> s1 >> c2 >> s2;
	bool q = 0, w = 0, e = 0, r = 0;
	if (c1 == c2) {
		q = 1;
		for (int i = 0; i <= (int)s1.size(); i++) {
			if (s1[i] >= '0' && s1[i] <= '9') {
				z += s1[i];
			}
		}
		for (int i = 0; i <= (int)s2.size(); i++) {
			if (s2[i] >= '0' && s2[i] <= '9') {
				x += s2[i];
			}
		}
		if (x == z) {
			w = 1;
			if (s1.back() <= 'C' && s2.back() <= 'C') {
				e = 1;
				if (s1.back() + 1 == s2.back()) {
					r = 1;
				}
				if (s1.back() - 1 == s2.back()) {
					r = 1;
				}
			}
			if (s1.back() >= 'D' && s2.back() >= 'D') {
				e = 1;
				r = 1;
			}
		}

	}

	cout << q << w << e << r;
	return 0;
}