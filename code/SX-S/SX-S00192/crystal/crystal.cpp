#include <bits/stdc++.h>
using namespace std;

long long a[500005], b[500005];

long long  n, m, l, r, mid, s, ans = 0;

long long fen(long long mi) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = a[i];
		if (b[i] < mi) {
			sum += (mi - b[i]);
			b[i] = mi;
		}
	}
	return sum;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	r = a[n];
	l = a[1];
	while (l <= r) {
		mid = (l + r) / 2;
		s = fen(mid);
		if (s > m)
			r = mid - 1;
		else
			l = mid + 1;
	}
	for (int i = 1; i <= n; i++)
		if (b[i] == mid)
			ans += 1;
	cout << ans;
	return 0;
}
