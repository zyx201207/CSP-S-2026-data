#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans1, ans2, ans3, ans4;
	if (c1 == c2) {
		ans1 = 1;
		int a, b;
		a = s1[0] - '0' + s1[1] - '0';
		b = s2[0] - '0' + s2[1] - '0';

		if (a == b) {
			ans2 = 1;
			char x, y;
			x = s1[2];
			y = s2[2];

			if ((x <= 'C' && y <= 'C') || (x > 'C' && y > 'C')) {
				ans3 = 1;

				if (x + 1 == y || y + 1 == x) {
					ans4 = 1;
				}

				else {
					ans4 = 0;
				}
			}

			else {
				ans3 = 0;
				ans4 = 0;
			}
		}

		else {
			ans2 = 0;
			ans3 = 0;
			ans4 = 0;
		}
	}

	else {
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		ans4 = 0;
	}

	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}