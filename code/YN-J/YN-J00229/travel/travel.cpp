#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, v = "0000";
int r1, r2, x1, x2, r3, x3;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < c1.size(); i++)
		r1 = r1 * 10 + c1[i] - '0', x1 = x1 * 10 + c2[i] - '0';
	for (int i = 0; i < s1.size(); i++) {
		if (i == s1.size() - 1)
			r3 = int(s1[i]) - 64, x3 = int(s2[i]) - 64;
		else
			r2 = r2 * 10 + s1[i] - '0', x2 = x2 * 10 + s2[i] - '0';

	}
	r3 = min(r3, 5), x3 = min(x3, 5);
	if (r1 == x1) {
		v[0] = '1';
		if (r2 == x2) {
			v[1] = '1';
			if ((r3 <= 3 && x3 <= 3) || (r3 > 3 && x3 > 3)) {
				v[2] = '1';
				if (abs(r3 - x3) == 1)
					v[3] = '1';
			}
		}
	}
	cout << v << '\n';
	return 0;
}