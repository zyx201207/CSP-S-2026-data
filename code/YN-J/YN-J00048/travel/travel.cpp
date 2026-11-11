#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	int ans = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		ans += 1000;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			ans += 100;
			if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
				ans += 10;
				if ((s1[2] - s2[2] == 1) || (s1[2] - s2[2] == -1))
					ans += 1;
			} else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
				ans += 10;
				if ((s1[2] - s2[2] == 2) || (s1[2] - s2[2] == -2))
					ans += 1;
			}
		}
		cout << ans;
	} else
		cout << "0000";
	return 0;
}