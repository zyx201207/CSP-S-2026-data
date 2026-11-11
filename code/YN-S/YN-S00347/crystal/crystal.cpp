#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans;
long long m;
long long a[N], sum[N];

bool pd(int cd) {
	for (int i = cd; i <= n; i++) {
		long long tmp1 = 1ll * a[i] * cd;
		long long tmp2 = sum[i] - sum[i - cd];
		if ( (tmp1 - tmp2) <= m) {
			return 1;
		}

	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int L = 1, R = n, mid = R;
	while (L <= R) {
		if (pd(mid) == 1) {
			L = mid + 1, ans = mid;
		} else {
			R = mid - 1;
		}
		mid = (L + R) / 2;
	}
	cout << ans;
	return 0;
}