#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	bool a = 0, b = 0, c = 0, d = 0;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		a = 1;


		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			b = 1;
			int n = 0, m = 0;

			if (s1[2] == 'C' || s1[2] == 'A' || s1[2]  == 'B') {
				n = 1;
			} else {
				n = 2;
			}


			if (s2[2] == 'C' || s2[2] == 'A' || s2[2]  == 'B') {
				m = 1;
			} else {
				m = 2;
			}

			if (n == m) {
				c = 1;

				if (s1[2] == s1[2] - 1 || s1[2] == s2[2] - 1)
					d = 1;

				if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
					d = 1;
			}
		}

	}

	cout << a << ' ' << b << ' ' << c << ' ' << d;

	return 0;
}