#include <bits/stdc++.h>

typedef long long ll;

const int N = 5e5 + 5;

int n;
ll m;
ll a[N];
int cnt = 1, sum = 1, num = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i + 1]) {
			cnt++;
			sum += cnt;
		}
	}
	int j = n / 2 + n % 2;
	for (int i = 1; i <= n; ++i) {
		if (m > 0) {
			a[j - 1] += a[j] - a[j - 1];
			m -= a[j] - a[j - 1];
			cnt += 2;
		}
	}
	std::sort(a + 1, a + 1 + n);
	for (int k = 1; k <= j - 1; ++k) {
		num = a[j - 1] - a[k];
		int tot = (a[j + 1] - a[j]) * cnt;
		if (num < tot && num <= m && tot <= m) cnt++;
		cnt = sum + 1;
	}
	printf("%d\n", cnt + 1);
	
	return 0;
}