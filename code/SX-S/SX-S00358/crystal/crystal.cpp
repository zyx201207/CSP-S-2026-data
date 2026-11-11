#include <bits/stdc++.h>
using namespace std;
long long n, m, mi, a[500010], ans = 1, ansl = 1, cha, k = 1;
bool isa = true, isb = true;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &mi);
	m = mi;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i == 2)
			cha = a[i] - a[i - 1];
		if (a[i] != i)
			isa = false;
		if (a[i] - a[i - 1] != cha && i > 2)
			isb = false;
	}
	if (isa == true) {
		for (int i = 2; i <= n; i++) {
			if (m >= (i - 1)) {
				m -= (i - 1);
				ans++;
			} else
				break;
		}
		printf("%lld\n", ans);
		return 0;
	} else if (isb == true) {
		for (int i = 2; i <= n; i++) {
			if (m >= (i - 1) * cha) {
				m -= (i - 1) * cha;
				ans++;
			} else
				break;
		}
		printf("%lld\n", ans);
		return 0;
	}
	sort(a + 1, a + 1 + n, greater<long long>());
	for (int i = 2; i <= n; i++) {
		while (m < (a[k] - a[i]) && k < i) {
//			for (int j = k + 1; j < i; j++) {
//				m += (a[k] - a[k + 1]);
//			}
			m += (a[k] - a[k + 1]) * (i - k - 1);
			ans--;
			k++;
		}
		if (m < (a[k] - a[i])) {
			k = i;
			ans = 1;
			m = mi;
		} else {
			m -= (a[k] - a[i]);
			ans++;
		}
		ansl = max(ansl, ans);
	}
	printf("%lld\n", ansl);
	return 0;
}