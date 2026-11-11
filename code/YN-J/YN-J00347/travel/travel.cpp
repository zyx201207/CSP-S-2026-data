#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string x, n, y, m;
	cin >> x >> n >> y >> m;

	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

	for (int i = 1; i <= 18; i ++) {

		for (int j = 1; j <= 5; j ++) {

			if (x == y) {
				ans1 = 1;

				if (n[1] == m[1] || n[2] == m[2]) {
					ans2 = 1;

					if ((n[3] == 'A' || n[3] == 'B' || n[3] == 'C') == (m[3] == 'A' || m[3] == 'B' || m[3] == 'C')) {
						ans3 = 1;
					}

					if ((n[3] == 'D' || n[3] == 'F') == (m[3] == 'D' || m[3] == 'F')) {
						ans3 = 1;
					}
				}
			}
		}
	}

	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}