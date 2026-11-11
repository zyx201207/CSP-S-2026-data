#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool tcx = 0, typ = 0, tyc = 0, xl = 0;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		tcx = 1;
		if (s1[0] == s2[0] and s1[1] == s2[1]) {
			typ = 1;
			if (s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C' and s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C' or s1[2] == 'D'
			        or s1[2] == 'F' and s2[2] == 'D' or s2[2] == 'F' ) {
				tyc = 1;
				if (s1[2] == 'D' or s1[2] == 'F' and s2[2] == 'D' or s2[2] == 'F' and s1[0] == s2[0] and s1[1] == s2[1]) {
					xl = 1;
				} else if (s1[2] == 'A' or s1[2] == 'B' or s1[2] == 'C' and s2[2] == 'A' or s2[2] == 'B' or s2[2] == 'C'
				           and s1[0] == s2[0] and s1[1] == s2[1]) {
					if (s1[2] == s2[2] - 1 or s1[2] - 1 == s2[2] and s1[0] == s2[0] and s1[1] == s2[1]) {
						xl = 1;
					}
				}
			}
		}
	}
	cout << tcx << typ << tyc << xl;
}