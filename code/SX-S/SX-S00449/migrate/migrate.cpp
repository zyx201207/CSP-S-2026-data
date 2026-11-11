#include <bits/stdc++.h>
using namespace std;
int c, t, n, sum;
long long a[200005], d, ca;

int mi(long long caa, long long ai, long long bi, long long dd) {
	int tl = dd / caa, l = bi - ai + 1;
	if (l == tl * 2) {
		return 1;
	} else {
		return 0;
	}

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int x = 1; x <= t; x++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ca = a[2] - a[1];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 3; j <= n; j++) {
				if (mi(ca, i, j, d)) {
					sum++;
				}
			}
		}
		cout << sum << "\n";
		sum = 0;
	}
	return 0;
}