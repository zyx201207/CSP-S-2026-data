#include <bits/stdc++.h>
using namespace std;

using i32 = int; using i64 = long long;

#define For(i, l, r) for (i32 i = (l); i <= (r); i++)


const i32 N = 1 << 19;
i32 n; i64 m;
i64 a[N];
i64 sum[N];

inline bool check(i32 mid) {
	For (i, mid, n) {
		i64 pp = sum[i] - sum[i - mid];
		if (a[i] * mid - pp <= m) return 1;
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(), cin.tie(), cout.tie();

	cin >> n >> m;

	For (i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);

	For (i, 1, n) sum[i] = sum[i - 1] + a[i];
	
	i32 l = 0, r = n;
	while (l < r) {
		i32 mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';

	return 0;
}