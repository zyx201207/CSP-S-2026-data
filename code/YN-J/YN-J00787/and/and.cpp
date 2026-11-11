#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 2e7 + 10;
int a[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int max1 = INT_MIN;
		for (int i = 1; i <= n; i++) {
			max1 = max(max1, a[i]);
		}
		cout << max1;
		return 0;
	}
	if (m == 2) {
		int max1 = INT_MIN;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) {
				if (l == r) {
					continue;
				}
				int js = a[l] & a[r];
				max1 = max(max1, js);
			}
		}
		cout << max1;
		return 0;
	}
	if (m == 3) {
		int max1 = INT_MIN;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) {
				for (int z = 1; z <= n; z++) {
					if (l == r || r == z || l == z) {
						continue;
					}
					int js = a[l] & a[r] & a[z];
					max1 = max(max1, js);
				}

			}
		}
		cout << max1;
		return 0;
	}
	if (m == 4) {
		int max1 = INT_MIN;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) {
				for (int z = 1; z <= n; z++) {
					for (int w = 1; w <= n; w++) {
						if (l == r || r == z || l == z || l == w || r == w) {
							continue;
						}
						int js = a[l] & a[r] & a[z] & a[w];
						max1 = max(max1, js);
					}

				}

			}
		}
		cout << max1;
		return 0;
	}
	if (m == 5) {
		int max1 = INT_MIN;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) {
				for (int z = 1; z <= n; z++) {
					for (int w = 1; w <= n; w++) {
						for (int y = 1; y <= n; y++) {
							if (l == r || r == z || l == z || l == w || r == w || z == w || l == y || r == y
							        || w == y || z == y) {
								continue;
							}
							int js = a[l] & a[r] & a[z] & a[w] & a[y];
							max1 = max(max1, js);
						}
					}

				}

			}
		}
		cout << max1;
		return 0;
	}
	if (m == 6) {
		int max1 = INT_MIN;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) {
				for (int z = 1; z <= n; z++) {
					for (int w = 1; w <= n; w++) {
						for (int y = 1; y <= n; y++) {
							for (int x = 1; x <= n; x++) {
								if (l == r || r == z || l == z || l == w || r == w || z == w || l == y || r == y
								        || w == y || z == y || l == x || r == x || z == x || w == x || y == x) {
									continue;
								}
								int js = a[l] & a[r] & a[z] & a[w] & a[y] & a[x];
								max1 = max(max1, js);
							}

						}
					}

				}

			}
		}
		cout << max1;
		return 0;
	} else {
		sort(a + 1, a + n + 1);
		cout << a[m];
	}
	return 0;
}