#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
int cmp[10];

int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	cmp[1] = 1;
	for (int i = 0; i < 2; i++) {
		if (c1[i] != c2[i]) {
			cmp[1] = 0;
		}
	}
	if (cmp[1]) {
		cmp[2] = 1;
		for (int i = 0; i < 2; i++) {
			if (s1[i] != s2[i]) {
				cmp[2] = 0;
			}
		}
		if (cmp[2]) {
			if (s1[2] >= 'A' && s1[2] <= 'C') {
				if (s2[2] >= 'A' && s2[2] <= 'C') {
					cmp[3] = 1;
					if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) {
						cmp[4] = 1;
					}
				}
			}
			if (s1[2] >= 'D' && s1[2] <= 'E') {
				if (s2[2] >= 'D' && s2[2] <= 'E') {
					cmp[3] = 1;
					cmp[4] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout << cmp[i];
	}
	return 0;
}