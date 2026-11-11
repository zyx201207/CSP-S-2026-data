#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans[4] = {0};
	for (int j = 1; j <= 1; j++) {
		if (c1 == c2) {
			ans[0] = 1;
		} else {
			break;
		}
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans[1] = 1;
		} else {
			break;
		}
		char z1 = s1[2];
		char z2 = s2[2];
		if (z1 == 'D' && z2 == 'F' || z1 == 'F' && z2 == 'D') {
			ans[2] = 1;
			ans[3] = 1;
		} else if (z1 == 'A' && z2 == 'B' || z1 == 'A' && z2 == 'C' || z1 == 'B' && z2 == 'A' || z1 == 'B' && z2 == 'C'
		           || z1 == 'C' && z2 == 'A' || z1 == 'C' && z2 == 'B') {
			ans[2] = 1;
		} else {
			break;
		}
		if (z1 == 'A' && z2 == 'B' || z1 == 'B' && z2 == 'A' || z1 == 'B' && z2 == 'C' || z1 == 'C' && z2 == 'B') {
			ans[3] = 1;
		}
	}
	for (int i = 0; i <= 3; i++) {
		cout << ans[i];
	}
	return 0;
}