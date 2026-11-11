#include <bits/stdc++.h>
#define i64 long long
#define i32 int
#define rep(i, l, r) for (i64 i = l; i <= r; ++i)
#define per(i, r, l) for (i64 i = r; i >= l; --i)
using namespace std;
const i64 N = 2e5 + 5;
i64 n, a[N], ans;
char c[N];
i32 main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i] >> c[i];
	i64 i = 1, j = n;
	while (i < j) {
		i64 tmp = min(a[i], a[j]);
		if (c[i] != c[j]) ans += tmp;
		a[i] -= tmp;
		a[j] -= tmp;
		if (!a[i]) ++i;
		if (!a[j]) --j;
	}
	cout << ans << '\n';
	return 0;
}


