#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
map<long long, int> cnt;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		long long x;
		scanf("%lld", &x);
		++cnt[x];
	}
	long long ans = -0x3f3f3f3f3f3f3f3f;
	int l = 0, n = 0;
	for (pair<long long, int> i : cnt) {
		a[l++] = i.first;
		++n;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		long long sum = cnt[a[i]], need = m, j = n - 1;
		while (a[j] >= a[i]) {
			--j;
		}
		for (; j >= 0 && need; --j) {
			long long c = cnt[a[j]];
			while (c && need) {
				if (need >= a[i] - a[j]) {
					--c;
					need -= a[i] - a[j];
					++sum;
				}
				else {
					break;
				}
			}
		}
		ans = max(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}
