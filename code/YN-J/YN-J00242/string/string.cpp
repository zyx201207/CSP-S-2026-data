#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long  n, a[N], tot, ans;
string c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		tot += a[i];
		a[i] += a[i - 1];
	}
	long long mid = tot / 2 + tot % 2;
	for (int i = 1, j = n; i <= n; i++) {
		long long jl = tot - a[j] + 1, jr = tot - a[j - 1];
		long long il = a[i - 1] + 1, ir = a[i];
		if (c[i] != c[j])
			ans += max(min(ir, jr) - max(il, jl) + 1, (long long)0);
		while (ir >= jr && j >= 1) {
			j--;
			jl = tot - a[j] + 1, jr = tot - a[j - 1];
			if (c[i] != c[j])
				ans += max(min(ir, jr) - max(il, jl) + 1, (long long)0);
		}
	}
	cout << ans / 2;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/