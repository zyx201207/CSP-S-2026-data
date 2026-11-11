#include <bits/stdc++.h>
using namespace std;
long long n, m, res = -1;
const int N = 2e5 + 10;
long long a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);

	for (long long i = n; i > 0; i--) {
		long long num = a[i];
		for (long long j = i; j > i - m; j--) {
			num = num & a[j];
		}
		res = max(res, num);
	}
	printf("%lld", res);
	return 0;
}
