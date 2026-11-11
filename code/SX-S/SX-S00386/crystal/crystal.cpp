#include <bits/stdc++.h>
using namespace std;
long long n, m, o;
long long a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	long long l = 1, r = n;
	while (l <= r) {
		long long u = 0, w = 1;
		long long mid = (r - l) / 2 + l;
		long long t = a[mid];
		for (long long i = mid - 1; i >= 1; i--) {
			long long mj = a[i];
			while (mj != t) {
				mj ++;
				u++;
			}
			if (m - u < 0)
				break;
			w++;
		}

		if (w >= o) {
			o = w;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld", o);
	return 0;
}
