#include <bits/stdc++.h>
using namespace std;
bool flag[4];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	long long c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 = c2) {
		flag[1] = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			flag[2] = 1;
			if (((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) || ((s1[2] == 'A' || s1[2] == 'B'
			        || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))) {
				flag[3] = 1;
				if ((s1[2] - s2[2] == 1) || (s2[2] - s1[2] == 1)) {
					flag[4] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (flag[i]) {
			cout << "1";
		} else
			cout << "0";
	}

	return 0;
}