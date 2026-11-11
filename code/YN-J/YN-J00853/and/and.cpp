#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[200001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	long long maxn = 0;
	if (m == 1) {
		cout << 0;
		return 0;
	}

	if (m == n) {
		for (int i = 0; i < n; i++) {
			maxn = max(maxn, a[i] & a[i + 1]);
		}
		cout << maxn;
		return 0;
	}
	sort(a, a + n + 1);
	return 0;
}