#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
long long m, a[500002], c[500002];

int f(int l) {
	int left = l, right = n, r;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long x = c[mid] - (a[mid] - a[mid - 1]) * (l - 1) + a[l - 1];
		if (x > m)
			right = mid - 1;
		else {
			left = mid + 1;
			r = mid;
		}
	}
	return (r - l + 1);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}
	for (int l = 1; l <= n; l++) {
		ans = max(ans, f(l));
	}
	cout << ans;
	return 0;
}//T1