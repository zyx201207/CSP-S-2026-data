#include<bits/stdc++.h>
using namespace std;

int n, ans = 1;
long long m, a[500001], s[500001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int k = 1; k <= n; k++) {
		scanf("%lld", &a[k]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		s[i + 1] = a[i + 1] - a[i];
	for (int i = 1; i < n; i++) {
		int f = s[i + 1] * i * 1LL;
		if (m >= f) {
			m -= f;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
