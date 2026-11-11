#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
long long a[N], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf(" %lld", &a[i]);
	sort(a + 1, a + 1 + n);
	int j = n - 1, i = 1;
	ans = a[n];
	long long mx = a[n];
	for (; j > n - m; j--) {
		if (a[n] != a[j])
			break;
		i++;
	}
	for (; i < m;) {
		int na = ans;
		for (int k = 1; k < na; k *= 2) {
			int p = upper_bound(a + 1, a + 1 + j, mx - k) - a - 1;
			if (a[p] == mx - k) {
				j = p, i++, ans &= a[p], mx = ans;
				break;
			}
		}
		if (na == ans) {
			int p = lower_bound(a + 1, a + 1 + j, mx) - a - 1;
			ans &= a[p], i++, j = p, mx = ans;
		}
	}
	printf("%lld", ans);
	return 0;
}