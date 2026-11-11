#include <bits/stdc++.h>
using namespace std;
long long n, m, mid, ans, a[114514 * 5];
bool b = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int x = (a[1] + a[n]) / n;
	for (int i = 1; i <= n; i++) {
		if (a[i] > x) {
			mid = i;
			break;
		}
	}
	for (int i = mid; i >= 1; i--) {
		if (a[mid] - a[i] <= m) {
			m -= (a[mid] - a[i]);
			ans++;
		} else {
			b = 0;
			break;
		}
	}
	if (b) {
		while (m >= (a[mid + 1] - a[mid] ) * mid && mid < n) {
			m -= (a[mid + 1] - a[mid]) * mid;
			ans++;
			mid++;
		}
	}
	printf("%lld", ans);
	return 0;
}