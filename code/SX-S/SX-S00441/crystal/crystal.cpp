#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, m, a[N], ans, su, e, l, b;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);

	sort(a + 1, a + 1 + n);
	l = 1;
	e = m;
	su = 1;
	ans = 1;
	for (int i = 2; i <= n; i++) {
		b = (a[i] - a[i - 1]) * su;
		if (e >= b) {
			e -= b;
			su++;
			ans = max(ans, su);
		} else {
			for (int j = l; j < i; j++) {
				e += a[i - 1] - a[j];
				su--;
				l++;
				b = (a[i] - a[i - 1]) * su;
				if (e >= b) {
					e -= b;
					su++;
					ans = max(ans, su);
					break;
				}
			}
		}
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
