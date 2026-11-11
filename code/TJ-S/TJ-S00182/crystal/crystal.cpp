#include <bits/stdc++.h>
#define i64 long long
#define rep(i, l, r) for (i64 i = l; i <= r; ++i)
#define per(i, r, l) for (i64 i = r; i >= l; --i)
using namespace std;
const i64 N = 5e5 + 5;
i64 n, l, r, m, a[N];
bool check(i64 mid) {
	i64 cnt = 0;
	rep(i, 1, mid - 1) cnt += a[i]; 
	rep(i, mid, n) {
		cnt -= a[i - mid];
		cnt += a[i];
		if (a[i] * mid - cnt <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	l = 1, r = n;
	while (l < r) {
		i64 mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}

