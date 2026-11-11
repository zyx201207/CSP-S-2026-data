#include <bits/stdc++.h>
using namespace std;

struct abc {
	long long sum;
	char x;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	long long z = 0;
	cin >> n;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i].sum >> a[i].x;
	}

	for (long long l = 1, r = n; l <= n && r >= 1 && l <= r;) {

		if (a[l].sum == 0) {
			l++;
		}

		if (a[r].sum == 0) {
			r--;
		}

		if (a[l].x == a[r].x) {
			if (a[l].sum > a[r].sum) {
				a[l].sum -= a[r].sum;
				r--;
			} else {
				a[r].sum -= a[l].sum;
				l++;
			}
		} else {
			if (a[l].sum > a[r].sum) {
				a[l].sum -= a[r].sum;
				z += a[r].sum;
				r--;
			} else {
				a[r].sum -= a[l].sum;
				z += a[l].sum;
				l++;
			}
		}
	}

	cout << z;
	return 0;
}
