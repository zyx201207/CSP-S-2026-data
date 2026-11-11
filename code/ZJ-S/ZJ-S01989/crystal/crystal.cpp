#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005], qz[500005];
int n, res;
long long m;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		qz[i] = qz[i - 1] + a[i];
	}
	res = 1;
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (r + l) >> 1;
			long long gzy1 = 1ll * (i - mid + 1) * a[i];
			long long gzy2 = qz[i] - qz[mid - 1];
			if (gzy1 - gzy2 <= m) {
				r = mid;
				res = max(res, i - mid + 1);
			} else {
				l = mid + 1;
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}