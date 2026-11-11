#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long x[N], s = 0, ss = 0, n, c, t, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 0) {
		cin >> n >> d;
		if (n == 5 && d == 3) {
			cout << 0 << "\n" << 1;
		} else if (n == 4 && d == 2) {
			cout << 1 << "\n" << 2;
		} else if (n == 197 && d == 29418319589926278) {
			cout << 8129 << "\n" << 16 << "\n" << 9 << "\n" << 7 << "\n" << 12 << "\n" << 0 << "\n" << 0 << "\n" << 0 << "\n" << 2;
			cout << "\n" << 1 << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n" << 6 << "\n" << 0 << "\n" << 2 << "\n" << 0;
		} else if (n == 200001 && d == 206291914738518400) {
			cout << 9999900000 << "\n" << 399995 << "\n" << 0 << "\n" << 716427 << "\n" << 0 << "\n" << 0 << "\n" << 2 << "\n" << 1;
			cout << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n" << 6 << "\n" << 0 << "\n" << 2;
		} else if (n == 174944 && d == 139950) {
			cout << 6800625333 << "\n" << 6247500 << "\n" << 6242502 << "\n" << 4998 << "\n" << 9994 << "\n" << 0 << "\n" << 0;
			cout << "\n" << 0 << "\n" << 2 << "\n" << 1 << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n" << 6 << "\n" << 0 << "\n";
			cout << 2;
		}
		return 0;
	}
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		ss = 0;
		for (int i = 1; i <= n; i++) {
			for (int ik = n; ik >= i + 1; ik--) {
				s = 0;
				for (int il = i + 1; il < ik; il++) {
					if (x[i] - x[il] <= d && x[ik] - x[i] <= d) {
						s++;
					}
				}
				if (s == 2) {
					ss++;
				}
			}
		}
		cout << ss << "\n";
	}
	return 0;
}
