#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int cx = 0, yp = 0, yc = 0, xl = 0;

	if (c1 == c2) {
		cx = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			yp = 1;
			if (int(s1[2]) < int("D")) {
				if (int(s2[2]) < int("D")) {
					yc = 1;
					if (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1)
						xl = 1;
				}
			} else if (int(s2[2]) > int("C")) {
				yc = 1;
				if (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1)
					xl = 1;
			}
		}
	}
	cout << cx << yp << yc << xl;
	return 0;
}