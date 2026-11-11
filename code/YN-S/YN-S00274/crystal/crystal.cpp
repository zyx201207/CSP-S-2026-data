#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
long long q[500005];
long long qzh[500005];
long long hzh[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		q[i - 1] = a[i] - a[i - 1];
	}
	for (int i = n - 1; i >= 1; i--) {
		qzh[i] = qzh[i + 1] + q[i];
	}
	for (int i = n - 1; i >= 1; i--) {
		hzh[i] = hzh[i + 1] + qzh[i];
	}
	long long anss = -1e18;
	for (int i = n; i >= 2; i--) {
		long long res1 = qzh[i];
		long long res2 = hzh[i];
		int l = 1, r = i - 1, mid;
		while (l < r) {
			mid = (l + r ) / 2;
			if (m >= 1ll * hzh[mid] - res2 - (1ll * (i - mid)*res1)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		anss = max(anss, 1ll * 1 + (i - mid));
	}
	cout << anss;
	return 0;
}