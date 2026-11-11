#include <bits/stdc++.h>

using namespace std;

long long n, m, a[500005], l, ma, r, id, sum, num, b[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	r = 1, l = 1;
	num = a[1];
	while (r <= n && l <= r) {
		if ((r - l + 1) * a[r] - (b[r] - b[l - 1]) <= m)
			r++;
		else
			l++;
		ma = max(ma, r - l);
	}
	cout << ma;
	return 0;
}
