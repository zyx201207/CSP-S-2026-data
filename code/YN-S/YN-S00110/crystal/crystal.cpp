#include <bits/stdc++.h>
using namespace std;
int n, l, r, mid;
long long a[500006], s[500006], zh[500006], m;

bool check() {
	mid = (r + l) / 2;
	if (zh[mid] <= m)
		return true;
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		zh[i] = (i - 1) * a[i] - s[i - 1];
	}
	zh[n + 1] = 1e18 + 11;
	l = 1;
	r = n + 1;
	while (l < r) {
		if (check())
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << l - 1;
	return 0;
}