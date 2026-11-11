#include <bits/stdc++.h>
using namespace std;

int a[4];
int main() {
	freopen("treval.in", "r", stdin);
	freopen("treval.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		a[1]++;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			a[2]++;
			if ( (s1[2] <= 'c' && s2[2] <= 'c') || (s1[2] >= 'd' && s2[2] >= 'd')) {
				a[3]++;
				if (int(s1[2] + 1 == s2[2] || int(s1[2]) - 1 == s2[2])) {
					a[4]++;
				}
			}
		}
	}
	if (s1[2] == 'C' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'C') {
		a[3] = 0;
		a[4] = 0;
	}
	for (int i = 1; i <= 4; i++) {
		cout << a[i];
	}
	return 0;
}